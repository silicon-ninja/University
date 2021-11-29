% Srikanth K 17ETCS002124
I = imread('Q1_5.tif');
[Gx, Gy] = imgradientxy(I,'prewitt');
figure
imshowpair(Gx, Gy, 'montage');
title('Directional Gradients: x-direction, Gx (left), y-direction, Gy (right) (Srikanth K 17ETCS002124)')
axis off;