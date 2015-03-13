#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <sstream>

using namespace std;


/*============== FONCTIONS UTILES ==============*/

/* CONVERSION VERS STRING */
template <typename T> string toString(const T& t); 





/*============== CLASSE INT2 ==============*/
class Int2 {

	public :
	
		int x;
		int y;
		
		Int2(int i=0,int j=0);
		Int2(const Int2& u);
		~Int2();

		inline friend std::ostream& operator << (std::ostream& os, const Int2& i)
		{
			os << "(" << i.x << "," << i.y << ")";
			return os; 
		};  
};	



/*============== CLASSE FLOAT2 ==============*/
class Float2 {

	public :
	
		float x;
		float y;
		
		Float2(float i=0,float j=0);
		Float2(const Float2& u);
		Float2(const Int2& u);
		~Float2();

		inline friend std::ostream& operator << (std::ostream& os, const Float2& i)
		{
			os << "(" << i.x << "," << i.y << ")";
			return os; 
		};  
};	






#endif