#pragma once

namespace Ccd
{
namespace Math
{


class LinearFunktion
{
public:
	LinearFunktion ();
	LinearFunktion ( double slope, double yIntersect );
	LinearFunktion ( LinearFunktion& other );
	LinearFunktion ( LinearFunktion&& other );
	
	LinearFunktion& operator=( LinearFunktion& other ) = default;
	LinearFunktion& operator=( LinearFunktion&& other ) = default;

	/* Access the computed results */
	double yIntersect();
	double slope();

	double y ( double x );
	double x ( double y );

private:
	/* Store results */
	double m_slope = 0.0;
	double m_yIntersect = 0.0;
};

}
}
