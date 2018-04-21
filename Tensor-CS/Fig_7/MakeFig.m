
%%
function [] = MakeFig(I0,PSNR,samplingratio)
    %Xref = I0(75:75+99-1,120:120+99-1,:);
    Xref = I0(:,:,1:50);
    maximum = max(Xref(:));
    Xref = Xref/maximum;
    [hcap,hiso] = visualize3D_factor(Xref,.3,[],.1);
    %view(-142, 14)
    view(-126, 4)
    delete(findobj('type','light','parent',gca))
    camlight('headlight')
    set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6)
    axis off
    title(['PSNR=',num2str(PSNR),'dB, ','sampling ratio=',num2str(100*samplingratio),'%'])

    figure
    subplot(2,2,1); imagesc(I0(:,:,15)); title('slice 15')
    subplot(2,2,2); imagesc(I0(:,:,30)); title('slice 30')
    subplot(2,2,3); imagesc(I0(:,:,45)); title('slice 45')
    subplot(2,2,4); imagesc(I0(:,:,60)); title('slice 60')

end
