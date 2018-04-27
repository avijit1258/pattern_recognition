

apple = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\apples\*.jpg';
mango = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\mangos\*.jpg';
orange = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\oranges\*.jpg';
strawberry = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\strawberries\*.jpg';
banana = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\bananas\*.jpg';

appleD = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\apples\';
mangoD = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\mangos\';
orangeD = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\oranges\';
strawberryD = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\strawberries\';
bananaD = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\bananas\';


features = zeros( 100 , 16);
iter = 1;
for i = 1 : 5

    if i == 1
    imagefiles = dir(apple);
    elseif i == 2 
    imagefiles = dir(mango);
    elseif i == 3
    imagefiles = dir(orange);
    elseif i == 4
    imagefiles = dir(strawberry);
    elseif i == 5
    imagefiles = dir(banana);
    end
    
nfiles = length(imagefiles);

    for j =1:nfiles
       currentfilename = imagefiles(j).name;
       %disp(currentfilename);
        if i == 1
        currentfilename = strcat(appleD ,currentfilename);
        elseif i == 2 
        currentfilename = strcat(mangoD ,currentfilename);
        elseif i == 3
        currentfilename = strcat(orangeD ,currentfilename);
        elseif i == 4
        currentfilename = strcat(strawberryD ,currentfilename);
        elseif i == 5
        currentfilename = strcat(bananaD ,currentfilename);
        end
       
       im = imread(currentfilename);
       
       hello = imresize(im,[100,100]);
       currentimage = double(hello);
       %disp(size(currentimage));
       color_feature = colorFeatures(hello);
       shape_feature = shapeFeatures(hello);      
       features(iter, :) = [color_feature shape_feature];
       iter = iter + 1;
    end

end

train_feature_a = zeros(16, 2);
train_feature_b = zeros(16, 2);
train_feature_s = zeros(16, 2);
train_feature_m = zeros(16, 2);
train_feature_o = zeros(16, 2);


for i = 1 : 16
    
train_feature_a(i,1) = mean(features(1:20, i));
train_feature_a(i,2) = std(features(1:20, i));


% a m o s b
train_feature_m(i,1) = mean(features(21:40, i));
train_feature_m(i,2) = std(features(21:40, i));

train_feature_o(i,1) = mean(features(41:60, i));
train_feature_o(i,2) = std(features(41:60, i));

train_feature_s(i,1) = mean(features(61:80, i));
train_feature_s(i,2) = std(features(61:80, i));

train_feature_b(i,1) = mean(features(81:100, i));
train_feature_b(i,2) = std(features(81:100, i));

end


testD = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\test_data\*.jpg';
test = 'C:\Users\aviji\OneDrive\Pattern Lab\FIDS30\test_data\';
imagefiles = dir(testD);    
nfiles = length(imagefiles);
test_feature = zeros(nfiles, 16);
    for j =1:nfiles
       currentfilename = imagefiles(j).name;
       %disp(currentfilename);
       currentfilename = strcat(test ,currentfilename);
       disp(currentfilename);
       im = imread(currentfilename);
       
       hello = imresize(im,[100,100]);
       currentimage = double(hello);
       %disp(size(currentimage));
       color_feature = colorFeatures(hello);
       shape_feature = shapeFeatures(hello);      
       test_feature(j , :) = [color_feature shape_feature];
       
    end
    
 
    
for f=1 : nfiles
    
    disp(imagefiles(f).name);
    pxA = 1;
    pxM = 1;
    pxO = 1;
    pxS = 1;
    pxB = 1;
    
    for i = 1 : 16
    
        
        pd_kernel = fitdist(features(1:20, i), 'kernel', 'kernel', 'triangle');
        a_pdf = pdf(pd_kernel,test_feature(f,i));
        pxA = pxA + a_pdf;
        
        
        pd_kernel = fitdist(features(21:40, i), 'kernel', 'kernel', 'triangle');
        m_pdf = pdf(pd_kernel,test_feature(f,i));
        pxM = pxM + m_pdf;

       
        
        pd_kernel = fitdist(features(41:60, i), 'kernel', 'kernel', 'triangle');
        o_pdf = pdf(pd_kernel,test_feature(f,i));
        pxO = pxO + o_pdf;

        
        
        pd_kernel = fitdist(features(61:80, i), 'kernel', 'kernel', 'triangle');
        s_pdf = pdf(pd_kernel,test_feature(f,i));
        pxS = pxS + s_pdf;

        
        
        pd_kernel = fitdist(features(81:100, i), 'kernel', 'kernel', 'triangle');
        b_pdf = pdf(pd_kernel,test_feature(f,i));
        pxB = pxB + b_pdf;

    end
    
    px = 0.2 * (pxA + pxM + pxO + pxS + pxB);
    
    pA = ((0.2 * pxA) / px);
    pM = ((0.2 * pxM) / px);
    pO = ((0.2 * pxO) / px);
    pS = ((0.2 * pxS) / px);
    pB = ((0.2 * pxB) / px);
    
    p = [pA pM pO pS pB];
    disp('Apple Mango Orange Strawberry Banana');
    disp(p);
end