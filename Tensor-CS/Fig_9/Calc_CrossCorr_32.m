function [b] = Calc_CrossCorr_32(D1,D2,i1,i2,p,Mask)
%#codegen
%p = length(i1);
%b = zeros(p-1,1);
b = zeros(1024,1);

%I1 = size(D1,1);
%I2 = size(D2,2);

%mask = zeros(I1*I2,1);
%mask(sub2ind([I1,I2], ind1(1:K)', ind2(1:K)'))=1;
%w = kron(D2(:,i2(p)),D1(:,i1(p))).*mask;
W = (D1(:,i1(p))*D2(:,i2(p))').*Mask;

for p1=1:p-1
   %b(p1) = kron(D2(:,i2(p1))',D1(:,i1(p1))')*w;
   b(p1) = D1(:,i1(p1))'*W*D2(:,i2(p1));   
end

b = b(1:p-1);

end