#pragma once
#ifndef LEASTSQUAREFITCALCULATOR_H
#define LEASTSQUAREFITCALCULATOR_H

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
		sum_Xsquared, sum_Ysquared,
		sumX_squared, sumY_squared,
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