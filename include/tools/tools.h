#ifndef STRUCTS_H
#define STRUCTS_H


/*!
 * \file tools.h
 * \author Jules
 * \brief Déclaration des outils
 * \addtogroup Tools 
 * @{
 */


#include <iostream>
#include <sstream>

using namespace std;


/***
* Outils divers
***/



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


/*============== CLASSE BOOL2 ==============*/
class Bool2 {

	public :
	
		bool x;
		bool y;
		
		Bool2(bool i=0,bool j=0);
		Bool2(const Bool2& u);
		Bool2(const Int2& u);
		~Bool2();

		inline friend std::ostream& operator << (std::ostream& os, const Bool2& i)
		{
			os << "(" << i.x << "," << i.y << ")";
			return os; 
		};  
};	




/** @}*/

#endif