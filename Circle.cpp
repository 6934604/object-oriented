
#include"Circle.h"


Circle::Circle()
{
	Circle::r = 2;
	
}
Circle::Circle(double R)
{
	Circle::r = R;
	
}
double Circle::Area()
{
	return 3.14*Circle::r*Circle::r;
}