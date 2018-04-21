clear all
clc

load results


I = size(I0);

I0 = I0/norm(tensor(I0));

div = 2; 

%%

%Xref = I0(75:75+99-1,120:120+99-1,:);
Xref = IM;
maximum = max(Xref(:));
Xref = Xref/maximum;
[hcap,hiso] = visualize3D_factor(Xref,.3,[],.1);
%view(-142, 14)
view(-126, 4)
delete(findobj('type','light','parent',gca))
camlight('headlight')
set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6)
axis off
title('Original (256x256x100)')

IMmask = Mask;
%Xref = AproxNBOMP(75:75+99-1,120:120+99-1,:);
Xref = IM.*IMmask;
Xref = Xref/max(Xref(:));
%Xref = Xref/maximum;
[hcap,hiso] = visualize3D_factor(Xref,.3,[],.1);
%view(-142, 14)
view(-126, 4)
delete(findobj('type','light','parent',gca))
camlight('headlight')
set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6)
axis off
%title('Available entries (50%)')
title('Available entries (25%)')

%Xref = AproxNBOMP(75:75+99-1,120:120+99-1,:);
Xref = IMrec;
Xref = Xref/max(Xref(:));
%Xref = Xref/maximum;
[hcap,hiso] = visualize3D_factor(Xref,.3,[],.1);
%view(-142, 14)
view(-126, 4)
delete(findobj('type','light','parent',gca))
camlight('headlight')
set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6)
axis off
title(['Reconstruction (PSNR=',num2str(PSNR),'dB)'])
%title('Reconstruction (PSNR=39dB)')

figure
subplot(2,2,1); imshow(IM(:,:,15),[0,6000]); title('slice 15')
subplot(2,2,2); imshow(IM(:,:,30),[0,6000]); title('slice 30')
subplot(2,2,3); imshow(IM(:,:,45),[0,6000]); title('slice 45')
subplot(2,2,4); imshow(IM(:,:,60),[0,6000]); title('slice 60')
colormap('jet');
annotation('textbox',...
    [0.455357142857143 0.932333333333334 0.0420138888888889 0.0476190476190476],...
    'String',{'Original'},...
    'LineStyle','none');

IMmasked = IM.*IMmask;
figure
subplot(2,2,1); imshow(IMmasked(:,:,15),[0,6000]); title('slice 15')
subplot(2,2,2); imshow(IMmasked(:,:,30),[0,6000]); title('slice 30')
subplot(2,2,3); imshow(IMmasked(:,:,45),[0,6000]); title('slice 45')
subplot(2,2,4); imshow(IMmasked(:,:,60),[0,6000]); title('slice 60')
colormap('jet');
annotation('textbox',...
    [0.455357142857143 0.932333333333334 0.0420138888888889 0.0476190476190476],...
    'String',{'Available entries'},...
    'LineStyle','none');

figure
subplot(2,2,1); imshow(IMrec(:,:,15),[0,6000]); title('slice 15')
subplot(2,2,2); imshow(IMrec(:,:,30),[0,6000]); title('slice 30')
subplot(2,2,3); imshow(IMrec(:,:,45),[0,6000]); title('slice 45')
subplot(2,2,4); imshow(IMrec(:,:,60),[0,6000]); title('slice 60')
colormap('jet');
annotation('textbox',...
    [0.455357142857143 0.932333333333334 0.0420138888888889 0.0476190476190476],...
    'String',{'Reconstruction'},...
    'LineStyle','none');

break

