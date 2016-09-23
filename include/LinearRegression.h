#include <vector>

#include <JsonPP.h>

namespace Ccd
{
namespace Math
{

class LinearRegression
{

	// f(x) = a + b*x
public:
	LinearRegression();
	~LinearRegression();
	void addPoint ( double _x, double _y );
	bool doTheMath();
	double a(); // y achsen abschnitt
	double b(); // steigung
	double y ( double _x );
	double x ( double _y );
	void clear();
	void setXList ( std::vector<double> _xi );
	void setYList ( std::vector<double> _yi );
	void setXList ( Ccd::Json::Value& xList );
	void setYList ( Ccd::Json::Value& yList );
private:
	std::vector<double> xi;
	std::vector<double> yi;
	std::vector<double> xi2; // xi^2
	std::vector<double> xiyi;
	int n_items;
	double __a; //name conflicts with m()
	double __b; //name conflicts with b()
	bool math_done;
};

};
};
