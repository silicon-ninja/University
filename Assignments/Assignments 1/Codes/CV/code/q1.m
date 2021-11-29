% Srikanth K 17ETCS002124

%Arithmetic Mean Filter
x=imread('Q1_1.tif');
x1=imresize(x,[256,256]);
figure;imshow(x1)
title('Original Image (Srikanth K 17ETCS002124)')
x2=im2gray(x1);
figure;imshow(x2);title('Gray Image (Srikanth K 17ETCS002124)');
[m,n]=size(x2);
for i=1:m-3
    for j=1:n-3
        a=x(i:i+3,j:j+3);
        v(i,j)=sum(sum(a));
    end
end
y=mat2gray(v);
figure;imshow(y);
title('Output: Arithmetic Mean Filter (Srikanth K 17ETCS002124)');

% Min and Max Filter
Original=imread('Q1_1.tif');         
BW = im2bw(Original,0.6);           
minf=@(x) min(x(:));                
maxf=@(x)max(x(:));                
min_Image=nlfilter(BW,[3 3],minf);  
max_Image=nlfilter(BW,[3 3],maxf);  

subplot(2,2,1), imshow(BW), title('Original Image (Srikanth K 17ETCS002124)');   
subplot(2,2,2), imshow(min_Image), title('Min (Srikanth K 17ETCS002124)'); 
subplot(2,2,3), imshow(max_Image), title('Max (Srikanth K 17ETCS002124)'); 


% Alpha Trimmed Mean Filter Image
data=imread('Q1_1.tif');
figure,imshow(data);, title('Original Image (Srikanth K 17ETCS002124)');  
data=im2gray(data);
data=im2double(data);
masksize=2;
d=4;
figure,imshow(data)
[ro col]=size(data);
temp1=[];
graber=0;
akkumulator=[];
for i=1:ro;
    for j=1:col;
        for m=-masksize:masksize;
            for n=-masksize:masksize;
                if (i+m>0 && i+m<ro && j+n>0 && j+n<col && ...      
                        masksize+m>0 && masksize+m<ro && ...
                        masksize+n>0 && masksize+n<col) 
                    
                    temp1=[temp1 data(i+m,j+n)];
                                    
                end
            end
        end
         
        temp1=sort(temp1);
        lenth=length(temp1);
        for k=((d/2)-1):(lenth-(d/2))
            akkumulator=[akkumulator temp1(k)];
        end
        akkumulator=sum(akkumulator);
        reformedimage(i,j)=(akkumulator) / (25-d);
        
        akkumulator=[];
        temp1=[];
        
    end
end

figure,imshow(reformedimage), title('Alpha Trimmed Mean Filter Image (Srikanth K 17ETCS002124)');  