% This function solves the CS problem in MRI imaging by applying the SPGL1 algorithm with
% a Kronecker basis. Also compute the minimum energy reconstruction by
% applying the inverse FFT to each mode on the available samples of the
% k-space.

function [AproxBP,errorBP,PSNRBP,YNyq,errorNyq,PSNRNyq] = ComputeCSBP(I0,samplingratio,epsilon)

% Compute Wavelet Dictionaries
M = size(I0);

load DauBases.mat
W3 = eye(M(3),M(3));

I = round([M(1)*sqrt(samplingratio), M(2)*sqrt(samplingratio), M(3)]);

l0 = 120;
rndind = randperm(M(1));
l15 = l0;
ind1 = [l15:M(1)-l15];
tf = ismember(rndind,ind1);
rndind = rndind(~tf);
ind1 = [ind1,rndind(1:I(1)-size(ind1,2))];

%l1 = round((M(1)-I(1))/2);
SM1 = fftshift(fft(eye(M(1),M(1)),M(1)));
%SM1 = SM1(l1:M(1)-l1,:);
SM1 = SM1(ind1,:);

rndind = randperm(M(2));
l15 = l0;
ind2 = [l15:M(2)-l15];
tf = ismember(rndind,ind2);
rndind = rndind(~tf);
ind2 = [ind2,rndind(1:I(2)-size(ind2,2))];
%l2 = round((M(2)-I(2))/2);
SM2 = fftshift(fft(eye(M(2),M(2)),M(2)));
%SM2 = SM2(l2:M(2)-l2,:);
SM2 = SM2(ind2,:);

SM3 = fftshift(fft(eye(M(3),M(3)),M(3)));

Y = double(ttensor(tensor(I0),{SM1,SM2,SM3}));

D0{1} = normalize(SM1*W1');      
D0{2} = normalize(SM2*W2');
D0{3} = normalize(SM3*W3');

save 'dictionaries.mat' 'D0'

%% Compute BP
disp('Computing BP...')
y = reshape(Y,[prod(size(Y)),1]);

opts = spgSetParms('verbosity',1);
opA = @(x,mode) dict(x,mode);
tic
%xest = spg_bp(@dict,y,opts);
xest = spg_bpdn(@dict,y, epsilon, opts);
TimeBP=toc;

Xest = reshape(xest,M);
AproxBP = ttensor(tensor(Xest),{W1',W2',W3'});

AproxBP = abs(double(AproxBP))/norm(tensor(AproxBP));

I0 = I0/norm(tensor(I0));
errorBP = norm(tensor(I0 - AproxBP));
PSNRBP = 20*log10(max(I0(:))/sqrt(mean(abs(I0(:) - AproxBP(:)).^2)));
disp('Tensor Reconstruction done!')
disp(['Sampling ratio=',num2str(samplingratio),' PSNR=',num2str(PSNRBP),'dB',' Time=',num2str(TimeBP/60,2),'min']);

%% Compute Nyquist reconstruction
FFT1 = fftshift(fft(eye(M(1),M(1)),M(1)));
SM1 = zeros(M(1));
SM1(ind1,:) = FFT1(ind1,:);

FFT2 = fftshift(fft(eye(M(2),M(2)),M(2)));
SM2 = zeros(M(2));
SM2(ind2,:) = FFT2(ind2,:);

SM3 = fftshift(fft(eye(M(3),M(3)),M(3)));

Y = double(ttensor(tensor(I0),{SM1,SM2,SM3}));


YNyq = fftshift(ifftn(fftshift(Y)));
YNyq = abs(YNyq)/norm(tensor(YNyq));

errorNyq = norm(tensor(I0 - YNyq));
PSNRNyq = 20*log10(max(I0(:))/sqrt(mean(abs(I0(:) - YNyq(:)).^2)));
disp('Nyquist Reconstruction done!')
disp(['Sampling ratio=',num2str(samplingratio),' PSNR=',num2str(PSNRNyq),'dB']);

end





