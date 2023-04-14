[imds,bxds] = objectDetectorTrainingData(gTruth,'SamplingFactor',1);

rng(0)
shuffledIndices = randperm(height(imds.Files));
idx = floor(0.6 * height(imds.Files));

trainingIdx = 1:idx;
validationIdx = idx+1 : idx + 1 + floor(0.1 * length(shuffledIndices) );
testIdx = validationIdx(end)+1 : length(shuffledIndices);

imdsTrain = imageDatastore(imds.Files(shuffledIndices(trainingIdx)));
trainingDataTbl = table(bxds.LabelData(shuffledIndices(trainingIdx),1));
bldsTrain = boxLabelDatastore(trainingDataTbl(:,1));

imdsValidation  = imageDatastore(imds.Files(shuffledIndices(validationIdx)));
validationDataTbl = table(bxds.LabelData(shuffledIndices(validationIdx),1));
bldsValidation  = boxLabelDatastore(validationDataTbl(:,1));

imdsTest  = imageDatastore(imds.Files(shuffledIndices(testIdx)));
testDataTbl = table(bxds.LabelData(shuffledIndices(testIdx),1));
bldsTest = boxLabelDatastore(testDataTbl(:,1));

trainingData = combine(imdsTrain,bldsTrain);
validationData = combine(imdsValidation,bldsValidation);
testData = combine(imdsTest,bldsTest);

%% FASTER R-CNN
data = read(trainingData);
inputSize = [224 224 1];
preprocessedTrainingData = transform(trainingData, @(data)preprocessData(data,inputSize));
numAnchors = 3;
anchorBoxes = estimateAnchorBoxes(trainingData,numAnchors);
featureExtractionNetwork = resnet50('Weights','none');
featureLayer = 'activation_40_relu';
numClasses = 1;
lgraph = fasterRCNNLayers(inputSize,numClasses,anchorBoxes,featureExtractionNetwork,featureLayer);

%% Augment

augmentedTrainingData = transform(trainingData,@augmentData);
augmentedData = cell(4,1);
for k = 1:4
    data = read(augmentedTrainingData);
    augmentedData{k} = insertShape(data{1},'Rectangle',data{2});
    reset(augmentedTrainingData);
end
figure
montage(augmentedData,'BorderSize',10)
%%
validationData = transform(validationData,@(data)preprocessData(data,inputSize));
trainingData = preprocessedTrainingData;

options = trainingOptions('sgdm',...
    'MaxEpochs',10,...
    'MiniBatchSize',2,...
    'InitialLearnRate',1e-3,...
    'CheckpointPath',tempdir,...
    'ValidationData',validationData);
% Train the Faster R-CNN detector.
% * Adjust NegativeOverlapRange and PositiveOverlapRange to ensure
%   that training samples tightly overlap with ground truth.
[detector, info] = trainFasterRCNNObjectDetector(trainingData,lgraph,options, ...
    'FreezeBatchNormalization',false, ...
    'NegativeOverlapRange',[0 0.3], ...
    'PositiveOverlapRange',[0.6 1]);

%% Test
I = imread(imdsTest.Files{1});
I = imresize(I,inputSize(1:2));
[bboxes,scores] = detect(detector,I);

I = insertObjectAnnotation(I,'rectangle',bboxes,scores);
figure
imshow(I)

testData = transform(testData,@(data)preprocessData(data,inputSize));
detectionResults = detect(detector,testData,'MinibatchSize',4);
[ap, recall, precision] = evaluateDetectionPrecision(detectionResults,testData);

figure
plot(recall,precision)
xlabel('Recall')
ylabel('Precision')
grid on
title(sprintf('Average Precision = %.2f', ap))

%% Print test
figure
for i = 1:height(detectionResults)
    I = imread(imdsTest.Files{i});
    I = imresize(I,inputSize(1:2));
    if ~isempty(detectionResults.Boxes{i})
        I = insertObjectAnnotation(I,'rectangle',detectionResults.Boxes{i},detectionResults.Scores{i});
    end
    imshow(I)
    waitforbuttonpress();
end
