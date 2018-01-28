#ifdef LEASTSQUAREFITCALCULATOR_H
#include<cmath>
#include "LeastSquareFitCalculator.h"

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

double LeastSquareFitCalculator::getYIntercept(void)
{
	return y_intercept;
}

double LeastSquareFitCalculator::getCorrelation_r(void)
{
	return correlation_r;
}

double LeastSquareFitCalculator::getSlope(void)
{
	return m;
}

double LeastSquareFitCalculator::dataCombiner(double* x, double* y)
{
	double result = 0.0;
	for (int i = 0;i <= n;i++)
		result += (x[i] * y[i]);
	return result;
}

double LeastSquareFitCalculator::sumsCalculator(double* data)
{
	double result = 0.0;
	for (int i = 0; i < n; i++)
		result += data[i];
	return result;
}

double LeastSquareFitCalculator::powerSums(double* data)
{
	double result=0.0;
	for (int i = 0; i < n; i++)
		result += pow(data[i], 2);
	return result;
}

void LeastSquareFitCalculator::calcCorrelation_r(void)
{
	double numerator, denominator;

	numerator = n*sumXY - sumX*sumY;
	denominator = sqrt(n*sum_Xsquared - sumX_squared)*sqrt(n*sum_Ysquared - sumY_squared);

	correlation_r = numerator / denominator;
}

void LeastSquareFitCalculator::calcYIntercept(void)
{
	y_intercept = (sumY - m*sumX) / n;
}

void LeastSquareFitCalculator::calcSlope(void)
{
	double numerator, denominator;

	numerator = n*sumXY - sumX*sumY;
	denominator = n*sum_Xsquared - sumX_squared;

	m = numerator / denominator;
}
#endif