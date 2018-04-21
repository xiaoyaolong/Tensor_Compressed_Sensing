function [b] = Calc_CrossCorr3D_8(D1,D2,D3,i1,i2,i3,p,Mask)
%#codegen
%p = length(i1);
%b = zeros(p-1,1);
b = zeros(512,1);

%bn = zeros(512,1);

I1 = size(D1,1);
I2 = size(D2,2);
I3 = size(D3,2);

%mask = zeros(I1*I2,1);
%mask(sub2ind([I1,I2], ind1(1:K)', ind2(1:K)'))=1;
%w = kron(D2(:,i2(p)),D1(:,i1(p))).*mask;
%W = (D1(:,i1(p))*D2(:,i2(p))').*Mask;
w = D1(:,i1(p))*D2(:,i2(p))';
w = w(:)*D3(:,i3(p))';
w = w(:).*Mask(:);
w = reshape(w,[I1,I2,I3]);

for p1=1:p-1
   %b(p1) = kron(D2(:,i2(p1))',D1(:,i1(p1))')*w;
   %b(p1) = D1(:,i1(p1))'*W*D2(:,i2(p1)); 
   
   %bn(p1) = double(ttensor(tensor(w),D1(:,i1(p1))',D2(:,i2(p1))',D3(:,i3(p1))'));
   
   u = D1(:,i1(p1))'*reshape(w,[I1,I2*I3]);
   u = reshape(u,[1,I2,I3]);
   u = D2(:,i2(p1))'*reshape(permute(u,[2,1,3]),[I2,I3]);
   %u = reshape(u,[1,1,I3]);
   %b(p1) = D3(:,i3(p1))'*reshape(permute(u,[3,1,2]),[I3,1]);
   b(p1) = D3(:,i3(p1))'*u';
   
%    for j1=1:I1
%        for j2=1:I2
%            for j3=1:I3
%                b(p1) = b(p1) + w(j1,j2,j3)*D1(j1,i1(p1))*D2(j2,i2(p1))*D3(j3,i3(p1));
%            end
%        end
%    end
end

b = b(1:p-1);
%bn = bn(1:p-1);

end