#pragma once

#include "LinearFunction.h"

#include <vector>

#include <JsonPP.h>

namespace Ccd
{
namespace Math
{


class LinearRegression
{
public:
	LinearRegression() = default;

	/* Methods for filling the data vectors */
	void addPoint ( double x, double y );

	void setXList ( std::vector<double> xList );
	void setYList ( std::vector<double> yList );

	void setXList ( Ccd::Json::Value& xList );
	void setYList ( Ccd::Json::Value& yList );

	/* Compute method. Call if data is ready. */
	LinearFunktion compute();

	/* Clear before computing next data set */
	void clear();

private:
	/* Store data vales */
	std::vector<double> xValues;
	std::vector<double> yValues;
	// store data points in std::vector<pair<double,double>> later on
};

}
}
