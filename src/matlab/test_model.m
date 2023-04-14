load imds
load detector
%% Offline
inputSize = [224 224 1];
figure(1)
for i = 1:10
    I = imread(imds.Files{i});
    I = imresize(I,inputSize(1:2));
    [bboxes,scores] = detect(detector,I);
    if ~isempty(bboxes)
        I = insertObjectAnnotation(I,'rectangle',bboxes,scores);
    end
    imshow(I)
    set(gcf, 'units','normalized','outerposition',[0 0 1 1]);
end

%% Real Time
% imaqregister("E:\Program Files (x86)\TIS IMAQ for MATLAB R2013b\x64\TISImaq_R2013_64.dll")
vid = videoinput('tisimaq_r2013_64',1,'Y800 (2592x1944)');
start(vid);
inputSize = [224 224 1];
figure;
for i = 1:100
    frame = getsnapshot(vid);
    frame = imresize(frame,inputSize(1:2));
    [bboxes,scores] = detect(detector,frame);
    [score, idx] = max(scores);
    bbox = bboxes(idx, :);
    annotation = sprintf('%s: (Confidence = %f)', 'Hare', score);
    if ~isempty(bboxes)
        frame = insertObjectAnnotation(frame,'rectangle',bbox,annotation);
    end
    imshow(frame);
    %set(gcf, 'units','normalized','outerposition',[0 0 1 1]);
end
stop(vid);