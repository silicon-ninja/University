% Srikanth K 17ETCS002124
im = imread('Q1_4.tif'); 
image = imnoise(im,'salt & pepper',0.01); 
M = medfilt2(image);
imshow(M), title('Salt and Pepper Reduced Noise (Srikanth K 17ETCS002124)');  