#include<cmath>
#include "LeastSquareFitCalculator.h"

//Constructor initializes all data members
LeastSquareFitCalculator::LeastSquareFitCalculator(int n, double* x, double* y) :
	num(n), sumX(sumsCalculator(x)), sumY(sumsCalculator(y)), sumXY(dataCombiner(x,y)),
	sum_Xsquared(powerSums(x)), sum_Ysquared(powerSums(y))
	{
		sumX_squared = pow(sumX,2);
		sumY_squared = pow(sumY,2);
		m = calcSlope();
		y_intercept = calcYIntercept();
		correlation_r = calcCorrelation_r();
	}

//getYIntercept() returns the value for the line's y-intercept
double LeastSquareFitCalculator::getYIntercept() const
{
	return y_intercept;
}

//getCorrelation_r() returns the regression value for the data to the line
double LeastSquareFitCalculator::getCorrelation_r() const
{
	return correlation_r;
}

//getSlope() returns the slope of the new line
double LeastSquareFitCalculator::getSlope() const
{
	return m;
}

//dataCombiner(double*,double*) calculates the sum of each x value times each y value
double LeastSquareFitCalculator::dataCombiner(double* x, double* y)
{
	double result = 0.0;
	for (int i = 0; i < num; ++i)
		result += x[i] * y[i];
	return result;
}

//sumsCalculator(double*) calculates the sum of any array of data
double LeastSquareFitCalculator::sumsCalculator(double* data)
{
	double result = 0.0;
	for (int i = 0; i < num; ++i)
		result += data[i];
	return result;
}

//powerSums(double*) calculates the sum of an array of data where each value must be squared
//before being added to the sum
double LeastSquareFitCalculator::powerSums(double* data)
{
	double result = 0.0;
	for (int i = 0; i < num; ++i)
		result += pow(data[i], 2);
	return result;
}

//calcCorrelation_r() calculates the regression value r
double LeastSquareFitCalculator::calcCorrelation_r()
{
	double numerator = num*sumXY - sumX*sumY,
	       denominator = sqrt(abs(num*sum_Xsquared - sumX_squared))*
							sqrt(abs(num*sum_Ysquared - sumY_squared));

	return numerator / denominator;
}

//calcYIntercept() calculates the y-intercept
double LeastSquareFitCalculator::calcYIntercept()
{
	return (sumY - m*sumX) / num;
}

//calcSlope() calculates the slope
double LeastSquareFitCalculator::calcSlope()
{
	double numerator = num*sumXY - sumX*sumY,
	       denominator = num*sum_Xsquared - sumX_squared;

	return numerator / denominator;
}