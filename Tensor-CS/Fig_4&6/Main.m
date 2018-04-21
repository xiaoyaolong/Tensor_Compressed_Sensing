%% Written by C. Caiafa, 2013.
%% email: ccaiafa@gmail.com (http://web.fi.uba.ar/~ccaiafa/Cesar/Cesar.html)

%% Illustration of a 2D signal having a Kronecker sparse (Block-sparse) representation and its recovery by the Kron-OMP (NBOMP) algorithm
% This Matlab Code generates the results shown in Fig 4 and Fig 6 in the paper 
% "Multidimensional Compressed Sensing and its Applications", by C. Caiafa
% and A. Cichocki, submitted to Wiley Interdisciplinary Reviews: Data
% Mining and Knowledge Discovery (2013)

% In Fig 4, a 32x32 patch image is modeled as a linear combination of only K=9 atoms (out of 1024) of the separable DCT basis. 
% Compressive measurements are taken by multiplying each mode by a random (Gaussian) sensing matrix (16x32) (sampling ratio = 50%). 
% The successive correlations of the residual with the Kronecker basis are shown for each iteration of the Kron-OMP algorithm. 
% The sparsity pattern is correctly recovered afar exactly K=9 iterations

% In Fig 6,a 32x32 patch having a block sparse representation with K=9 atoms contained in a 3x3 block, is recovered from compressive
% measurements taken in the same way as in the example of Fig. 4. It is highlighted that NBOMP recover the correct sparse pattern after 
% exactly 3 iterations instead of 9 iterations that would require the OMP (unstructured) algorithm.

clear 
clc
close all

epsilon = 1e-10;
I = 32;
M = 16;
K = 9; % sparsity

D1 = dct(eye(I));
D2 = dct(eye(I));

%% Unstructured case (Kron-OMP algorithm)

% List of selected indices
% ind1 = [1,1,5,6,10,10,14,20,25];
% ind2 = [1,2,3,4,15,20,20,20,25];
% 
% X = zeros(I);
% for n=1:size(ind1,2)
%     X(ind1(n),ind2(n)) = randn(1);
% end

load 'varKronOMP.mat'; % load sensing matrices Phi1, Phi2 and sparse matrix X

Y = D1*X*D2'; % 2D sparse signal model

figure
imshow(Y,[-0.3,0.3],'InitialMagnification',400)
title('2D signal')
figure
imshow(D1,[-0.3,0.3],'InitialMagnification',400)
title('mode-1 dictionary')
figure
imshow(D2',[-0.3,0.3],'InitialMagnification',400)
title('mode-2 dictionary')
figure
imshow(X,[-0.3,0.3],'InitialMagnification',400)
title('sparse core matrix')

%Phi1 = randn(M,I);
%Phi2 = randn(M,I);
% save 'var.mat' 'X' 'Phi1' 'Phi2'

Z = Phi1*Y*Phi2'; % Compressive measurements

figure
imshow(Z,[-15,15],'InitialMagnification',400)
title('compressed measurement')
figure
imshow(Phi1,[-3,3],'InitialMagnification',400)
title('mode-1 sensing matrix')
figure
imshow(Phi2',[-3,3],'InitialMagnification',400)
title('mode-2 sensing matrix')

disp('Computing Kron-OMP algorithm...')
[A,indx] = KronOMP2D({Phi1*D1,Phi2*D2},Z,K,0);
disp(['  '])

figure
imshow(double(A),[-0.3,0.3],'InitialMagnification',400)
title('Recovered core matrix')

%% Block-sparse case (NBOMP algorithm)

% Block indices
%ind1 = [2,5,15];
%ind2 = [1,12,20];

%X = zeros(M);
%X(ind1,ind2) = randn(3,3);
load 'varNBOMP.mat'

Y = D1*X*D2'; % block-sparse signal model

figure
imshow(Y,[-0.3,0.3],'InitialMagnification',400)
title('2D signal')
figure
imshow(D1,[-0.3,0.3],'InitialMagnification',400)
title('mode-1 dictionary')
figure
imshow(D2',[-0.3,0.3],'InitialMagnification',400)
title('mode-2 dictionary')
figure
imshow(X,[-0.3,0.3],'InitialMagnification',400)
title('sparse core matrix')


% Phi1 = randn(I,M);
% Phi2 = randn(I,M);
% save 'varNBOMP.mat' 'X' 'Phi1' 'Phi2'

B1=normalize(Phi1*D1);
B2=normalize(Phi2*D2);

Z = B1*X*B2'; % Compressive measurements

figure
imshow(Z,[-1,1],'InitialMagnification',400)
title('compressed measurement')
figure
imshow(Phi1,[-3,3],'InitialMagnification',400)
title('mode-1 sensing matrix')
figure
imshow(Phi2',[-3,3],'InitialMagnification',400)
title('mode-2 sensing matrix')

disp('Computing NBOMP algorithm...')
[X,Ind] = tensor_OMPND({B1,B2},Z,[I I],epsilon)
figure
imshow(double(X),[-0.3,0.3],'InitialMagnification',400)
title('Recovered core matrix')



