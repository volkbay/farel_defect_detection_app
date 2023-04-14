v = VideoReader('res.avi');
f = read(v,1);
h = fspecial('log',3,0.9);
imshowpair(f,imfilter(f,h),'montage');