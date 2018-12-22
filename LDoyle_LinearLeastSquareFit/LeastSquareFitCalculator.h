#ifndef LEASTSQUAREFITCALCULATOR_H
#define LEASTSQUAREFITCALCULATOR_H

//class LeastSquareFitCalculator contains several functions and variables for
//calculating a line of best fit for any number of data points using summation method.
//class was used in order to create an organized framework of methods and procedures
class LeastSquareFitCalculator
{
public:
	LeastSquareFitCalculator(int, double*, double*);
	double getYIntercept() const;
	double getCorrelation_r() const;
	double getSlope() const;
private:
	int num;
	double sumX, sumY,
		sumXY,
		sum_Xsquared, sum_Ysquared,	//these are the sums where each value must be squared
		sumX_squared, sumY_squared,	//these are the sums where the sum itself is squared
		correlation_r, m, y_intercept;
	double sumsCalculator(double*);
	double powerSums(double*);
	double dataCombiner(double*, double*);
	double calcCorrelation_r();
	double calcYIntercept();
	double calcSlope();
};

#endif