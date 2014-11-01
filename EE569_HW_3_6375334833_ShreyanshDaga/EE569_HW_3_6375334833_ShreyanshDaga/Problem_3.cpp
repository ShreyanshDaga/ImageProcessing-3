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
//File: Problem_3.cpp
//////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

#include"HW_3.h"
#include"Pixel.h"
#include"Image.h"
#include"Histogram.h"
#include"Matrix.h"
#include"Misc.h"

using namespace std;

double LawFilter_3(double daImageWin[3][3], Matrix *pmatLawFilter);
double LawFilter_5(double daImageWin[5][5], Matrix *pmatLawFilter);

void Problem_3_A()
{
	Image imTexture[12];
	string strTexture[12] = {"texture1.raw","texture2.raw","texture3.raw","texture4.raw","texture5.raw","texture6.raw","texture7.raw","texture8.raw","texture9.raw","texture10.raw","texture11.raw","texture12.raw"};
	int iRows = 128, iCols =128;
	
	for(int i = 0;i<12;i++)
	{
		InitImage(&imTexture[i], strTexture[i], iRows, iCols, 1);
		imTexture[i].ReadImageData();
	}

	Matrix  matESW[3];
	Matrix *pmatLawFilters[9];
	double dE5[5] = {-1.0/6.0,-2.0/6.0,0.00,2.0/6.0,1.0/6.0};
	double dS5[5] = {-1.0/4.0,0,2.0/4.0,0.00,-1.0/4.0};
	double dW5[5] = {-1.0/6.0,2.0/6.0,0.00,-2.0/6.0,1.0/6.0};

	for(int i = 0;i<3;i++)
	{
		matESW[i].SetM(5);
		matESW[i].SetN(1);
		matESW[i].AllocMatrixMem();		
	}
	matESW[0].SetElements(dE5);
	matESW[1].SetElements(dS5);
	matESW[2].SetElements(dW5);	

	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			pmatLawFilters[i*3+j] = Matrix::MatrixMultiply(matESW[i],*matESW[j].MatrixTranspose());
			//pmatLawFilters[i*3+j]->PrintMatrix();
		}
	}

	double dFeatureVec[12][9];
	for(int i = 0;i<12;i++)
	{
		for(int j = 0;j<9;j++)
		{
			dFeatureVec[i][j] = 0.00;
		}
	}

	for(int k = 0;k<12;k++)
	{
		Image *pimTex = imTexture[k].ImageExtend(2);	
		for(int i = 2;i<iRows+2;i++)
		{
			for(int j = 2;j<iCols+2;j++)
			{
				double daImageWin[5][5];
				for(int l = 0;l<5;l++)
				{
					for(int m = 0;m<5;m++)
					{
						daImageWin[l][m] = pimTex->GetBW(i + l - 2,j + m -2);
					}
				}

				for(int p = 0;p<9;p++)
					dFeatureVec[k][p] += pow(LawFilter_5(daImageWin,pmatLawFilters[p]),2);
			}
		}		

		delete pimTex;
	}

	//Mean
	double **daFeatureMean = new double*[12];
	for(int i = 0;i<12;i++)
	{
		daFeatureMean[i] = new double[9];

		for(int j = 0;j<9;j++)
		{
			daFeatureMean[i][j] = sqrt(dFeatureVec[i][j] / (128*128));
			dFeatureVec[i][j] = daFeatureMean[i][j];
		}
	}	

	cout<<"\n* Writing .csv file which will contain 12x9 feature set for 12 texture images..then proceed to use matlab..";
	fstream File;

	File.open("Q3_A.csv",ios::out);

	for(int i = 0;i<12;i++)
	{
		File<<daFeatureMean[i][0]<<","<<daFeatureMean[i][1]<<","<<daFeatureMean[i][2]<<","<<daFeatureMean[i][3]<<","<<daFeatureMean[i][4]<<","<<daFeatureMean[i][5]<<","<<daFeatureMean[i][6]<<","<<daFeatureMean[i][7]<<","<<daFeatureMean[i][8];		
		File<<"\n";
	}
	File.close();

	//Clustering
	int *piLabels;
	cout<<"\nCSV File Written\nName: Q3_A.csv\n Proceed to Matlab to read this file and perfome kmeans using matlab\n\n This is output Using Kmeans() provided for c++..";
	piLabels = K_Means(daFeatureMean,12,9,4,0.0001,0);

	for(int i = 0;i<12;i++)
	{
		cout<<"\n "<<piLabels[i];
	}
	cout<<"\nPress 'C' to continue..";
	getch();
}

