height = 1944;
width  = 2592;

% vid = VideoReader("../vid/def1.avi");
%
% idx = 1;
% while(vid.hasFrame)
%     fr = vid.readFrame;
%     imwrite(fr, ["img"+idx+".bmp"]);
%     idx = idx + 1;
% end
close all
% v = VideoWriter('newfile.avi','Motion JPEG AVI');
% v.FrameRate = 15;
% open(v)
error = 0;
img = zeros(height,width,'uint8');
for i = 30
    disp(i);
    tic;
    img = im2gray(imread(["img"+i+".bmp"]));
    [imgs, r, r_big] = img_prep(img);
%     imshowpair(img,imgs);
    patch = imgs(r(2)-r_big(2)+1:r(2)-r_big(2)+r(4)+1,1:1+r(3));
    img(r_big(2):r_big(2)+r_big(4),r_big(1):r_big(1)+r_big(3))= img(r_big(2):r_big(2)+r_big(4),r_big(1):r_big(1)+r_big(3))+ cast(255*imgs,'uint8');
    if numel(patch)/nnz(patch) > 250
        frame = insertShape(img,'Rectangle',r,'Color','r','LineWidth',5);
        error = error + 1;
    else
        frame = insertShape(img,'Rectangle',r,'Color','g','LineWidth',5);
    end
    figure;
    imshow(frame);
%     writeVideo(v,frame);
%     waitforbuttonpress();
toc
end
% close(v);
%% FAST
% corners = detectFASTFeatures(imgs2,'ROI',r2,'MinQuality',0.01,'MinContrast',0.01);
% imshow(img); hold on;
% plot(corners);
%% MSER
% regions = detectMSERFeatures(imgs,'ROI',roi,'ThresholdDelta',1,'MaxAreaVariation',0.5);
% figure; imshow(img); hold on;
% plot(regions,'showPixelList',true,'showEllipses',false);
%% HOG
% blockSize = [2 2];
% cellSize = [32 32];
% overlap = [1 1];
% 
% [feat, vis] = extractHOGFeatures(imgs, 'CellSize', cellSize, 'BlockSize', blockSize, 'BlockOverlap', overlap);
% [feat2, vis2] = extractHOGFeatures(imgs2, 'CellSize', cellSize, 'BlockSize', blockSize, 'BlockOverlap', overlap);
% %% Match
% indexPairs = matchFeatures(feat,feat2) ;
% matchedPoints1 = vis(indexPairs(:,1));
% matchedPoints2 = vis2(indexPairs(:,2));
% figure; showMatchedFeatures(img,img2,matchedPoints1,matchedPoints2);
% legend('matched points 1','matched points 2');
%% BRISK
% points = detectBRISKFeatures(imgs,'ROI',r);
% [ft, vp] = extractFeatures(img, points);
%% Show
% imshow(img);
% hold on
% plot(vp.selectStrongest(10));