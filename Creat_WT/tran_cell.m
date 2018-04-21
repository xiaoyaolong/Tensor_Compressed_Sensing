function [D] = tran_cell(D0)

num_all = length(D0);

for num = 1:num_all
    D{num} = D0{num}';
end

