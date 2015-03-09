#include <tools.h>



/*============== FONCTIONS UTILES ==============*/

/* CONVERSION VERS STRING */
template <typename T> string toString(const T& t) { 
    ostringstream os; 
    os<<t; 
    return os.str(); 
} 


/*============== CLASSE UINT2 ==============*/
Int2::Int2(int x, int y)
:x(x),y(y)
{}

Int2::Int2(const Int2& u) 
{
	x = u.x;
	y = u.y;
};

Int2::~Int2()
{}

string Int2::toString()
{
	stringstream ss;
	ss << x << "," << y;
	return ss.str();
}