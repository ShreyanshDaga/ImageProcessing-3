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
//File: Problem_1.cpp
//////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

#include"HW_3.h"
#include"Pixel.h"
#include"Image.h"
#include"Histogram.h"
#include"Misc.h"
#include"Matrix.h"

using namespace std;

void Translate();
void Problem_1_A_b();

//Warping to Diamond
void Problem_1_A()
{
	//8 Triangle Method
	Image imPuppy, imPuppyWarped, imTestImage_1, imTestImgae_1_Warped;
	string strImageNames[4] = {"puppy.raw","puppy_warped.raw","test_1.raw","test_1_warped.raw"};
	int iRows, iCols;
	int iColorFormat;

	iRows = 500;
	iCols = 500;
	iColorFormat = 3;

	//Perform Warping on Puppy.raw
	InitImage(&imPuppy,strImageNames[2],iRows,iCols,iColorFormat);
	InitImage(&imPuppyWarped,strImageNames[3],iRows,iCols,iColorFormat);
	InitImage(&imTestImage_1,strImageNames[2],iRows,iCols,iColorFormat);
	InitImage(&imTestImgae_1_Warped,strImageNames[3],iRows,iCols,iColorFormat);

	imPuppy.ReadImageData();
	imTestImage_1.ReadImageData();	

	imPuppyWarped.FillColor(0);

	Matrix matTrans1(2,3), matTrans2(2,3), matTrans3(2,3), matTrans4(2,3), matTrans5(2,3), matTrans6(2,3), matTrans7(2,3), matTrans8(2,3);
	//Triangle_1
	matTrans1.SetElement(0,0, -0.50);
	matTrans1.SetElement(0,1, 1.00);
	matTrans1.SetElement(0,2, 1.00);
	matTrans1.SetElement(1,0, -0.50);
	matTrans1.SetElement(1,1, 0.00);
	matTrans1.SetElement(1,2, 2.00);

	//Triangle_2
	matTrans2.SetElement(0,0, 0.50);
	matTrans2.SetElement(0,1, 1.00);
	matTrans2.SetElement(0,2, -1.00);
	matTrans2.SetElement(1,0, -0.50);
	matTrans2.SetElement(1,1, 0.00);
	matTrans2.SetElement(1,2, 2.00);

	//Triangle_3
	matTrans3.SetElement(0,0, -0.50);
	matTrans3.SetElement(0,1, 2.00);
	matTrans3.SetElement(0,2, 0.00);
	matTrans3.SetElement(1,0, 0.50);
	matTrans3.SetElement(1,1, -1.00);
	matTrans3.SetElement(1,2, 1.00);

	//Triangle_4
	matTrans4.SetElement(0,0, -0.50);
	matTrans4.SetElement(0,1, 2.00);
	matTrans4.SetElement(0,2, 0.00);
	matTrans4.SetElement(1,0, -0.50);
	matTrans4.SetElement(1,1, 1.00);
	matTrans4.SetElement(1,2, 1.00);

	//Triangle_5
	matTrans5.SetElement(0,0, -0.50);
	matTrans5.SetElement(0,1, 1.00);
	matTrans5.SetElement(0,2, 1.00);
	matTrans5.SetElement(1,0, -0.50);
	matTrans5.SetElement(1,1, 0.00);
	matTrans5.SetElement(1,2, 2.00);

	//Triangle_6
	matTrans6.SetElement(0,0, 0.50);
	matTrans6.SetElement(0,1, 1.00);
	matTrans6.SetElement(0,2, -1.00);
	matTrans6.SetElement(1,0, -0.50);
	matTrans6.SetElement(1,1, 0.00);
	matTrans6.SetElement(1,2, 2.00);

	//Triangle_7
	matTrans7.SetElement(0,0, -0.50);
	matTrans7.SetElement(0,1, 2.00);
	matTrans7.SetElement(0,2, 0.00);
	matTrans7.SetElement(1,0, 0.50);
	matTrans7.SetElement(1,1, -1.00);
	matTrans7.SetElement(1,2, 1.00);

	//Triangle_8
	matTrans8.SetElement(0,0, -0.50);
	matTrans8.SetElement(0,1, 2.00);
	matTrans8.SetElement(0,2, 0.00);
	matTrans8.SetElement(1,0, -0.50);
	matTrans8.SetElement(1,1, 1.00);
	matTrans8.SetElement(1,2, 1.00);

	//Control Points for triangles
	Point ptaT1[3], ptaT2[3], ptaT3[3], ptaT4[3], ptaT5[3], ptaT6[3], ptaT7[3], ptaT8[3];
	ptaT1[0].iX = 0.25;
	ptaT1[0].iY = 0.25;
	ptaT1[1].iX = 0.00;
	ptaT1[1].iY = 0.50;
	ptaT1[2].iX = 0.50;
	ptaT1[2].iY = 0.50;

	ptaT2[0].iX = 0.00;
	ptaT2[0].iY = 0.50;
	ptaT2[1].iX = 0.25;
	ptaT2[1].iY = 0.75;
	ptaT2[2].iX = 0.50;
	ptaT2[2].iY = 0.50;

	ptaT3[0].iX = 0.50;
	ptaT3[0].iY = 0.50;
	ptaT3[1].iX = 0.25;
	ptaT3[1].iY = 0.75;
	ptaT3[2].iX = 0.50;
	ptaT3[2].iY = 1.00;

	ptaT4[0].iX = 0.50;
	ptaT4[0].iY = 0.50;
	ptaT4[1].iX = 0.50;
	ptaT4[1].iY = 1.00;
	ptaT4[2].iX = 0.75;
	ptaT4[2].iY = 0.75;

	ptaT5[0].iX = 0.50;
	ptaT5[0].iY = 0.50;
	ptaT5[1].iX = 0.75;
	ptaT5[1].iY = 0.75;
	ptaT5[2].iX = 1.00;
	ptaT5[2].iY = 0.50;

	ptaT6[0].iX = 0.75;
	ptaT6[0].iY = 0.25;
	ptaT6[1].iX = 0.50;
	ptaT6[1].iY = 0.50;
	ptaT6[2].iX = 1.00;
	ptaT6[2].iY = 0.50;

	ptaT7[0].iX = 0.50;
	ptaT7[0].iY = 0.00;
	ptaT7[1].iX = 0.50;
	ptaT7[1].iY = 0.50;
	ptaT7[2].iX = 0.75;
	ptaT7[2].iY = 0.25;

	ptaT8[0].iX = 0.50;
	ptaT8[0].iY = 0.00;
	ptaT8[1].iX = 0.25;
	ptaT8[1].iY = 0.25;
	ptaT8[2].iX = 0.50;
	ptaT8[2].iY = 0.50;


	iRows = 499;
	iCols = 499;

	for(int i = 0;i<iRows;i++)
	{
		for(int j = 0;j<iCols;j++)
		{
			double dU = (double)(i)/499.00;
			double dV = (double)(j)/499.00;
			Point ptP(dU,dV);			
									
			if(ptP.LiesWithinTriangle(ptaT1))
			{
				//Check for Triangle_1
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(matTrans1,matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imPuppy.GetPixel(dX*iRows,dY*iCols);
				imPuppyWarped.SetPixel(i,j,*pxP);
				imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaT2))
			{
				//Check for Triangle_2
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(matTrans2,matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imPuppy.GetPixel(dX*iRows,dY*iCols);
				imPuppyWarped.SetPixel(i,j,*pxP);
				imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaT3))
			{
				//Check for Triangle_3
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(matTrans3,matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imPuppy.GetPixel(dX*iRows,dY*iCols);
				imPuppyWarped.SetPixel(i,j,*pxP);
				imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaT4))
			{
				//Check for Triangle_4
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(matTrans4,matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imPuppy.GetPixel(dX*iRows,dY*iCols);
				imPuppyWarped.SetPixel(i,j,*pxP);
				imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaT5))
			{
				//Check for Triangle_5
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(matTrans5,matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imPuppy.GetPixel(dX*iRows,dY*iCols);
				imPuppyWarped.SetPixel(i,j,*pxP);
				imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaT6))
			{
				//Check for Triangle_6
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(matTrans6,matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imPuppy.GetPixel(dX*iRows,dY*iCols);
				imPuppyWarped.SetPixel(i,j,*pxP);
				imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaT7))
			{
				//Check for Triangle_7
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(matTrans7,matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imPuppy.GetPixel(dX*iRows,dY*iCols);
				imPuppyWarped.SetPixel(i,j,*pxP);
				imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaT8))
			{
				//Check for Triangle_8
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(matTrans8,matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imPuppy.GetPixel(dX*iRows,dY*iCols);
				imPuppyWarped.SetPixel(i,j,*pxP);
				imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else
			{
				//Pixel pxPB(0);
				//
				//imPuppyWarped.SetPixel(i,j,pxPB);
				//imTestImgae_1_Warped.SetPixel(i,j,pxPB);
			}
		}
	}

	imPuppyWarped.WriteImageData();
	imTestImgae_1_Warped.WriteImageData();

	cout<<"\nPress 'C' to continue";
	getch();	
}

void Problem_1_A_b()
{
	Image imPuppy, imPuppyWarped, imTestImage_1, imTestImgae_1_Warped;
	string strImageNames[4] = {"puppy.raw","puppy_warped.raw","test_1.raw","test_1_warped.raw"};
	int iRows, iCols;
	int iColorFormat;

	iRows = 500;
	iCols = 500;
	iColorFormat = 3;

	//Perform Warping on Puppy.raw
	InitImage(&imPuppy,strImageNames[0],iRows,iCols,iColorFormat);
	InitImage(&imPuppyWarped,strImageNames[1],iRows,iCols,iColorFormat);
	InitImage(&imTestImage_1,strImageNames[2],iRows,iCols,iColorFormat);
	InitImage(&imTestImgae_1_Warped,strImageNames[3],iRows,iCols,iColorFormat);

	imPuppy.ReadImageData();
	imTestImage_1.ReadImageData();

	Pixel pxPB(0);
	for(int i = 0;i<iRows;i++)
	{
		for(int j = 0;j<iCols;j++)
		{
			imPuppyWarped.SetPixel(i,j,pxPB);
			imTestImgae_1_Warped.SetPixel(i,j,pxPB);
		}
	}
}

void Problem_1_B()
{
	Image imCowboy, imCowboyWarped;
	string strNames[2]  = {"cowboy.raw","cowboy_warped.raw"};
	int iRows = 500, iCols = 500;

	InitImage(&imCowboy,strNames[0],iRows,iCols,3);
	InitImage(&imCowboyWarped,strNames[1],iRows,iCols,3);

	imCowboy.ReadImageData();
	imCowboyWarped.FillColor(0);	

	//Transition Matrix
	Matrix *matTransUX[7], *matTransUX_inv[7], *pMatTran[7];
	//Control Points
	Point p1(0.498,0.498);
	Point p2(0.00,0.498);
	Point p3(0.173,0.738);
	Point p4(p1);
	Point p5(p3);
	Point p6(0.3632,1.00);
	Point p7(p1);
	Point p8(p6);
	Point p9(0.995,0.794);
	Point p10(p1);
	Point p11(p9);
	Point p12(0.995,0.206);
	Point p13(p1);
	Point p14(p12);
	Point p15(0.3632,0.00);
	Point p16(p1);
	Point p17(p15);
	Point p18(0.173,0.2625);
	Point p19(p1);
	Point p20(p18);
	Point p21(p2);
	
	Point pp1(0.5,0.5);
	Point pp2(0.00,0.50);
	Point pp3(0,1);
	Point pp4(pp1);
	Point pp5(pp3);
	Point pp6(0.346,1);
	Point pp7(pp1);
	Point pp8(pp6);
	Point pp9(1,1);
	Point pp10(pp1);
	Point pp11(pp9);
	Point pp12(1,0);
	Point pp13(pp1);
	Point pp14(pp12);
	Point pp15(0.346,0);
	Point pp16(pp1);
	Point pp17(pp15);
	Point pp18(0,0);
	Point pp19(pp1);
	Point pp20(pp18);
	Point pp21(pp2);

	Point ptaOp[7][3] = {{p1,p2,p3},{p4,p5,p6},{p7,p8,p9},{p10,p11,p12},{p13,p14,p15},{p16,p17,p18},{p19,p20,p21}};
	Point ptaIp[7][3] = {{pp1,pp2,pp3},{pp4,pp5,pp6},{pp7,pp8,pp9},{pp10,pp11,pp12},{pp13,pp14,pp15},{pp16,pp17,pp18},{pp19,pp20,pp21}};

	for(int i = 0;i<7;i++)
	{
		Matrix matU(3,1), matV(3,1);
		Matrix matX(3,1), matY(3,1);
		
		double dU[3] = {ptaOp[i][0].iX, ptaOp[i][1].iX, ptaOp[i][2].iX};//{0.173,0.00,0.500};
		double dV[3] = {ptaOp[i][0].iY, ptaOp[i][1].iY, ptaOp[i][2].iY};//{0.2625,0.500,0.500};
		double dX[3] = {ptaIp[i][0].iX, ptaIp[i][1].iX, ptaIp[i][2].iX};//{0.00,0.00,0.500};
		double dY[3] = {ptaIp[i][0].iY, ptaIp[i][1].iY, ptaIp[i][2].iY};//{0.00,0.50,0.500};
		
		matU.SetElements(dU);	
		matV.SetElements(dV);
		matX.SetElements(dX);
		matY.SetElements(dY);
		
		matTransUX[i] = Matrix::FindMatrixA(matU,matV,1);
		matTransUX_inv[i] = matTransUX[i]->InverseMatrix();

		Matrix *pmatA, *pmatB;

		pmatA = Matrix::MatrixMultiply(*matTransUX_inv[i],matX);
		pmatB = Matrix::MatrixMultiply(*matTransUX_inv[i],matY);

		pMatTran[i] = Matrix::MergeByRow(*pmatA->MatrixTranspose(),*pmatB->MatrixTranspose());

		delete pmatA;
		delete pmatB;
	}

	iRows = 499;
	iCols = 499;

	for(int i = 0;i<iRows;i++)
	{
		for(int j = 0;j<iCols;j++)
		{
			double dU = (double)(i)/499.00;
			double dV = (double)(j)/499.00;
			Point ptP(dU,dV);			
									
			if(ptP.LiesWithinTriangle(ptaOp[0]))
			{
				//Check for Triangle_1
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(*pMatTran[0],matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imCowboy.GetPixel(dX*iRows,dY*iCols);
				imCowboyWarped.SetPixel(i,j,*pxP);
				//imTestImgae_1_Warped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaOp[1]))
			{
				//Check for Triangle_2
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(*pMatTran[1],matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imCowboy.GetPixel(dX*iRows,dY*iCols);
				imCowboyWarped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaOp[2]))
			{
				//Check for Triangle_3
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(*pMatTran[2],matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imCowboy.GetPixel(dX*iRows,dY*iCols);
				imCowboyWarped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaOp[3]))
			{
				//Check for Triangle_4
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(*pMatTran[3],matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imCowboy.GetPixel(dX*iRows,dY*iCols);
				imCowboyWarped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaOp[4]))
			{
				//Check for Triangle_5
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(*pMatTran[4],matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imCowboy.GetPixel(dX*iRows,dY*iCols);
				imCowboyWarped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaOp[5]))
			{
				//Check for Triangle_6
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(*pMatTran[5],matOp);
				
				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imCowboy.GetPixel(dX*iRows,dY*iCols);
				imCowboyWarped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
			else if(ptP.LiesWithinTriangle(ptaOp[6]))
			{
				//Check for Triangle_7
				Matrix *pmatIp;
				Matrix matOp(3,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(*pMatTran[6],matOp);	

				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imCowboy.GetPixel(dX*iRows,dY*iCols);
				imCowboyWarped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
		}

	}

	imCowboyWarped.WriteImageData();

	cout<<"\nPress 'C' to continue";
	getch();	
}

void Problem_1_C()
{
	Image imTransformer, imTransformerWarped;
	int iRows = 500, iCols = 500;
	string strNames[2] = {"transformmer.raw","transformer_warped.raw"};

	InitImage(&imTransformer,strNames[0],iRows,iCols,3);
	InitImage(&imTransformerWarped,strNames[1],iRows,iCols,3);
	
	imTransformer.ReadImageData();
	imTransformerWarped.FillColor(0);

	//Quadrant 1
	//Forward Method
	//for(int i = 0;i<500;i++)
	//{
	//	for(int j = 0;j<500;j++)
	//	{
	//		Point ptP((double)i/499,(double)j/499);
	//		ptP.Cart2Pol(0.499,0.499);
	//		
	//		double dOpRad = 0.499;
	//		double dIpRad = ptP.FindDistanceFromSq();			
	//		double dScaleFactor = 0.499/dIpRad;
	//		
	//		Point ptPOut;
	//		ptPOut.iRad = dScaleFactor*ptP.iRad;
	//		ptPOut.iTheta = ptP.iTheta;
	//
	//		ptPOut.Pol2Cart(0.499,0.499);
	//
	//		if(ptPOut.iRad > 0.500)
	//			continue;
	//		//cout<<"\ni: "<<i<<"  j: "<<j;
	//		imTransformerWarped.SetPixel(ptPOut.iX*499,ptPOut.iY*499,*imTransformer.GetPixel(i,j));
	//	}
	//}

	//Reverse Method
	for(double i = 0;i<0.5;i +=0.002)
	{
		for(double d = 0;d<360.00;d += 0.1)
		{
			Point ptP;
			ptP.iRad = i;
			ptP.iTheta = d;
			ptP.Pol2Cart(0.5,0.5);
	
			double dOpRad = 0.5;
			double dIpRad = ptP.FindDistanceFromSq();
			double dScaleFactor = dOpRad/dIpRad;
	
			Point ptPIP;
			ptPIP.iRad = (1/dScaleFactor)*i;
			ptPIP.iTheta = ptP.iTheta;
			ptPIP.Pol2Cart(0.5,0.5);
			
			imTransformerWarped.SetPixel(ptP.iX*499,ptP.iY*499,*imTransformer.GetPixel(ptPIP.iX*499,ptPIP.iY*499));
		}
	}

	imTransformerWarped.WriteImageData();
	
	cout<<"\nPress 'C' to continue";
	getch();	
}

void Problem_1_C_a()
{
	Image imTransformer, imTransformerWarped;
	int iRows = 500, iCols = 500;
	string strNames[2] = {"transformmer.raw","transformer_warped.raw"};

	InitImage(&imTransformer,strNames[0],iRows,iCols,3);
	InitImage(&imTransformerWarped,strNames[1],iRows,iCols,3);
	
	imTransformer.ReadImageData();
	imTransformerWarped.FillColor(0);
	
	Matrix *pmatUX[4], *pmatUX_inv[4], *pmatXU[4], *pmatTrans[4];

	Point ptO1(0.5,0.5);
	Point ptO2(0.5,0.0);
	Point ptO3(0.3086,0.0386);
	Point ptO4(0.0,0.0);
	Point ptO5(0.0386,0.3086);
	Point ptO6(0.0,0.5);

	Point ptI1(0.5,0.5);
	Point ptI2(0.5,0.0);
	Point ptI3(0.25,0.00);
	Point ptI4(0.00,0.00);
	Point ptI5(0.00,0.25);
	Point ptI6(0.0,0.5);

	Point ptaOp[1][6] = {{ptO1,ptO2,ptO3,ptO4,ptO5,ptO6,}};
	Point ptaIp[1][6] = {{ptI1,ptI2,ptI3,ptI4,ptI5,ptI6,}};
		
	for(int i = 0;i<1;i++)
	{
		Matrix matU(6,1), matV(6,1);
		Matrix matX(6,1), matY(6,1);
		
		double dU[6] = {ptaOp[i][0].iX, ptaOp[i][1].iX, ptaOp[i][2].iX, ptaOp[i][3].iX, ptaOp[i][4].iX, ptaOp[i][5].iX};
		double dV[6] = {ptaOp[i][0].iY, ptaOp[i][1].iY, ptaOp[i][2].iY, ptaOp[i][3].iY, ptaOp[i][4].iY, ptaOp[i][5].iY};
		double dX[6] = {ptaIp[i][0].iX, ptaIp[i][1].iX, ptaIp[i][2].iX, ptaIp[i][3].iX, ptaIp[i][4].iX, ptaIp[i][5].iX};
		double dY[6] = {ptaIp[i][0].iY, ptaIp[i][1].iY, ptaIp[i][2].iY, ptaIp[i][3].iY, ptaIp[i][4].iY, ptaIp[i][5].iY};
		
		matU.SetElements(dU);	
		matV.SetElements(dV);
		matX.SetElements(dX);
		matY.SetElements(dY);
		
		//
		cout<<"\n";
		matX.PrintMatrix();
		cout<<"\n";
		matY.PrintMatrix();

		pmatUX[i] = Matrix::FindMatrixA(matU,matV,2);
		pmatUX_inv[i] = pmatUX[i]->InverseMatrix();
		//
		cout<<"\n";
		pmatUX_inv[i]->PrintMatrix();

		Matrix *pmatA, *pmatB;

		pmatA = Matrix::MatrixMultiply(*pmatUX_inv[i],matX);
		pmatB = Matrix::MatrixMultiply(*pmatUX_inv[i],matY);

		pmatTrans[i] = Matrix::MergeByRow(*pmatA->MatrixTranspose(),*pmatB->MatrixTranspose());
		//
		cout<<"\n";
		pmatTrans[i]->PrintMatrix();
		delete pmatA;
		delete pmatB;
	}

	iRows = 499;
	iCols = 499;

	for(int i = 0;i<iRows;i++)
	{
		for(int j = 0;j<iCols;j++)
		{
			double dU = (double)(i)/499.00;
			double dV = (double)(j)/499.00;
			Point ptP(dU,dV);			
									
			if(ptP.LiesWithinQuarterCircle(0.5,1))
			{
				Matrix *pmatIp;
				Matrix matOp(6,1);
				
				matOp.SetElement(0,0,1.00);
				matOp.SetElement(1,0,ptP.iX);
				matOp.SetElement(2,0,ptP.iY);
				matOp.SetElement(3,0,ptP.iX*ptP.iX);
				matOp.SetElement(4,0,ptP.iX*ptP.iY);
				matOp.SetElement(5,0,ptP.iY*ptP.iY);
				
				pmatIp = Matrix::MatrixMultiply(*pmatTrans[0],matOp);	

				double dX = pmatIp->GetElement(0,0);
				double dY = pmatIp->GetElement(1,0);

				Pixel *pxP = imTransformer.GetPixel(dX*iRows,dY*iCols);
				imTransformerWarped.SetPixel(i,j,*pxP);

				delete pxP;
				delete pmatIp;
			}
		}
	}
	
	imTransformerWarped.WriteImageData();

	//double dScaleFac = 0, dRad = 250;

	//Quadrant 1
	//for(int i = 0;i<250;i++)
	//{
	//	dScaleFac = sin(3.14159/180*90/250*i);
	//	cout<<"\nScale Factor: "<<dScaleFac*250;
	//	for(int j = 0;j<250;j++)
	//	{
	//	
	//	}
	//}
	

	cout<<"\nPress 'C' to continue";
	getch();	
}

/// Matrix Inversion Code Taken from http://chi3x10.wordpress.com/2008/05/28/calculate-matrix-inversion-in-c/
//   Author: Yu-Tseh Jason Chi
/// matrix inversioon

// the result is put in Y
void MatrixInversion(double **A, int order, double **Y)
{
    // get the determinant of a
    double det = 1.0/CalcDeterminant(A,order);
 
    // memory allocation
    double *temp = new double[(order-1)*(order-1)];
    double **minor = new double*[order-1];
    for(int i=0;i<order-1;i++)
        minor[i] = temp+(i*(order-1));
 
    for(int j=0;j<order;j++)
    {
        for(int i=0;i<order;i++)
        {
            // get the co-factor (matrix) of A(j,i)
            GetMinor(A,minor,j,i,order);
            Y[i][j] = det*CalcDeterminant(minor,order-1);
            if( (i+j)%2 == 1)
                Y[i][j] = -Y[i][j];
        }
    }
 
    // release memory
    //delete [] minor[0];
    delete [] temp;
    delete [] minor;
}
 
// calculate the cofactor of element (row,col)
int GetMinor(double **src, double **dest, int row, int col, int order)
{
    // indicate which col and row is being copied to dest
    int colCount=0,rowCount=0;
 
    for(int i = 0; i < order; i++ )
    {
        if( i != row )
        {
            colCount = 0;
            for(int j = 0; j < order; j++ )
            {
                // when j is not the element
                if( j != col )
                {
                    dest[rowCount][colCount] = src[i][j];
                    colCount++;
                }
            }
            rowCount++;
        }
    }
 
    return 1;
}
 
// Calculate the determinant recursively.
double CalcDeterminant( double **mat, int order)
{
    // order must be >= 0
    // stop the recursion when matrix is a single element
    if( order == 1 )
        return mat[0][0];
 
    // the determinant value
    double det = 0;
 
    // allocate the cofactor matrix
    double **minor;
    minor = new double*[order-1];
    for(int i=0;i<order-1;i++)
        minor[i] = new double[order-1];
 
    for(int i = 0; i < order; i++ )
    {
        // get minor of element (0,i)
        GetMinor( mat, minor, 0, i , order);
        // the recusion is here!
 
        det += (i%2==1?-1.0:1.0) * mat[0][i] * CalcDeterminant(minor,order-1);       
    }
 
    // release memory
    for(int i=0;i<order-1;i++)
        delete [] minor[i];
    delete [] minor;
 
    return det;
}