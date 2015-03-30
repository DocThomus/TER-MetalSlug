#ifndef MYDRAWABLE_H
#define MYDRAWABLE_H

/*!
 * \file MyDrawable.h
 * \author Jules
 * \brief Déclaration de la classe MyDrawable
 * \addtogroup View
 * @{
 */

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tools/XMLtools.h>

#include <view/Animation.h>
#include <view/Frame.h>

using namespace std;
using namespace sf;



/*!\class MyDrawable
 * \brief Un rectangle affichable
 *
 * L'objet contient un rectangle et une texture à lui appliquer.
 * La texture peut être répétée ou affichée.
 * Il est aussi possible de lui définir une animation.
 */
class MyDrawable
{

	protected :

		RectangleShape body; /*!< \brief  Rectangle à afficher */
		vector<Animation> animations; /*!< \brief Liste des animations de l'objet. */
		int current_anim; /*!< \brief Animation courante. */
		Texture* tex; /*!< \brief Texture à appliquer au rectangle. */
		Bool2 repeat_tex; /*!< \brief Indique si la texture doit être répétée horizontalement et/ou verticalement. */

	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe MyDrawable.
	     */
		MyDrawable();

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe MyDrawable.
	     */
		~MyDrawable();

		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		virtual void display(RenderWindow* window)=0;

		/*!
	     * \brief Remet l'animation courante au début.
	     */
		void resetAnim();

		/*!
	     * \brief Ajoute une animation à l'objet.
	     */
		void addAnimation(Animation a);

		/*!
	     * \brief Ajoute plusieurs animations à l'objet.
	     */
		void addAnimations(vector<Animation> v);

		/*!
	     * \brief Ajoute des animations chargées à partir d"un fichier XML.
	     */
		void addAnimations(string filename);

		/*!
	     * \brief Changement d'animation
	     *
	     * Change l'animation courante de l'objet.
	     * \param i : Indice de l'animation.
	     * \param repeat : Indique si l'animation doit se répéter ou non.
	     * \param next : Si l'animation n'est pas répétée, next est l'indice de l'application qui sera lue ensuite.
	     */
		bool changeAnimation(int i, bool repeat=true, int next=-1);

		/*!
	     * \brief Change la frame courante de l'animation courante.
	     */
		void changeFrame(int i);

		/*!
	     * \brief Retourne la frame courante de l'animation courante. 
	     */
		Frame* getFrame();

		/*!
	     * \brief Changement de frame.
	     *
	     * Indique à l'animation courante qu'elle doit passer à le frame suivante.
	     * \param n : nombre de frames à passer.
	     */
		bool setNextFrame(int n=1);

		/*!
	     * \brief Définition de la texture.
	     *
	     * Indique à l'objet quelle texture il doit appliquer à son rectangle.
	     * \param tex : Texture à appliquer.
	     * \param r : Indique si la texture doit être ou non répétée horizontalement/verticalement.
	     */
		void setTexture(Texture* tex, Bool2 r=Bool2(false,false));
		
		/*!
	     * \brief Mise à jour de la texture
	     *
	     * Met à jour la zone de la texture qui doit être appliquée au rectangle.
	     */
		virtual void updateIntRect();

		/*!
	     * \brief Chargement d'animations
	     *
	     * Methode statique permettant de charger des animations à partir d'un fichier.
	     */
		static vector<Animation> loadSpriteFromFile(string filename);


};


/** @}*/

#endif
