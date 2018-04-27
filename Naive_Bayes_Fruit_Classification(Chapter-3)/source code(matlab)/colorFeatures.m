function colorMoments = colorFeatures(image)
R = double(image(:, :, 1));
G = double(image(:, :, 2));
B = double(image(:, :, 3));
meanR = mean( R(:) );
stdR  = std( R(:) );
sknR = iqr(R(:));
meanG = mean( G(:) );
stdG  = std( G(:) );
sknG = iqr(G(:));
meanB = mean( B(:) );
stdB  = std( B(:) );
sknB = iqr(B(:));

colorMoments = zeros(1, 9);

colorMoments = [meanR stdR sknR meanG stdG sknG meanB stdB sknB];

clear('R','G','B','meanR','stdR','meanG','stdG','meanB','stdB');

end