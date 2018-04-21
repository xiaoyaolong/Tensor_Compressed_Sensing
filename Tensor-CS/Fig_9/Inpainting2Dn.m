function [Yap, X] = Inpainting2Dn(I0, Mask, D0, epsilon,sparsity,displaymode)
% I0: 2D image
% perc: sampling ratio
% base: dictionary selection 'Daubechies', 'Haar', etc.
% L: multiresolution levels

I = size(I0);
ind1 = zeros(prod(I),1);
ind2 = zeros(prod(I),1);

selind = find(Mask);
K = length(selind);
[ind1(1:K),ind2(1:K)] = ind2sub(I(1),selind);

%cii = Calc_cii_8_mex(D0{1},D0{2},Mask);
%cii = Calc_cii_16_mex(D0{1},D0{2},Mask);
cii = Calc_cii_32_mex(D0{1},D0{2},Mask);
%cii = Calc_cii_64_mex(D0{1},D0{2},Mask);

% vector of selected entries
z = zeros(K,1);
for k=1:K
    z(k) = I0(ind1(k),ind2(k));
end

% Cropped Tensor (zeros at non seleced positions)
Y = I0.*Mask;
norma = norm(Y,'fro');

% Auxiliar correlation
MATV = D0{1}'*Y*D0{2};

%% Compute tensor modified OMP
% Initial residual
R = Y;
error = Inf;
P = round(prod(I)*sparsity); % Max number of nonzero entries
i1 = zeros(1,prod(I));
i2 = zeros(1,prod(I));
p = 1;

v = zeros(P,1);

while (error > epsilon) && (p <= P)
    % Max Correlated atom detection
    
    PROJ = abs(D0{1}'*R*D0{2});
    [value,i] = max(PROJ(:)./cii);
    [i1(p),i2(p)] = ind2sub(I(1),i);
    
    w = full(D0{1}(ind1(1:K),i1(p)).*D0{2}(ind2(1:K),i2(p)));
    
    if p==1
        lambda = pinv(w)*z;  
        Zinv = 1/(w'*w);
        v(1,1) = MATV(i1(p),i2(p));
        
    else
        %b = Calc_CrossCorr_8_mex(D0{1},D0{2},i1,i2,p,Mask);  
        %b = Calc_CrossCorr_16_mex(D0{1},D0{2},i1,i2,p,Mask);  
        b = Calc_CrossCorr_32_mex(D0{1},D0{2},i1,i2,p,Mask);  
        %b = Calc_CrossCorr_64_mex(D0{1},D0{2},i1,i2,p,Mask);  

        d = Zinv*b;
        s = norm(w,'fro')^2 - b'*d;
        Zinv = (1/s)*[s*Zinv + d*d', -d; -d', 1]; 
        v(p,1) = MATV(i1(p),i2(p));       
        lambda = Zinv*v(1:p,1);
    end
        
    X = sparse(i1(1:p),i2(1:p),lambda',I(1),I(2));
    Yap = full(D0{1}*X*D0{2}');
    
    R = Y - Yap;
    R = R.*Mask;
    error = norm(R,'fro')/norma;
    
    if displaymode == 'sishow'
        PSNR = 20*log10(max(I0(:))/sqrt(mean((I0(:) - Yap(:)).^2))); 
        disp(['Error=',num2str(error),', p=',num2str(p),', sparsity=',num2str(p/prod(I)),', PSNR=',num2str(PSNR)])
    end
    p = p + 1;
end
p = p - 1;

%% Original
Yap = I0.*Mask + Yap.*(~Mask);


end




