function [W] = create_WT(Dim,redundancy,dim_exp,type,L,par)

if ~exist('dim_exp','var') 
    dim_exp = []; 
end

M = Dim;
Length_D = length(Dim);

if dim_exp > Length_D
    error('The dimension is not engough');
end

for num = 1:Length_D
    U{num} = eye(M(num));
end

for num = 1:Length_D
    if num ~= dim_exp
        W{num} = zeros(M(num),redundancy*M(num));
    else
        W{num} = zeros(M(num),M(num));
    end
end
 
qmf = MakeONFilter(type,par);

for num = 1:Length_D
    for j = 1:M(num)
        temp = FWT_PO(U{num}(:,j),L,qmf);
        W{num}(:,j) = temp;
    end
    W{num} = W{num}*diag(1./sqrt(diag(W{num}'*W{num})));
end
 
