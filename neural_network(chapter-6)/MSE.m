disp('Enter the function');
syms w1 w2
eq = input('');
%disp(eq);

difW1 = diff(eq,w1);
difW2 = diff(eq,w2);
w1(1) = 0;
w2(1) = 0;
s = inline(eq);
%F = feval(s,w1,w2);
a = inline(difW1);
b = inline(difW2);
%Fw1 = feval(a,w1,w2);
%Fw2 = feval(b,w1,w2);
%disp(difW2);
count = 1;
c = 0.1;
i = 1;
disp('Iteration    F            DF/Dw1       DF/Dw2        w1           w2');
while(1)
   
    F = feval(s,w1(i),w2(i));
    Fw1 = feval(a,w1(i),w2(i));
    Fw2 = feval(b,w1(i),w2(i));
    
    pr = sprintf('  %d        %f       %f     %f     %f     %f',i,F,Fw1,Fw2,w1(i),w2(i));
    disp(pr)
    
    if i > 2
        if w1(i) == w1(i-1) && w2(i) == w2(i-1)
            count = count+1;
        else
            count = 1;
        end
    end
    
    if count == 6
        break;
    end
    
    i = i+1;
    w1(i) = double(w1(i-1) - (c*Fw1));
    w2(i) = double(w2(i-1) - (c*Fw2));
    
    
end


