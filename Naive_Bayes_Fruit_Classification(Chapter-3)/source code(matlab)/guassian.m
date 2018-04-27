function prob = guassian( mean, std, x )
if std == 0
    std = 0.000001;
end
%std = std + 0.5;
exponent = exp(-pow2(x - mean)/(2 * std * std));
suffix = 1 / (sqrt(2 * 3.14) * std);

prob = exponent * suffix;
%clear('exponent', 'suffix', 'prob');
end

