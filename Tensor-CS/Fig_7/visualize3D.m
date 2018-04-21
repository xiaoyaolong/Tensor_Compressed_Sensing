function [hcap,hiso]= visualize3D(V,isovalue,rate, fig)
% Visualize iso-surface of a tensor Y with isovalue,
% isovalue  
%    isovalue < 0 : cube visualization
%    isovalue = 0.01 : visualization of reconstruction
%
% Copyright of Anh Huy Phan
% phan@brain.riken.jp
% 03/2008

% V = permute(V,[1,3,2]);
% fig = figure(1);clf
V = permute(flipdim(double(V),1),[3 2 1]);
if (exist('fig','var')~=1) ||  ~strcmp(get(fig,'type'),'figure') &&...
        ~strcmp(get(fig,'type'),'axes')
    fig = figure;    
end

set(fig,'Color','w');
if exist('isovalue','var')~= 1
    isovalue = .1*max(V(:));
end

if exist('rate','var')~= 1
    if numel(V)>=1e6
        rate = 5;
    else
        rate = 1;
    end
end
V = V(1:rate:end,1:rate:end,1:rate:end);

Ds = V;
hiso = patch(isosurface(Ds,isovalue),...
 'FaceColor',[1,.75,.65],...
 'EdgeColor','none');

hcap = patch(isocaps(V,isovalue),...
 'FaceColor','interp',...
 'EdgeColor','none');
% colormap(map)
view(45,30) 
axis tight 
daspect([1,1,1])

lightangle(45,30); 
h1 = camlight(0,-90);
set(gcf,'Renderer','zbuffer'); lighting phong; % gouraud
isonormals(Ds,hiso)
set(hcap,'AmbientStrength',.6)
set(hiso,'SpecularColorReflectance',0,'SpecularExponent',50)
camlight 
camlight('headlight')