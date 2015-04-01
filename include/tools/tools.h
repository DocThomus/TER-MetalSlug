#ifndef STRUCTS_H
#define STRUCTS_H


/*!
 * \file tools.h
 * \author Jules
 * \brief Outils de programmation (classes,fonctions...)
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

/*!
 * \brief Conversion d'une variable quelconque en string
 */
template <typename T> string toString(const T& t); 



/*============== CLASSE INT2 ==============*/

 /*!\class Int2
 *  \brief Stockage de deux entiers
 *
 * Stocke deux entiers, permet un accès plus intuitif qu'avec un simple tableau.
 * Utilse pour stocker une position ou une taille.
 */
class Int2 {

	public :
	
		int x; /*!< \brief Entier 1 */
		int y; /*!< \brief Entier 2 */
		
		Int2(int i=0,int j=0); /*!< \brief Constructeur */
		Int2(const Int2& u); /*!< \brief Constructeur par copie */
		~Int2(); /*!< \brief Destructeur */

		/*!\relates operator <<
		 * \brief Pour afficher les information d'un objet dans le flux standard.
		 */
		inline friend ostream& operator << (std::ostream& os, const Int2& i)
		{
			os << "(" << i.x << "," << i.y << ")";
			return os; 
		};  
};	



/*============== CLASSE FLOAT2 ==============*/

/*!\class Float2
 *  \brief Stockage de deux flottants
 *
 * Stocke deux flottants, permet un accès plus intuitif qu'avec un simple tableau.
 * Utilse pour stocker une position ou une taille.
 */
class Float2 {

	public :
	
		float x; /*!< \brief Float 1 */
		float y; /*!< \brief Float 2 */
		
		Float2(float i=0,float j=0); /*!< \brief Constructeur */
		Float2(const Float2& u); /*!< \brief Constructeur par copie */
		Float2(const Int2& u); /*!< \brief Construction à partir d'un Int2 */
		~Float2(); /*!< \brief Destructeur */

		/*!\relates operator <<
		 * \brief Pour afficher les information d'un objet dans le flux standard.
		 */
		inline friend std::ostream& operator << (std::ostream& os, const Float2& i)
		{
			os << "(" << i.x << "," << i.y << ")";
			return os; 
		};  
};	


/*============== CLASSE BOOL2 ==============*/

/*!\class Bool2
 *  \brief Stockage de deux booléens
 *
 * Stocke deux booléens, permet un accès plus intuitif qu'avec un simple tableau.
 */
class Bool2 {

	public :
	
		bool x; /*!< \brief Booléen 1 */
		bool y; /*!< \brief Booléen 2 */
		
		Bool2(bool i=0,bool j=0); /*!< \brief Constructeur */
		Bool2(const Bool2& u); /*!< \brief Constructeur par copie*/
		Bool2(const Int2& u); /*!< \brief Constructeur à partir d'un Int2 */
		~Bool2(); /*!< \brief Destructeur */

		/*!\relates operator <<
		 * \brief Pour afficher les information d'un objet dans le flux standard.
		 */
		inline friend std::ostream& operator << (std::ostream& os, const Bool2& i)
		{
			os << "(" << i.x << "," << i.y << ")";
			return os; 
		};  
};	




/** @}*/

#endif