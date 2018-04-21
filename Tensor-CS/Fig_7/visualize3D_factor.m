function [hcap,hiso]=visualize3D_factor(Y,isovalue,A,d)
% Visualize iso-surface of a tensor Y with isovalue,
% Factors A are also displayed around its tensor.
% d: distance rate between factors and tensor
%
% Ref: visualized3D
% Copyright of Anh Huy Phan
% phan@brain.riken.jp
% 04/2008
In = size(Y);
[hcap,hiso]= visualize3D(Y,isovalue,1);
%%
if ~isempty(A)
    if ~exist('d','var') ==1
        d = .9;
    end
    hold on
    D = min(In*1)*d;

    % factor 1
    k = 1;

    plot3(bsxfun(@plus,A{k}/max(A{k}(:))*.98,...
        0:size(A{k},2)-1)*(In(2)-1)/size(A{k},2)+1,...
        -D*ones(1,In(k)),In(k):-1:1)

    text((.5:size(A{k},2)-.5)*(In(2)-1)/size(A{k},2),...
        -D*ones(1,size(A{k},2)),  ...
        In(k)+zeros(1,size(A{k},2))+5,...
        {1:size(A{k},2)})

    axis tight
    hf(k) = patch([1.01 In(2)-.01 In(2)-.01  1.01 1.01 ] ,...
        [-D -D -D -D -D ], [1 1 In(1)  In(1) 1 ],[255 255 215]/255);

    % factor 2
    k = 2;
    plot3(1:In(2),...
        bsxfun(@plus,A{k}/max(A{k}(:))*.98,...
            0:size(A{k},2)-1)*(In(3)-1)/size(A{k},2)+1,...
            -D*ones(1,In(2)))

    text(zeros(1,size(A{k},2))-5,...
        (.5:size(A{k},2)-.5)*(In(3)-1)/size(A{k},2),...
        -D*ones(1,size(A{k},2)),  ...
        {1:size(A{k},2)})

    hf(k) = patch([1.01 1.01 In(2)-.01 In(2)-.01 1.01 ],...
        [1.01 In(3)-1.01 In(3)-1.01 1.01 1.01] ,...
        [-D -D -D -D -D ],[255 255 215]/255);

    % factor 3
    k = 3
    plot3(In(k)+D*ones(1,In(k)),...
        1:In(k),...
        bsxfun(@plus,A{k}/max(A{k}(:))*.98,...
        0:size(A{k},2)-1)*(In(1)-1)/size(A{k},2)+1)

    text(In(k)+D*ones(1,size(A{k},2)),...
        zeros(1,size(A{k},2))+In(k)+5,...
        (.5:size(A{k},2)-.5)*(In(1)-1)/size(A{k},2),...
        {1:size(A{k},2)})

    hf(k) = patch(In(k)+[D D D D D ] ,[1 1 In(3)-.01 In(3)-.01 1 ],...
        [1 In(1) In(1) 1 1],[255 255 215]/255);

    set(hf,'AmbientStrength',1,'Facealpha',.6)
    axis off
    view(-52,28)
    axis tight

    text(In(2)/2,-D,In(1)*1.3,'${\bf A}^{(1)}$','interpreter','latex')
    text(-In(2)*0.3,In(3)/2,-D,'${\bf A}^{(2)}$','interpreter','latex')
    text(In(3) + D,In(3)/2,In(1)*1.3,'${\bf A}^{(3)}$','interpreter','latex')
end