clc; 
close all; 
clear all;
 
v = 12;
pi = 3.1416;
p = 1.2;
 
% create array for data which was read from Figure 4
x = [2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5];
y = [0.13, 0.19, 0.3, 0.36, 0.4, 0.425, 0.44, 0.45,0.45, 0.45, 0.435, 0.42, 0.385, 0.35, 0.295];
 
advanced_ratio = 2.5:0.070707:9.5; %creating 100 data points for advance ratio
Cp = []; %creating array for Cp(yvalues)
 
%interpolating  data 
j = 1;
for i = advanced_ratio
  y_lookup = interp1(x, y, i);  
    Cp(j) = y_lookup; %storing values in array
    j= j+1;
end
 
figure(1);
plot(advanced_ratio,Cp);
Cp_lookup = interp1(advanced_ratio, Cp, 2.7);
 
%creating arrays
P_avail = [];
P_ex = [];
r_array = [];
w_array = [];
 
index = 1;
 
%sweeping rotor spped and radius
for r = 1.05:0.05:7.95
    for w = 21:1:34
       ar = (r*w)/v;
       
       if (ar > 9.5)
           break
       end
       if (ar<2.5)
           continue
       end
       
    r_array(index) = r;
    w_array(index) = w;
    Cp_temp = interp1(advanced_ratio, Cp, ar);
    P_avail(index) = 0.5*p*pi*r^2*v*v^2;
    P_ex(index) = Cp_temp*P_avail(index);
    index= index + 1;
    end
    
end
 
%finding max values
max_Pex = max(P_ex);
index_maxpex = find(P_ex==max_Pex);
display(index_maxpex);
max_radius = r_array(index_maxpex);
max_rotorvelocity = w_array(index_maxpex);
