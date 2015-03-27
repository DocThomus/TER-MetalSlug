#include <tools/tools.h>



/*============== FONCTIONS UTILES ==============*/

/* CONVERSION VERS STRING */
template <typename T> string toString(const T& t) { 
    ostringstream os; 
    os<<t; 
    return os.str(); 
} 


/*============== CLASSE INT2 ==============*/
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


/*============== CLASSE FLOAT2 ==============*/
Float2::Float2(float x, float y)
:x(x),y(y)
{}

Float2::Float2(const Float2& u) 
{
	x = u.x;
	y = u.y;
};

Float2::Float2(const Int2& u) 
{
	x = float(u.x);
	y = float(u.y);
};

Float2::~Float2()
{}



/*============== CLASSE BOOL2 ==============*/
Bool2::Bool2(bool x, bool y)
:x(x),y(y)
{}

Bool2::Bool2(const Bool2& u) 
{
	x = u.x;
	y = u.y;
};


Bool2::~Bool2()
{}
