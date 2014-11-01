//////////////////////////////////////////////////
//EE 569 Homework #3
//
//Date:			September 22, 2013
//Name:		Shreyansh Dnyanesh Daga
//ID:				6375-3348-33	
//Email:		sdaga@usc.edu
//
//Compiled and build on Visual Studio 2012
//OS: Windows 8
//File: Problem_2.cpp
//////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

#include"HW_3.h"
#include"Pixel.h"
#include"Image.h"
#include"Misc.h"
#include"Histogram.h"

using namespace std;

void Problem_2_A()
{
	Image imCube[5];
	string strNames[5] = {"image1.raw","image2.raw","image3.raw","image4.raw","image5.raw",};
	int iRows = 200, iCols = 200;	

	for(int i = 0;i<5;i++)
	{
		InitImage(&imCube[i],strNames[i],iRows,iCols,3);
		imCube[i].ReadImageData();
	}

	//Image 1
	
	//Image 2

	//Image 3

	cout<<"\n I could Not Complete Homework 2 within deadline. I will complete it as soon as possible and submit as soon as possible.\nThank you.";
	cout<<"\nPress 'C' to continue..";
	getch();
}

void Problem_2_B()
{
	cout<<"\n I could Not Complete Homework 2 within deadline. I will complete it as soon as possible and submit as soon as possible.\nThank you.";
	cout<<"\nPress 'C' to continue..";
	getch();
}

void Problem_2_C()
{
	cout<<"\n I could Not Complete Homework 2 within deadline. I will complete it as soon as possible and submit as soon as possible.\nThank you.";
	cout<<"\nPress 'C' to continue..";
	getch();
}