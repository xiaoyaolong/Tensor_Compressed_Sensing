function [cii] = Calc_cii_32(D1,D2,Mask)
%#codegen
I1 = size(D1,1);
I2 = size(D2,1);
%cii = zeros(I1*I2,1);
cii = zeros(I1,I2);

%mask = zeros(I1*I2,1);
%mask(sub2ind([I1,I2], ind1(1:K)', ind2(1:K)'))=1;

for j2=1:I2
    for j1=1:I1
        %w = kron(D2(:,j2),D1(:,j1)).*mask;
        W = (D1(:,j1)*D2(:,j2)').*Mask;
        cii(j1, j2) = sqrt(sum(W(:).^2));
    end
end

cii = reshape(cii,[I1*I2,1]);

end