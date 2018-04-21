function [indx] = OMP(B,z,K,epsilon)

norma = norm(z,'fro');
residual = z;
indx=zeros(K,1);
I = size(B,2);

figure
for j=1:1:K,
    proj=B'*residual;

    subplot(5,1,j);
    bar(abs(proj))
    xlim([0 I]);
    %ylim([0 1]);
    
    [maxVal,pos] = max(abs(proj));
    pos = pos(1);
    indx(j) = pos;
    a = pinv(B(:,indx(1:j)))*z;
    residual = z - B(:,indx(1:j))*a;
    
    if sum(residual.^2)/norma < epsilon
        break;
    end
end;
return;
end
