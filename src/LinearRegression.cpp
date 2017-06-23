#include "LinearRegression.h"

namespace Ccd
{
namespace Math
{

void LinearRegression::addPoint ( double x, double y )
{
	xValues.push_back ( x );
	yValues.push_back ( y );
}

void LinearRegression::setXList ( std::vector<double> xValuesNew )
{
	xValues = xValuesNew;
}

void LinearRegression::setYList ( std::vector<double> yValuesNew )
{
	yValues = yValuesNew;
}

void LinearRegression::setXList ( Ccd::Json::Value& xList )
{
	xValues.clear();
	for ( auto xItem : xList.toArray() ) {
		if ( xItem.type() == Ccd::Json::ValueType::Int )
			xValues.push_back ( xItem.toInt() );
		else if ( xItem.type() == Ccd::Json::ValueType::Double )
			xValues.push_back ( xItem.toDouble() );
	}
}

void LinearRegression::setYList ( Ccd::Json::Value& yList )
{
	yValues.clear();
	for ( auto yItem : yList.toArray() ) {
		if ( yItem.type() == Ccd::Json::ValueType::Int )
			yValues.push_back ( yItem.toInt() );
		else if ( yItem.type() == Ccd::Json::ValueType::Double )
			yValues.push_back ( yItem.toDouble() );
	}
}

LinearFunktion LinearRegression::compute()
{
	int values = 0;		// count of values
	double xSum = 0;	// sum of all x values
	double ySum = 0;	// sum of all y vales
	double xMean = 0.0;	// mean of x vales
	double yMean = 0.0;	// mean of y vales
	double num = 0.0; 	// numerator
	double den = 0.0;	// denumerator divisor divider
	
	if ( xValues.size() != yValues.size() ){
		throw ("X and Y value count is diffrent");
	}
	
	values = xValues.size();
	
	for ( int i = 0; i < values; i++) {
		xSum += xValues[i];
		ySum += yValues[i];
	}
	xMean = static_cast<double>(xSum / values);
	yMean = static_cast<double>(ySum / values);
	
	for ( int i = 0; i < values; i ++) {
		double x = xValues[i];
		double y = yValues[i];
		
		num += static_cast<double>((x - xMean) * (y - yMean));
		den += static_cast<double>((x - xMean) * (x - xMean));
	}
	
	if ( 0 == den ) {
		throw ( "Dividing by 0" );
	}
	
	double slope = num / den;
	double yIntersect = yMean - (slope * xMean);
	
	return LinearFunktion (slope, yIntersect);
}

void LinearRegression::clear()
{
	xValues.clear();
	yValues.clear();
}


};
};