void Problem_3_B()
{
	string strName[2] = {"comb.raw", "CombSegment.raw"};
	int iRows = 450;
	int iCols = 600;
	Image imComb(strName[0],iRows, iCols, 1), imCombSegment(strName[1],iRows,iCols,1);

	imComb.ReadImageData();

	cout<<"\n*Forming 25 5x5 Kernals..";
	Matrix  matLESWR[5], matLES[3];
	Matrix *pmatLawFilters[25];
	double dL3[5] = {1.00/16.0,4.00/16.0,6.00/16.0,4.00/16.0,1.00/16.0};
	double dE3[5] = {-1.00/6.00,-2.00/6.00,0,2.00/6.00,1.00/6.00};	
	double dS3[5] = {-1.00/4.00,0,2.00/4.00,0,-1.00/4.00};
	double dW3[5] = {-1.00/6.00,2.00/6.00,0,-2.00/6.00,1.00/6.00};
	double dR3[5] = {1.00/16.00,-4.00/16.00,6.00/16.00,-4.00/16.00,1.00/16.00};

	for(int i = 0;i<5;i++)
	{
		matLESWR[i].SetM(5);
		matLESWR[i].SetN(1);
		matLESWR[i].AllocMatrixMem();		
	}
	matLESWR[0].SetElements(dL3);
	matLESWR[1].SetElements(dE3);
	matLESWR[2].SetElements(dS3);
	matLESWR[3].SetElements(dW3);
	matLESWR[4].SetElements(dR3);

	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			pmatLawFilters[i*5+j] = Matrix::MatrixMultiply(matLESWR[i],*matLESWR[j].MatrixTranspose());
		}
	}

	double **dPixelFeatureVector = new double*[270000];
	for(int i = 0;i<270000;i++)
	{
		dPixelFeatureVector[i] = new double[25];
	}

	//5x5 Kernals
	double **daLawFiltIm[25];
	Image *pimExComb, imLawFilt[25];
	string szName[25] = {"1.raw","2.raw","3.raw","4.raw","5.raw","6.raw","7.raw","8.raw","9.raw","10.raw","11.raw","12.raw","13.raw","14.raw","15.raw","16.raw","17.raw","18.raw","19.raw","20.raw","21.raw","22.raw","23.raw","24.raw","25.raw"};

	for(int i = 0;i<25;i++)
	{
		InitImage(&imLawFilt[i],szName[i],iRows,iCols,1);
		daLawFiltIm[i] = new double*[iRows];
		for(int k = 0;k<iRows;k++)
			daLawFiltIm[i][k] = new double[iCols];
	}

	pimExComb = imComb.ImageExtend(4);

	cout<<"\n*Applying 25 Laws filter over extended Image..";
	for(int i = 2;i<iRows+2;i++)
	{
		for(int j = 2;j<iCols+2;j++)
		{
			double daImageWin[5][5];
			for(int l = 0;l<5;l++)
			{
				for(int m = 0;m<5;m++)
				{
					daImageWin[l][m] = pimExComb->GetBW(i + l - 2,j + m - 2);
				}
			}

			double dPixVal[25];
			for(int k = 0;k<25;k++)
			{
				daLawFiltIm[k][i-2][j-2] = LawFilter_5(daImageWin,pmatLawFilters[k]);
			}
		}
	}

	for(int i = 0;i<25;i++)
	{
		imLawFilt[i].SetDoubleArray(daLawFiltIm[i],false);
		imLawFilt[i].WriteImageData();
	}

	//Energy Computation 15 window
	Image *pimExtended;
	double **daExArray;

	cout<<"\nCalculating Energy based on window size = 15..";
	for(int k = 0;k<25;k++)
	{
		pimExtended = imLawFilt[k].ImageExtend(7);
		daExArray = pimExtended->GetDoubleArray(false);

		for(int i = 7;i<iRows+7;i++)
		{
			for(int j = 7;j<iCols+7;j++)
			{
				double dpPixVal = 0.00;
				for(int l = 0;l<15;l++)
				{
					for(int m = 0;m<15;m++)
					{
						dpPixVal += daExArray[i + l - 7][j + m - 7];
					}
				}

				dpPixVal /= 121.00;
				daLawFiltIm[k][i-7][j-7] = dpPixVal;
			}
		}

		cout<<"\n*Normalizing w.r.t L5*L5'..";
		//Normalize w.r.t 1st filter
		for(int i = 0;i<25;i++)
		{
			for(int j = 0;j<iRows;j++)
			{
				for(int k = 0;k<iCols;k++)
				{
					double dFact = daLawFiltIm[0][j][k];

					daLawFiltIm[i][j][k] /= dFact;
					dPixelFeatureVector [j*iCols + k][i] = daLawFiltIm[i][j][k];
				}
			}
		}		
	}

	//Kmeans
	int labelcount = 6;
	cout<<"\n Enter Label count for kmeans (6/7): ";
	cin>>labelcount;
	cout<<"\n*Applying kmeans...";
	int *pLabel = K_Means(dPixelFeatureVector,270000,25,labelcount,0.0001,0);

	//File
	fstream File;
	
	//cout<<"\nWriting File..";
	//File.open("Q3_C.csv",ios::out);
	//for(int i = 0;i<270000;i++)
	//{
	//	File<<dPixelFeatureVector[i][0]<<","<<dPixelFeatureVector[i][1]<<","<<dPixelFeatureVector[i][2]<<","<<dPixelFeatureVector[i][3]<<","<<dPixelFeatureVector[i][4]<<","<<dPixelFeatureVector[i][5]<<","<<dPixelFeatureVector[i][6]<<","<<dPixelFeatureVector[i][7]<<","<<dPixelFeatureVector[i][8];		
	//	File<<"\n";
	//}
	//File.close();	

	//cout<<"\nFile Written..";
	
	//fstream File_in("Q3_C_ans.csv",ios::in);

	cout<<"\n*Writing OutputImage(labelVal*36 = Pixel Value)..";
	for(int i = 0;i<iRows;i++)
	{
		for(int j = 0;j<iCols;j++)
		{
			int iVal = pLabel[i*iCols + j];		
			Pixel pxP((iVal-1)*36);
			imCombSegment.SetPixel(i,j,pxP);
		}
	}

	imCombSegment.WriteImageData();

	//Clean Up
	for(int i = 0;i<270000;i++)
		delete [] dPixelFeatureVector[i];

	delete [] dPixelFeatureVector;
	getch();
	cout<<"\nPress 'C' to continue..";
}

void Problem_3_C()
{

}

double LawFilter_3(double daImageWin[3][3], Matrix *pmatLawFilter)
{
	double dVal = 0.00;

	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			dVal += daImageWin[i][j]*pmatLawFilter->GetElement(i,j);
		}
	}

	return dVal;
}

double LawFilter_5(double daImageWin[5][5], Matrix *pmatLawFilter)
{
	double dVal = 0.00;

	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			dVal += daImageWin[i][j]*pmatLawFilter->GetElement(i,j);
		}
	}

	return dVal;
}
