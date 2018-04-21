function [y] = dict(x,mode)
load 'dictionaries.mat'
[I1,M1] = size(D0{1});
[I2,M2] = size(D0{2});
[I3,M3] = size(D0{3});

if mode == 2
    X = reshape(x,[I1,I2,I3]);
    Y = double(ttensor(tensor(X),transpose(D0)));
    y = reshape(Y,[M1*M2*M3,1]);
else
    X = reshape(x,[M1,M2,M3]);
    Y = double(ttensor(tensor(X),D0));
    y = reshape(Y,[I1*I2*I3,1]);
end

end

function [D] = transpose(D)
M = size(D,2);
for m = 1:M
    D{m} = D{m}';
end

end
