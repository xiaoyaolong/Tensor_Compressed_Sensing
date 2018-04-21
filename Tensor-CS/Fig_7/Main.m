%% Written by C. Caiafa, 2013.
%% email: ccaiafa@gmail.com (http://web.fi.uba.ar/~ccaiafa/Cesar/Cesar.html)

%% CS MRI application
% This Matlab Code generates the results shown in Fig 7 in the paper 
% "Multidimensional Compressed Sensing and its Applications", by C. Caiafa
% and A. Cichocki, submitted to Wiley Interdisciplinary Reviews: Data
% Mining and Knowledge Discovery (2013)

% This demo requires to have the following packages installed:
% - MATLAB Tensor Toolbox Version 2.4, Brett W. Bader and Tamara G. Kolda,  
% available at http://csmr.ca.sandia.gov/~tgkolda/TensorToolbox/, March 2010.
% - SGPL1 v1.7: A solver for large-scale sparse reconstruction, Michael P.  
% Friedlander and Ewout van den Berg, http://www.cs.ubc.ca/labs/scl/spgl1/index.html

% Here we show an Hyperspectral Compressive Imaging example based on a natural scene image (1024x1024x32) corresponding to the data-set 
% of Scene 4 in the Foster & Nascimento & Amano database (http://personalpages.manchester.ac.uk/staff/david.foster/)
% For each channel we apply a separable random sensing matrix. We also assume that the data-set has a multiway block-sparse representation 
% using the separable Daubechies Wavelet Transform basis. The results for a
% sampling ratio=33% is shown here.

% We thank Dr. Anh Huy Phan for providing us the Matlab codes used to
% visualize 3D data-sets (visualize3D.m).

clear
clc

load ../Datasets/3DBrain/brain.mat;
I0=double(im);

%% Display original 3D image
I0 = I0/norm(tensor(I0));
MakeFig(I0,Inf,1.0)

%% Compute reconstruction based on Kronecker BP using SPGL1 algorithm (sampling ratio = 75%)
epsilon = 0.03;
samplingratio = 0.75;

[AproxBP,errorBP,PSNRBP,YNyq,errorNyq,PSNRNyq] = ComputeCSBP(I0,samplingratio,epsilon);

MakeFig(abs(AproxBP),PSNRBP,samplingratio);
MakeFig(abs(YNyq),PSNRNyq,samplingratio);


%% Compute reconstruction based on Kronecker BP using SPGL1 algorithm (sampling ratio = 50%)
epsilon = 0.03;
samplingratio = 0.50;

[AproxBP,errorBP,PSNRBP,YNyq,errorNyq,PSNRNyq] = ComputeCSBP(I0,samplingratio,epsilon);

MakeFig(abs(AproxNBOMP),PSNRNBOMP,samplingratio);
MakeFig(abs(YNyq),PSNRNyq,samplingratio);

