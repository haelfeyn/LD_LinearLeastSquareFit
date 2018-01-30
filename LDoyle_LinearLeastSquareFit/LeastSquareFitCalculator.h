#pragma once
#ifndef LEASTSQUAREFITCALCULATOR_H
#define LEASTSQUAREFITCALCULATOR_H

//class LeastSquareFitCalculator continues several functions and variables for
//calculating a line of best fit for any number of data points using summation method.
//class was used in order to create an organized template of methods and procedures
class LeastSquareFitCalculator
{
public:
	LeastSquareFitCalculator(int, double*, double*);
	double getYIntercept(void);
	double getCorrelation_r(void);
	double getSlope(void);
private:
	int n;
	double sumX, sumY,
		sumXY,
		sum_Xsquared, sum_Ysquared,	//these are the sums where each value must be squared
		sumX_squared, sumY_squared,	//these are the sums where the sum itself is squared
		correlation_r, m, y_intercept;
	double sumsCalculator(double*);
	double powerSums(double*);
	double dataCombiner(double*, double*);
	void calcCorrelation_r(void);
	void calcYIntercept(void);
	void calcSlope(void);
};

#include "LeastSquareFitCalculator.cpp"
#endif