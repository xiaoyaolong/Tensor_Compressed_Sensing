%% Written by C. Caiafa, 2013.
%% email: ccaiafa@gmail.com (http://web.fi.uba.ar/~ccaiafa/Cesar/Cesar.html)

%% Hyperspectral Compressive Sampling Imaging results.
% This Matlab Code generates the results shown in Fig 9 in the paper 
% "Multidimensional Compressed Sensing and its Applications", by C. Caiafa
% and A. Cichocki, submitted to Wiley Interdisciplinary Reviews: Data
% Mining and Knowledge Discovery (2013)

% Results of applying the Tensor Completion algorithm (Kron-TC) with Kronecker dictionary (orthogonal DCT) 
% 32x32 patches of "Barbara" data-set (512x512). A PSNR=27.66dB is obtained which is comparable to the state-of-the-arts methods.

%% This code takes about 90 minutes to run in a notebook computer (MacBookPro, 2.3GHz) using compiled MEX files
%% To generate Fig 9 just call MakeFig9() which displays the saved results

clc
clear

IM = double(imread('../Datasets/Barbara/Barbara.png'));

IS = size(IM);
IMrec = zeros(size(IM));
COUNT = zeros(size(IM));

I = [32,32];

load 'DCTbases'

perc = 0.2; % sampling ratio
epsilon = 0.055;
sparsity = 0.1;

% Selection of entries
K = round(prod(size(IM))*perc); % Number of samples
indices = randperm(prod(size(IM)));
[ind1,ind2] = ind2sub(size(IM,1),indices);

% Selection tensor
Mask = full(sparse(ind1(1:K)',ind2(1:K)',ones(K,1)));

h = waitbar(0);
end1 = IS(1)-I(1)+1;
end2 = IS(2)-I(2)+1;
Totiter = end1*end2;

tickID = tic;

for i1 = 1:1:end1
    for i2 = 1:1:end2
    tic
    areai = i1:i1+I(1)-1;
    areaj = i2:i2+I(2)-1;

    I0 = IM(areai,areaj);
    I = size(I0);

    [Yap, X] = Inpainting2Dn(I0, Mask(areai,areaj), D0, epsilon,sparsity,'noshow');
    Yap(Yap>255) = 255;
    Yap(Yap<0) = 0;
    
    IMrec(areai,areaj) = IMrec(areai,areaj) + Yap;
    COUNT(areai,areaj) = COUNT(areai,areaj) + 1;
    
    PSNR = 20*log10(max(I0(:))/sqrt(mean((I0(:) - Yap(:)).^2))); 
    disp(['PSNR (dB) = ', num2str(PSNR)]);
    
    M = max(I0(:));
    m = min(I0(:));
    mag =400;
    
    time = toc;
    remaining = (Totiter - ((i1-1)*end1 + i2-1))*time;
    message = ['Remaining ', num2str(remaining/60),' mins'];
    waitbar(((i1-1)*end1 + i2-1)/Totiter, h, message)

    end
    
end

IMrec = abs(IMrec./COUNT);
imagesc([IM,IM.*Mask,IMrec])
colormap('gray');
PSNR = 20*log10(max(IM(:))/sqrt(mean((IM(:) - IMrec(:)).^2)))

save 'resultsBarbara20perc.mat'

toc(tickID)

%% Generate Fig 9 from saved results
MakeFig9()


