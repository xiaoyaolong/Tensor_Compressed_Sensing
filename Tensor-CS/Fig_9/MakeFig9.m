%%
clear
clc

load 'resultsBarbara20perc.mat'

IMmasked = IM.*Mask;

figure
subplot(2,3,1);
imshow(IM,[0,255])
title('Original (512 x 512) image')

subplot(2,3,2);
imshow(IMmasked,[0,255])
title('Available pixels (20%)')

subplot(2,3,3);
imshow(IMrec,[0,255])
title('Reconstruction (PSNR=27.61dB)')

%% zoom
subplot(2,3,4);
imshow(IM(51:200,301:450),[0,255])
title('(150 x 150) Zoom')

subplot(2,3,5);
imshow(IMmasked(51:200,301:450),[0,255])
title('(150 x 150) Zoom')

subplot(2,3,6);
imshow(IMrec(51:200,301:450),[0,255])
title('(150 x 150) Zoom')