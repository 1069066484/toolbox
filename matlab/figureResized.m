% Creates a figures that takes up certain area of screen.
%
% Almost same as figure, except get to specify what fraction of available
% screen space figure should take up.  Figure appears in center of screen.
%
% USAGE
%  varargout = figureResized( screenratio, varargin )
%
% INPUTS
%  screenratio - controls fraction of screen image takes out (<=.8)
%  varargin    - parameters to figure
%
% OUTPUTS
%  varargout   - out from figure
%
% EXAMPLE
%  figureResized( .75 )
%
% See also FIGURE

% Piotr's Image&Video Toolbox      Version NEW
% Written and maintained by Piotr Dollar    pdollar-at-cs.ucsd.edu
% Please email me if you find bugs, or have suggestions or questions!

function varargout = figureResized( screenratio, varargin )

if( nargin<1 ); screenratio=.3; end
if( screenratio>1 ); error('screenratio must be <= 1'); end

% call figure
h = figure( varargin{:} );
if( nargout ); varargout = {h}; end;

% get dimensions of screen and what want figure to be
units = get(0,'Units');
ss = get(0,'ScreenSize');
st = (1 - screenratio)/2;
pos = [st*ss(3), st*ss(4), screenratio*ss(3), screenratio*ss(4)];

% set dimensions of figure
set( h, 'Units', units );
set( h, 'Position', pos );