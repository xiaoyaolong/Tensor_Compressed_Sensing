%% Written by C. Caiafa, 2013.
%% email: ccaiafa@gmail.com (http://web.fi.uba.ar/~ccaiafa/Cesar/Cesar.html)

%% Hyperspectral Compressive Sampling Imaging results.
% This Matlab Code generates the results shown in Fig 10 (case sampling ratio=25%) in the paper 
% "Multidimensional Compressed Sensing and its Applications", by C. Caiafa
% and A. Cichocki, submitted to Wiley Interdisciplinary Reviews: Data
% Mining and Knowledge Discovery (2013)

% Results of applying the Tensor Completion algorithm with Kronecker dictionary (orthogonal DCT) to 8x8x8 tensor 
% patches of the 3D brain data-set (256x256x100)

% This demo requires to have the following packages installed:
% - MATLAB Tensor Toolbox Version 2.4, Brett W. Bader and Tamara G. Kolda,  
% available at http://csmr.ca.sandia.gov/~tgkolda/TensorToolbox/, March 2010.

% We thank Dr. Anh Huy Phan for providing us the Matlab codes used to
% visualize 3D data-sets (visualize3D.m).

%% This code takes about 48hours to run in a notebook computer (MacBookPro, 2.3GHz) using compiled MEX files
%% To generate Fig 10 just call MakeFig10() which displays the saved results (case sampling ratio=25%)

clc
clear

load ../Datasets/3DBrain/brain.mat;
IM = double(im(1:256,1:256,1:64));

IS = size(IM);
IMrec = zeros(size(IM));
COUNT = zeros(size(IM));

%I = [4,4,4];
I = [8,8,8];
%I = [16,16,16];
%I = [32,32,32];

load 'DCTbases'

perc = 0.25; % sampling ratio
epsilon = 0.055;
sparsity = 0.1;

% Selection of entries
K = round(prod(size(IM))*perc); % Number of samples
indices = randperm(prod(size(IM)));
[ind1,ind2,ind3] = ind2sub(size(IM),indices);

% Selection tensor
Mask = double(sptensor([ind1(1:K)',ind2(1:K)',ind3(1:K)'],ones(K,1),IS));

h = waitbar(0);

end1 = IS(1)-I(1)+1;
end2 = IS(2)-I(2)+1;
end3 = IS(3)-I(3)+1;

tickID = tic;

Totiter = end1*end2*end3;
iter = 1;
for i1 = 1:1:end1  
    for i2 = 1:1:end2
        for i3 = 1:1:end3
            tic
            areai = i1:i1+I(1)-1;
            areaj = i2:i2+I(2)-1;
            areak = i3:i3+I(3)-1;

            I0 = IM(areai,areaj,areak);
            I = size(I0);

            [Yap, X] = Inpainting3Dn(I0, Mask(areai,areaj,areak), D0, epsilon,sparsity,'noshow');
            IMrec(areai,areaj,areak) = IMrec(areai,areaj,areak) + Yap;
            COUNT(areai,areaj,areak) = COUNT(areai,areaj,areak) + 1;

            PSNR = 20*log10(max(I0(:))/sqrt(mean((I0(:) - Yap(:)).^2))); 
            disp(['PSNR (dB) = ', num2str(PSNR)]);

            M = max(I0(:));
            m = min(I0(:));
            mag =400;
            time = toc;
            %remaining = (Totiter - ((i1-1)*end3 + i2-1)*end2 + i3 -1)*time;
            remaining = (Totiter - iter)*time;
            message = ['Remaining ', num2str(remaining/60/60),' hours ', '(i1,i2,i3)=','(',num2str(i1),',',num2str(i2),',',num2str(i3),')'];
            waitbar(iter/Totiter, h, message)
            iter = iter + 1;
        end
    end
    
end

IMrec = IMrec./COUNT;
imagesc([IM(:,:,32),IM(:,:,32).*Mask(:,:,32),IMrec(:,:,32)])
colormap('gray');
PSNR = 20*log10(max(IM(:))/sqrt(mean((IM(:) - IMrec(:)).^2)))

toc(tickID)

save results

%% Generate Fig 10 from saved data results
MakeFig10()
