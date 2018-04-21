function [cii] = Calc_cii3D_8(D1,D2,D3,Mask)
%#codegen
I1 = size(D1,1);
I2 = size(D2,1);
I3 = size(D3,1);
%cii = zeros(I1*I2*I3,1);
cii = zeros(I1,I2,I3);

%mask = zeros(I1*I2,1);
%mask(sub2ind([I1,I2], ind1(1:K)', ind2(1:K)'))=1;

for j3=1:I3
    for j2=1:I2
        for j1=1:I1
            %w = kron(D2(:,j2),D1(:,j1)).*mask;
            %W = (D1(:,j1)*D2(:,j2)').*Mask;
            
            w = D1(:,j1)*D2(:,j2)';
            w = w(:)*D3(:,j3)';
            w = w(:).*Mask(:);
            %cii(sub2ind([I1,I2,I3], j1, j2, j3)) = sqrt(sum(w(:).^2));
            cii(j1, j2, j3) = sqrt(sum(w(:).^2));
        end
    end
end
cii = reshape(cii,[I1*I2*I3,1]);

end