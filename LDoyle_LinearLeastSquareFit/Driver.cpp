//Luke Doyle
//Program: Linear Least Square Fit Calculator
//Purpose: To create a line of best fit for a collection of data points using summation algorithm
//Date: 10/12/17
#include<conio.h>
#include<iostream>
#include<iomanip>
#include "LeastSquareFitCalculator.h"
using namespace std;
void display(LeastSquareFitCalculator&);
int getValidDataNumber();
//main() dynamically allocates memory for data and creates a LeastSquareFitCalculator object
void main()
{
	char cont;

	//create a menu option in case the user wishes to calculate multiple lines of best fit
	do
	{
		cout << "Would you like to calculate a Linear Least Square Fit[y/n]? ";
		cin >> cont;
		if (tolower(cont) == 'y')
		{
			int num;
			double *dataX, *dataY;	//pointers for dynamic memory allocation

			cout << "\nHow many data points do you have? ";
			num = getValidDataNumber();	//Validate user input: positive integers only!
			dataX = new double[num];	//Create arrays of the proper size
			dataY = new double[num];

			//Get data points: first x then y coordinates
			cout << "\n\nEnter x coordinates:\n";
			for (int i = 0; i < num; i++)
				cin >> dataX[i];

			cout << "\n\nEnter y coordinates:\n";
			for (int i = 0; i < num; i++)
				cin >> dataY[i];

			//Create a LeastSquareFitCalculator object initialized with the proper data
			LeastSquareFitCalculator sqFit(num, dataX, dataY);
			display(sqFit);	//display the results

			delete[] dataX;	//delete dynamically allocated memory
			delete[] dataY;
		}
	} while (tolower(cont) == 'y');
}

//getValidDataNumber() makes sure the user inputs an appropriate value for the number of data points
int getValidDataNumber()
{
	int numDataPoints;

	cin >> numDataPoints;	//get a value from the user
	//if the user's value is not appropriate print error message and get a valid input
	while (cin.fail() || !(numDataPoints > 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Your did not enter a proper number of data points\nPlease try again: ";
		cin >> numDataPoints;
	}

	return numDataPoints;
}

//display() prints the results of the calculations: slope, y-intercept, regression value, and line equation
void display(LeastSquareFitCalculator& sF)
{
	cout << "\nYour y intercept is: " << setw(8) << setprecision(7) << sF.getYIntercept()
		<< "\nYour slope is: " << sF.getSlope()
		<< "\nYour regression: " << sF.getCorrelation_r()
		<< "\n\nThe equation is: y = " << sF.getSlope() << "x ";
	if (sF.getYIntercept() < 0)
		cout << "- ";
	else
		cout << "+ ";
	cout << abs(sF.getYIntercept())
		<< endl << endl << endl;
}