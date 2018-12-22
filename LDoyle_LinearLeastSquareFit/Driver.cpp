//Luke Doyle
//Program: Linear Least Square Fit Calculator
//Purpose: To create a line of best fit for a collection of data points using summation algorithm
//V2.0
//Date: 12/22/18
#include<iostream>
#include<iomanip>
using namespace std;
#include "LeastSquareFitCalculator.h"
void display(const LeastSquareFitCalculator&);
int validateUserChoice();
void getInfo_menu();
void create_newArrays(double*&, double*&, int);
void retreive_DataPoints(double*&, double*&, int);
void delete_Data(double*&, double*&);

//main() display a menu for user input
int main()
{
	getInfo_menu();
	return 0;
}

//getValidDataNumber() makes sure the user inputs an appropriate value for the number of data points
int validateUserChoice()
{
	int numDataPoints;

	cin >> numDataPoints;
	//if the user's value is not appropriate, print error message and get a valid input
	while (cin.fail() || numDataPoints <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "You did not enter a proper number of data points\nPlease try again: ";
		cin >> numDataPoints;
	}

	return numDataPoints;
}

//display() prints the results of the calculations: slope, y-intercept, regression value, and line equation
void display(const LeastSquareFitCalculator& sF)
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

//getInfo_menu() creates a loop to allow for user input, and retrieves data
void getInfo_menu()
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
			double *dataX = nullptr, *dataY = nullptr;	//pointers for dynamic memory allocation

			cout << "\nHow many data points do you have? ";
			num = validateUserChoice();	//Validate user input: positive integers only!
			
			//Create arrays of the proper size
			create_newArrays(dataX,dataY,num);
			
			//Get data points
			retreive_DataPoints(dataX,dataY,num);

			//Create a LeastSquareFitCalculator object initialized with the proper data
			display(LeastSquareFitCalculator(num, dataX, dataY));	//display the results

			//delete dynamically allocated memory
			delete_Data(dataX, dataY);
		}
	} while (tolower(cont) == 'y');
}

//create_newArrays() dynamically allocates new storage for the data arrays
void create_newArrays(double*& dX, double*& dY, int num)
{
	dX = new double[num];
	dY = new double[num];
}

//retreive_DataPoints() fills the arrays with data points from the user
void retreive_DataPoints(double*& dX, double*& dY, int num)
{
	cout << "\n\nEnter x coordinates:\n";
	for (int i = 0; i < num; ++i)
		cin >> dX[i];

	cout << "\n\nEnter y coordinates:\n";
	for (int i = 0; i < num; ++i)
		cin >> dY[i];
}

void delete_Data(double*& dX, double*& dY)
{
	delete[] dX;
	delete[] dY;
}