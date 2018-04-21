%% Written by C. Caiafa, 2013.
%% email: ccaiafa@gmail.com (http://web.fi.uba.ar/~ccaiafa/Cesar/Cesar.html)

%% Sparse Tucker approximation of multidimensional signals
% This Matlab Code generates the results shown in Fig 3 in the paper 
% "Multidimensional Compressed Sensing and its Applications", by C. Caiafa
% and A. Cichocki, submitted to Wiley Interdisciplinary Reviews: Data
% Mining and Knowledge Discovery (2013)

% The original tensor Y (3D MRI brain image) is represented by the Tucker model 
% Y=[X;D1,D2,D3]$, where factors D1,D2 and D3 are orthogonal, thus, the optimal 
% core tensor is given X=[Y;D1',D2',D3'].The tensor is reconstructed by keeping 
% only the largest (absolute values) entries of X. The resulting PSNR (dB), for 
% different amount of kept coefficients, are shown for the case of using Daubechies 
% WT dictionaries. 

% This demo requires to have the following package installed:
% MATLAB Tensor Toolbox Version 2.4, Brett W. Bader and Tamara G. Kolda,  
% available at http://csmr.ca.sandia.gov/~tgkolda/TensorToolbox/, March 2010. 

% We thank Dr. Anh Huy Phan for providing us the Matlab codes used to
% visualize 3D data-sets (visualize3D.m).

clc
clear

%% Load 3D MRI data-set
load ../Datasets/3DBrain/brain.mat;
Y = double(im(1:256,1:256,1:64));
I = size(Y);

%% image Y
%Xref = Y;
%maximum = max(Xref(:));
%Xref = Xref/maximum;
[hcap,hiso] = visualize3D_factor(Y/(max(Y(:))),.3,[],.1);
view(-126, 4)
delete(findobj('type','light','parent',gca))
camlight('headlight')
set(hiso,'AmbientStrength',.5,'DiffuseStrength',.6)
axis off

%% Daubechies case
load DauBasis.mat
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








