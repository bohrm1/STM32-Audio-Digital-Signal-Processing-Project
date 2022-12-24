clear 
close all

F = 32000;
alpha = 0.9;
filter_omega = 3.14159/8;

a = [2*alpha*cos(filter_omega), -1*alpha^2];
b = [1, -2 * cos(filter_omega), 1];

freqz(b,a,F); title('Frequency Response')