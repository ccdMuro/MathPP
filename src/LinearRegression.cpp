#include "LinearRegression.h"

namespace Ccd
{
namespace Math
{

LinearRegression::LinearRegression() :
	__a ( 0.0 ),
	__b ( 0.0 )
{
	xi.clear(); //QList<double>
	xi2.clear(); //QList<double>
	yi.clear(); //QList<double>
	xiyi.clear(); //QList<double>
	n_items = 0; //int
	math_done = false;
}

LinearRegression::~LinearRegression()
{
}

void LinearRegression::addPoint ( double _x, double _y )
{
	xi.push_back ( _x );
	yi.push_back ( _y );
	n_items++;
}

void LinearRegression::clear()
{
	xi.clear();
	xi2.clear();
	yi.clear();
	xiyi.clear();
	n_items = 0;
	math_done = false;
}

bool LinearRegression::doTheMath()
{
	int idx = 0;
	double xi_sum = 0.0;
	double yi_sum = 0.0;
	double xi_average = 0.0;
	double yi_average = 0.0;
	double xi_minus_xa_multi_yi_ya = 0.0;
	double xi_minus_xa_2_sum = 0.0;
	if ( ( xi.size() != yi.size() ) || ( xi.size() != n_items ) )
		return false;
	for ( auto xIdx : xi ) {
		xi_sum += xIdx;
	}
	xi_average = xi_sum / n_items;
	for ( auto y : yi ) {
		yi_sum += y;
	}
	yi_average = yi_sum / n_items;
	for ( idx = 0; idx < n_items; idx++ ) {
		double xi_minus_xa = xi.at ( idx ) - xi_average;
		double yi_minus_ya = yi.at ( idx ) - yi_average;
		xi_minus_xa_multi_yi_ya += xi_minus_xa *yi_minus_ya;
		xi_minus_xa_2_sum += xi_minus_xa * xi_minus_xa;
	}
	if ( xi_minus_xa_2_sum != 0 ) {
		__b = xi_minus_xa_multi_yi_ya / xi_minus_xa_2_sum;
		__a = yi_average - __b * xi_average;
	} else {
		__b = 0;
		__a = 0;
	}
	math_done = true;
	return true;
}

double LinearRegression::a()
{
	if ( math_done )
		return __a;
	return 0;
}

double LinearRegression::b()
{
	if ( math_done )
		return __b;
	return 0;
}

double LinearRegression::y ( double _x )
{
	if ( math_done )
		return ( __a + ( _x*__b ) );
	return 0;
}

double LinearRegression::x ( double _y )
{
	if ( math_done )
		return ( ( _y/__b ) - ( __a/__b ) );
	return 0;
}

void LinearRegression::setXList ( std::vector<double> _xi )
{
	xi = _xi;
	n_items = xi.size();
}

void LinearRegression::setYList ( std::vector<double> _yi )
{
	yi = _yi;
	n_items = yi.size();
}

void LinearRegression::setXList ( Ccd::Json::Value& xList )
{
	xi.clear();
	for ( auto xItem : xList.toArray() ) {
		if ( xItem.type() == Ccd::Json::ValueType::Int )
			xi.push_back ( xItem.toInt() );
		else if ( xItem.type() == Ccd::Json::ValueType::Double )
			xi.push_back ( xItem.toDouble() );
	}

	n_items = xi.size();
}

void LinearRegression::setYList ( Ccd::Json::Value& yList )
{
	yi.clear();
	for ( auto yItem : yList.toArray() ) {
		if ( yItem.type() == Ccd::Json::ValueType::Int )
			yi.push_back ( yItem.toInt() );
		else if ( yItem.type() == Ccd::Json::ValueType::Double )
			yi.push_back ( yItem.toDouble() );
	}

	n_items = yi.size();
}

};
};
