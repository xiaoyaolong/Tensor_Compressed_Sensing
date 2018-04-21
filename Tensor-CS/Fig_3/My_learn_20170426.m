clc;
clear;

%% Load 3D MRI data-set
load ../Datasets/3DBrain/brain_uint8.mat;
Y = double(im_uint8(1:256,1:256,1:64));
I = size(Y);

%% Show Original
% [~,hiso] = visualize3D_factor(Y/(max(Y(:))),.3,[],.1);
% view(-126, 4);
% delete(findobj('type','light','parent',gca));
% camlight('headlight');
% set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6);
% title('Original');
% axis off;

%% Daubechies case
% load DauBasis.mat
type = 'Daubechies';
L = 1;
par = 10;
[D0] = create_WT(I,1,[],type,L,par);
D0 = tran_cell(D0);
% D0{1} = dctmtx(I(1));D0{2} = dctmtx(I(2));D0{3} = dctmtx(I(3));
X = ttm(tensor(Y),{D0{1}',D0{2}',D0{3}'},[1,2,3]); % Compute core tensor

%% Compute sparse core tensor
x = double(X(:));
[C,ind] = sort(abs(x),'descend');

%% image Y25 (keep 25% largest absolute coefficients)
range = 1:round(0.25*prod(I));
spx = zeros(prod(I),1);
spx(ind(range)) = x(ind(range));
X25 = reshape(spx,I);

Y25 = ttm(tensor(X25),D0,[1,2,3]);

Xref = Y25;
maximum = max(Xref(:));
Xref = Xref/maximum;
[hcap,hiso] = visualize3D_factor(Xref,.3,[],.1);
view(-126, 4)
delete(findobj('type','light','parent',gca))
camlight('headlight')
set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6)
axis off

PSNR25 = 20*log10(max(Y(:))/sqrt(mean((Y(:) - Y25(:)).^2)));
title(['Reconstructed with 25% of coefficients (PSNR=',num2str(PSNR25),'dB)']);
disp(['Kept Coefficients=',num2str(25),'%  , PSNR=',num2str(PSNR25),'dB'])

%% image Y05 (keep 5% largest absolute coefficients)
range = 1:round(0.05*prod(I));
spx = zeros(prod(I),1);
spx(ind(range)) = x(ind(range));
X05 = reshape(spx,I);

Y05 = ttm(tensor(X05),D0,[1,2,3]);

Xref = Y05;
maximum = max(Xref(:));
Xref = Xref/maximum;
[hcap,hiso] = visualize3D_factor(Xref,.3,[],.1);
%view(-142, 14)
view(-126, 4)
delete(findobj('type','light','parent',gca))
camlight('headlight')
set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6)
axis off

PSNR05 = 20*log10(max(Y(:))/sqrt(mean((Y(:) - Y05(:)).^2)));
title(['Reconstructed with 5% of coefficients (PSNR=',num2str(PSNR05),'dB)']);
disp(['Kept Coefficients=',num2str(5),'%  , PSNR=',num2str(PSNR05),'dB'])

%% image Y01 (keep 1% largest absolute coefficients)
range = 1:round(0.01*prod(I));
spx = zeros(prod(I),1);
spx(ind(range)) = x(ind(range));
X01 = reshape(spx,I);

Y01 = ttm(tensor(X01),D0,[1,2,3]);

Xref = Y01;
maximum = max(Xref(:));
Xref = Xref/maximum;
[hcap,hiso] = visualize3D_factor(Xref,.3,[],.1);
%view(-142, 14)
view(-126, 4)
delete(findobj('type','light','parent',gca))
camlight('headlight')
set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6)

axis off

PSNR01 = 20*log10(max(Y(:))/sqrt(mean((Y(:) - Y01(:)).^2)));
title(['Reconstructed with 1% of coefficients (PSNR=',num2str(PSNR01),'dB)']);
disp(['Kept Coefficients=',num2str(1),'%  , PSNR=',num2str(PSNR01),'dB'])

%% Generate plot PSNR vs percentage of keep coefficients
percrange = 0.001:0.001:0.25;
PSNR_Dau = zeros(1,length(percrange));

X_Dau = ttm(tensor(Y),{D0{1}',D0{2}',D0{3}'},[1,2,3]);
x_Dau = double(X_Dau(:));
[C,ind_Dau] = sort(abs(x_Dau),'descend');

n = 1;
for p = percrange
    range = 1:round(p*prod(I));
    
    spx_Dau = zeros(prod(I),1);
    spx_Dau(ind_Dau(range)) = x_Dau(ind_Dau(range));
    Xp_Dau = reshape(spx_Dau,I);
    Yp_Dau = ttm(tensor(Xp_Dau),D0,[1,2,3]);    
    PSNR_Dau(n) = 20*log10(max(Y(:))/sqrt(mean((Y(:) - Yp_Dau(:)).^2)));
    
    n = n + 1;
    disp(['Percentage p=',num2str(p)])
end

figure
plot(percrange*100,PSNR_Dau)
xlabel({'Kept Coefficients (%)'});
ylabel({'PSNR (dB)'});
title({'Sparse Tucker Approximation is obtained by keeping the largest absolute coefficients (core tensor entries)'});








