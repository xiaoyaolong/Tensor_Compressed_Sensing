function [A,indx] = KronOMP2D(D,X,K,epsilon)

N = size(D,2);

for i = 1:N
    [I(i),M(i)] = size(D{i});
end

normaX = norm(X,'fro');

Res=X;

indx = zeros(K,N);
error = Inf;

figure
j = 1;
while (j <= K) && (error > epsilon)
    
    proj = D{1}'*Res*D{2};
    subplot(1,K,j)
    imagesc(abs(proj))
    title(['k=',num2str(j)])
    
    proj = reshape(proj,[prod(M),1]);
    
    
    
    [maxVal,pos]=max(abs(proj));
    [indi,indj]= ind2sub(M(1),pos);
    indx(j,:) = [indi,indj];
    
    for n = 1:N
        w{n} = D{n}(:,indx(j,n));
    end
    
    c = w{1}'*X*w{2};
    
    if j == 1
        for n = 1:N
            W{n} = w{n};
        end
    else
        for n=1:N 
            W{n} = [W{n} w{n}];
        end
    end
    
    a = pinv(kr(W{2},W{1}))*reshape(X,[prod(I),1]);

    Res = X - W{1}*diag(a)*W{2}';
    error = norm(Res,'fro')/normaX;
    disp(['Coef= ', num2str(j),' indx= ',num2str(indx(j,:)),'  Error= ',num2str(error)]);
    if error < epsilon
        j = j + 1;
        break;
    end
    j = j + 1;
end;

A = sptensor(indx(1:(j-1),:),a,M);

return;

end

