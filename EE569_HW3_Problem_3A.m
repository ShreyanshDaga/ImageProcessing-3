%%%%%%%%%%%%%%%%%%%%
%EE 569 Homework #3
%Date:			November 3, 2013
%Name:			Shreyansh Dnyanesh Daga
%ID:			6375-3348-33	
%Email:			sdaga@usc.edu
%Compiled and build on 	Matlab R2013a
%OS: Windows 8
%File: EE569_HW3_Problem_3A.m
%%%%%%%%%%%%%%%%%%%%%%%%%

%%Obtain file from c++ prgram 'Q33_A.csv', This will contain the 12x9 feature values and use it as follows
X = csvread('Q3_A.csv');
A = kmeans(X,4);
disp('Clustering based on k-means with k = 4');
disp(A);