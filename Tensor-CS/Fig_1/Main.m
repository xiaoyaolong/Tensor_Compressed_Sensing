%% Written by C. Caiafa, 2013.
%% email: ccaiafa@gmail.com (http://web.fi.uba.ar/~ccaiafa/Cesar/Cesar.html)

%% 1D CS example illustrating the application of the BP and MPsparsity recovery methods

% This Matlab Code generates the results shown in Fig 1 in the paper 
% "Multidimensional Compressed Sensing and its Applications", by C. Caiafa
% and A. Cichocki, submitted to Wiley Interdisciplinary Reviews: Data
% Mining and Knowledge Discovery (2013)

% This code requires SGPL1 v1.7: A solver for large-scale sparse reconstruction, Michael P.  Friedlander 
% and Ewout van den Berg, http://www.cs.ubc.ca/labs/scl/spgl1/index.html

clear 
clc
close all

%% Generate signals
I = 256; % signal size
M = 64; % measurement size
K = 5; % sparsity

load 'var.mat'  % load matrix D (IxI Daubechies WT dictionary), matrix Phi (MxI random Gaussian) 
                % and sparse vector x containing non-zero entries at [3,5,10,100,250]
                
%ind = [3,5,10,100,250];
%x = zeros(I,1);
%x(ind) = randn(K,1);
                
y = D*x; % sparse modelling of signal y

% Display Daubechies Dictionary
figure
for n=1:5
    subplot(8,1,n);
    plot(D(:,n));
    xlim([0 I]);
    ylim([-0.6 0.6]);
end
subplot(8,1,6);
plot(D(:,10));
xlim([0 I]);
ylim([-0.6 0.6]);

subplot(8,1,7);
plot(D(:,100));
xlim([0 I]);
ylim([-0.6 0.6]);

subplot(8,1,8);
plot(D(:,250));
xlim([0 I]);
ylim([-0.6 0.6]);
annotation('textbox',...
    [0.3875 0.925190476190478 0.259821428571429 0.0571428571428571],...
    'String',{'Daubechies WT dictionary'},'LineStyle','none');

% Display signal y
figure
plot(y)
xlim([0 I]);
ylim([-0.6 0.6]);
title('Original signal y')

%% Take compressive measurements

z = Phi*y; % measurements

% display measurements z
figure
plot(z)
xlim([0 M]);
title('Compressive measurements')

%% Apply BP method (SPGL1 algorithm)

[x,r,g,info] = spg_bp(Phi*D,z);

% display reconstructed signal 
figure
plot(D*x)
xlim([0 I]);
title('SPGL1 recovery')

% display sucessive approximations of vector x in iterations 1,2,3 and 79
figure
load 'x1'
subplot(4,1,1);
stem(x,'MarkerSize',2)
xlim([0 I]);

load 'x2'
subplot(4,1,2);
stem(x,'MarkerSize',2)
xlim([0 I]);

load 'x3'
subplot(4,1,3);
stem(x,'MarkerSize',2)
xlim([0 I]);

load 'x79'
subplot(4,1,4);
stem(x,'MarkerSize',2)
xlim([0 I]);

%% Apply OMP algorithm
epsilon = 1e-10;
[indx] = OMP(Phi*D,z,K,epsilon);

% display reconstructed signal 
figure
plot(D*x)
xlim([0 I]);
title('OMP recovery')



