v = VideoReader('out1.avi');
v2 = VideoWriter('res1.avi','Grayscale AVI');
v2.FrameRate = v.FrameRate;
open(v2);
while(hasFrame(v))
    f = readFrame(v);
    f_resized = imresize(f(:,:,1),0.1);
    writeVideo(v2, f_resized);
end
close(v2);