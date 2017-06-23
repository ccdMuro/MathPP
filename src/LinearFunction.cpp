#include "LinearFunction.h"

namespace Ccd
{
namespace Math
{

LinearFunktion::LinearFunktion() :
	m_slope { 0 },
m_yIntersect { 0 } {}

LinearFunktion::LinearFunktion ( double slope, double yIntersect ) :
	m_slope {slope},
m_yIntersect {yIntersect} {}

LinearFunktion::LinearFunktion ( LinearFunktion& other ) :
	m_slope { other.m_slope },
m_yIntersect { other.m_yIntersect} {}

LinearFunktion::LinearFunktion ( LinearFunktion&& other ) :
	m_slope { other.m_slope },
m_yIntersect { other.m_yIntersect} {}



double LinearFunktion::yIntersect()
{
	return m_yIntersect;
}

double LinearFunktion::slope()
{
	return m_slope;
}


double LinearFunktion::y ( double x )
{
	return ( ( m_slope * x ) + m_yIntersect );
}

double LinearFunktion::x ( double y )
{
	return ( ( y -  m_yIntersect ) / m_slope );
}


}
}
