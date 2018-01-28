//Luke Doyle
//Program: Linear Least Square Fit Calculator
//Purpose: To create a line of best fit for a collection of data points
//Date: 10/12/17
#include<conio.h>
#include<iostream>
#include<iomanip>
#include "LeastSquareFitCalculator.h"
using namespace std;
void display(LeastSquareFitCalculator&);
void main()
{
	char cont;
	int num;
	double *dataX, *dataY;

	do
	{
		cout << "\nWould you like to calculate a Linear Least Square Fit[y/n]? ";
		cin >> cont;
		if (tolower(cont) == 'y')
		{
			cout << "\nHow many data points do you have? ";
			cin >> num;
			dataX = new double[num];
			dataY = new double[num];
			cout << "\n\n\nEnter x coordinates:\n";
			for (int i = 0; i < num; i++)
				cin >> dataX[i];

			cout << "\n\n\nEnter y coordinates:\n";
			for (int i = 0; i < num; i++)
				cin >> dataY[i];

			LeastSquareFitCalculator sqFit(num, dataX, dataY);
			display(sqFit);

			delete[] dataX;
			delete[] dataY;
		}
	} while (tolower(cont) == 'y');
}

void display(LeastSquareFitCalculator& sF)
{
	cout << "\nYour y intercept is: " << setw(8) << setprecision(6) << sF.getYIntercept()
		<< "\nYour slope is: " << sF.getSlope()
		<< "\nYour regression: " << sF.getCorrelation_r()
		<< "\n\nThe equation is: y = " << sF.getSlope() << "x + " << sF.getYIntercept();
}