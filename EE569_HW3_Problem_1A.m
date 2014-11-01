%%%%%%%%%%%%%%%%%%%%
%EE 569 Homework #3
%Date:			November 3, 2013
%Name:			Shreyansh Dnyanesh Daga
%ID:			6375-3348-33	
%Email:			sdaga@usc.edu
%Compiled and build on 	Matlab R2013a
%OS: Windows 8
%File: EE569_HW3_Problem_1A.m
%%%%%%%%%%%%%%%%%%%%%%%%%

%Triangle 1
U = [0.25 0.00 0.50];
V = [0.25 0.50 0.50];

X = [0.00 0.00 0.50];
Y = [0.00 0.50 0.50];

A = [1 U(1) V(1);1 U(2) V(2);1 U(3) V(3)];

A_inv = inv(A);

c = A_inv*X';
d = A_inv*Y';

a = A*U';
b = A*V';

tmat1 = [c';d'];
tmat2 = [a';b'];
disp('Triangle_1');
disp(tmat1);
disp(tmat2);

%Triangle 2
U = [0.0 0.25 0.5];
V = [0.5 0.75 0.5];
X = [0.0 0.0 0.5];
Y = [0.5 1.0 0.5];

B = [1 U(1) V(1);1 U(2) V(2);1 U(3) V(3)];

B_inv = inv(B);

c = B_inv*X';
d = B_inv*Y';

tmat1 = [c';d'];
disp('Triangle_2');
disp(tmat1);

%Triangle 3
U = [0.50 0.25 0.50];
V = [0.50 0.75 1.00];
X = [0.50 0.00 0.50];
Y = [0.50 1.00 1.00];

B = [1 U(1) V(1);1 U(2) V(2);1 U(3) V(3)];

B_inv = inv(B);

c = B_inv*X';
d = B_inv*Y';

tmat1 = [c';d'];
disp('Triangle_3');
disp(tmat1);

%Triangle 4
U = [0.50 0.50 0.75];
V = [0.50 1.00 0.75];
X = [0.50 0.50 1.00];
Y = [0.50 1.00 1.00];

B = [1 U(1) V(1);1 U(2) V(2);1 U(3) V(3)];

B_inv = inv(B);

c = B_inv*X';
d = B_inv*Y';

tmat1 = [c';d'];
disp('Triangle_4');
disp(tmat1);

%Triangle 5
U = [0.50 0.75 1.00];
V = [0.50 0.75 0.50];
X = [0.50 1.00 1.00];
Y = [0.50 1.00 0.50];

B = [1 U(1) V(1);1 U(2) V(2);1 U(3) V(3)];

B_inv = inv(B);

c = B_inv*X';
d = B_inv*Y';

tmat1 = [c';d'];
disp('Triangle_5');
disp(tmat1);

%Triangle 6
U = [0.75 0.50 1.00];
V = [0.25 0.50 0.50];
X = [1.00 0.50 1.00];
Y = [0.00 0.50 0.50];

B = [1 U(1) V(1);1 U(2) V(2);1 U(3) V(3)];

B_inv = inv(B);

c = B_inv*X';
d = B_inv*Y';

tmat1 = [c';d'];
disp('Triangle_6');
disp(tmat1);

%Triangle 7
U = [0.50 0.50 0.75];
V = [0.00 0.50 0.25];
X = [0.50 0.50 1.00];
Y = [0.00 0.50 0.00];

B = [1 U(1) V(1);1 U(2) V(2);1 U(3) V(3)];

B_inv = inv(B);

c = B_inv*X';
d = B_inv*Y';

tmat1 = [c';d'];
disp('Triangle_7');
disp(tmat1);

%Triangle 8
U = [0.50 0.25 0.50];
V = [0.00 0.25 0.50];
X = [0.50 0.00 0.50];
Y = [0.00 0.00 0.50];

B = [1 U(1) V(1);1 U(2) V(2);1 U(3) V(3)];

B_inv = inv(B);

c = B_inv*X';
d = B_inv*Y';

tmat1 = [c';d'];
disp('Triangle_8');
disp(tmat1);

