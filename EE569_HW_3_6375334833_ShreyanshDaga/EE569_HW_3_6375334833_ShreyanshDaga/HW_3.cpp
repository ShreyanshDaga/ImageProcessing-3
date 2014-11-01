//////////////////////////////////////////////////
//EE 569 Homework #3
//
//Date:			November 3, 2013
//Name:		Shreyansh Dnyanesh Daga
//ID:				6375-3348-33	
//Email:		sdaga@usc.edu
//
//Compiled and build on Visual Studio 2012
//OS: Windows 8
//File: HW_3.cpp
//////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

#include"HW_3.h"

int PrintMenu();
void TestFunction();

void main()
{
	int iCh = 0;

	while(1)
	{
		iCh = PrintMenu();		
		//GenerateTestImage();
		switch(iCh)
		{				
			case 1:
				Problem_1_A();				
			break;
		
			case 2:
			{
				Problem_1_B();		
			}
			break;
		
			case 3:
				Problem_1_C();
			break;			

			case 4:
				Problem_2_A();
			break;

			case 5:
				Problem_2_B();
			break;

			case 6:
				Problem_2_C();
			break;

			case 7:
				Problem_3_A();
			break;

			case 8:
				Problem_3_B();
			break;

			case 9:
				Problem_3_C();
			break;

			case 10:
				exit(0);
			break;

			case 0:
				TestFunction();
		}
	}
}

int PrintMenu()
{
	int iCh = 0;

	while(1)
	{
		system("CLS");		
		cout<<"\t\t\t\t\t\tShreyansh Daga, USCID 6375334833\n";
		cout<<"******* Home work 3 ********\n";		
		cout<<"*Problem 1:Spatial Warping\n";
		cout<<"1.\tQ1(a) Warping to Diamond shape\n";
		cout<<"2.\tQ1(b) Warping to Pentagon shape\n";
		cout<<"3.\tQ1(c) Warping to Circle shape\n\n";		
		cout<<"*Problem 2:Perspective Transformation and Imaging Geometry\n";
		cout<<"4.\tQ2(a) Preprocessing\n";
		cout<<"5.\tQ2(b) Capturing 3D scene\n";
		cout<<"6.\tQ2(c) Rotating Cube\n\n";
		cout<<"*Problem 3:Texture Analysis and Segmentation using Laws Filter\n";
		cout<<"7.\tQ3(a) Texture Image clustering\n";
		cout<<"8.\tQ3(b) Texture Segmentation\n";
		cout<<"9.\tQ3(c) Advanced\n";
		cout<<"10.\tExit\n";
		cout<<"0.\t TestFunction\n";
		cout<<"\n Enter your choice: ";
		cin>>iCh;

		if(iCh > 13)
		{
			cout<<"\n\n!! Please enter valid choice !!\n\n";
			getch();
			iCh = 0;
		}
		else
		{
			break;
		}
	}
	return iCh;
}

void TestFunction()
{
	Point p1(0.5,0.0);
	p1.Cart2Pol(0.5,0.5);
	p1.Pol2Cart(0.5,0.5);

	p1.iX = 0.0;
	p1.iY = 0.5;
	p1.Cart2Pol(0.5,0.5);
	p1.Pol2Cart(0.5,0.5);

	p1.iX = 0.25;
	p1.iY = 0.75;
	p1.Cart2Pol(0.5,0.5);
	p1.Pol2Cart(0.5,0.5);

	p1.iX = 0.75;
	p1.iY = 0.75;
	p1.Cart2Pol(0.5,0.5);
	p1.Pol2Cart(0.5,0.5);
}