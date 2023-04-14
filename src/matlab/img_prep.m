function [output_image, roi, roi_big] = img_prep(input_image)
    mask = input_image>graythresh(input_image)*255+max(input_image(:))/10;
    maskm = imclose(mask, strel('disk',30,4));
    maskm = imopen(maskm, strel('disk',30,4));
    maskf = bwareafilt(maskm,1);
    maskfin = mask.*maskf;
   
    
    stripe = maskf - maskfin;
    [r, c] = find(stripe == 1);
    stripe_center = round([mean(r), mean(c)]);
    
    bbox = regionprops(maskfin,'BoundingBox');
    roi_big = round(bbox.BoundingBox);
    roi_small = [roi_big(1) stripe_center(1)+round(roi_big(4)/16) round(roi_big(3)/2) round(roi_big(4)/8)];
    
    imgs = input_image(roi_big(2):roi_big(2)+roi_big(4),roi_big(1):roi_big(1)+roi_big(3));
    maskfins = maskfin(roi_big(2):roi_big(2)+roi_big(4),roi_big(1):roi_big(1)+roi_big(3));
    masks = imerode(maskfins,strel('disk',50,4));
    imgs(~maskfins) = 0;
    imgs = imgaussfilt(imgs,5); 
    imgh = adapthisteq(imgs,'NumTiles',[8 8],'ClipLimit',0.01);   
%     imgh(~maskfin) = 0;
    imge = edge(imgh,'Canny',[0.01 0.1],5);
    imge = imge.*masks;
    imge = imdilate(imge,strel('disk',4,4));
     
    roi = roi_small;
    output_image = imge;
     
%      imshowpair(input_image,imgs,'montage');
%      figure;
%      imshowpair(imgh,imge,'montage');
%      imshow([mask,maskm]);
%      figure
%      imshow([maskf,maskfin]);