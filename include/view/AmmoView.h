#ifndef AMMOVIEW_H
#define AMMOVIEW_H

/*!
 * \file AmmoView.h
 * \author Jules
 * \brief Déclaration de la classe AmmoView
 * \addtogroup View
 * @{
 */

#include <iostream>
#include <vector>
#include <math.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Ammo.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;



/*!\class AmmoView
 * \brief Un objet Ammo affichable.
 */
class AmmoView : public Ammo, public MyDrawable
{

	protected :

		static vector<Texture*> textures; /*!< \brief Variable de classe contenant les différentes textures de projectiles. */
		

	public :
		
		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe AmmoView
	     */
		AmmoView();

		/*!
	     * \brief Constructeur
	     *
	     * Construit un AmmoView à partir d'un Ammo.
	     */
		AmmoView(Ammo);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Ammo
	     */
		~AmmoView();

		/*!
	     * \brief Chargement des textures
	     *
	     * Methode statique permettant de charger les textures des projectiles.
	     * ATTENTION : Cette méthode doit impérativement être appelée avant d'afficher des projectiles !
	     */
		static void loadTextures();

		/*!
	     * \brief Affichage
	     *
	     * Affiche l'objet dans une fenêtre de rendu.
	     * \param window : Fenêtre d'affichage
	     */
		virtual void display(RenderWindow* window);

		/*!
	     * \brief Animer
	     *
	     * Déplace le projectile en fonction du temps.
	     * \param dt : Temps écoulé depuis le dernier appel de la fonction.
	     */
		virtual void animate(int dt);

		/*!
	     * \brief Projectile stoppé
	     *
	     * Le projectile "meurt" (il explose, disparait...).
	     * \param pos : Position d'arrêt de l'objet.
	     */
		virtual void die(Int2 pos);

		/*!
	     * \brief Initialisation de la rotation
	     * 
	     * Effectue la rotation du projectile en fonction de son vecteur de déplacemement.
	     */
		void initRotation();

};


/** @}*/

#endif
