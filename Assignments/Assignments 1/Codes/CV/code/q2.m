% Srikanth K 17ETCS002124

% Image 1

a = imread('Q1_2.tif');
heq = histeq(a)
subplot(221);imshow(a);title('Original Image - 1  (Srikanth K 17ETCS002124)')
subplot(222);imshow(heq);title('Equalized Image - 1 (Srikanth K 17ETCS002124)')
subplot(223);imhist(a);title('Histrogram Original Image - 1')
subplot(224);imhist(heq);title('Histrogram Equalized Image - 1 (Srikanth K 17ETCS002124)')


% Image 2

b = imread('Q1_3.tif');
heq2 = histeq(b)
subplot(221);imshow(b);title('Original Image - 2  (Srikanth K 17ETCS002124)')
subplot(222);imshow(heq2);title('Equalized Image - 2 (Srikanth K 17ETCS002124)')
subplot(223);imhist(b);title('Histrogram Original Image - 2')
subplot(224);imhist(heq2);title('Histrogram Equalized Image - 2 (Srikanth K 17ETCS002124)')