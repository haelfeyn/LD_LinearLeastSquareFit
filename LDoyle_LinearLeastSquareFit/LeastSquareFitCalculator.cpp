#ifdef LEASTSQUAREFITCALCULATOR_H
#include<cmath>
#include "LeastSquareFitCalculator.h"

//Constructor initializes all variables important for calculating slope, intercept, and regression
LeastSquareFitCalculator::LeastSquareFitCalculator(int num, double* x, double* y)
{
	n = num;
	sumX = sumsCalculator(x);
	sumY = sumsCalculator(y);
	sumXY = dataCombiner(x, y);
	sum_Xsquared = powerSums(x);
	sum_Ysquared = powerSums(y);
	sumX_squared = pow(sumX, 2);
	sumY_squared = pow(sumY, 2);

	calcSlope();
	calcYIntercept();
	calcCorrelation_r();
}

//getYIntercept() returns the value for the line's y-intercept
double LeastSquareFitCalculator::getYIntercept(void)
{
	return y_intercept;
}

//getCorrelation_r() returns the regression value for the data to the line
double LeastSquareFitCalculator::getCorrelation_r(void)
{
	return correlation_r;
}

//getSlope() returns the slope of the new line
double LeastSquareFitCalculator::getSlope(void)
{
	return m;
}

//dataCombiner(double*,double*) calculates the sum of each x value times each y value
double LeastSquareFitCalculator::dataCombiner(double* x, double* y)
{
	double result = 0.0;
	for (int i = 0;i <= n;i++)
		result += (x[i] * y[i]);
	return result;
}

//sumsCalculator(double*) calculates the sum of any array of data
double LeastSquareFitCalculator::sumsCalculator(double* data)
{
	double result = 0.0;
	for (int i = 0; i < n; i++)
		result += data[i];
	return result;
}

//powerSums(double*) calculates the sum of an array of data where each value must be squared
//before being added to the sum
double LeastSquareFitCalculator::powerSums(double* data)
{
	double result=0.0;
	for (int i = 0; i < n; i++)
		result += pow(data[i], 2);
	return result;
}

//calcCorrelation_r() calculates the regression value r
void LeastSquareFitCalculator::calcCorrelation_r(void)
{
	double numerator, denominator;

	numerator = n*sumXY - sumX*sumY;
	denominator = sqrt(abs(n*sum_Xsquared - sumX_squared))*sqrt(abs(n*sum_Ysquared - sumY_squared));

	correlation_r = numerator / denominator;
}

//calcYIntercept() calculates the y-intercept
void LeastSquareFitCalculator::calcYIntercept(void)
{
	y_intercept = (sumY - m*sumX) / n;
}

//calcSlope() calculates the slope
void LeastSquareFitCalculator::calcSlope(void)
{
	double numerator, denominator;

	numerator = n*sumXY - sumX*sumY;
	denominator = n*sum_Xsquared - sumX_squared;

	m = numerator / denominator;
}
#endif