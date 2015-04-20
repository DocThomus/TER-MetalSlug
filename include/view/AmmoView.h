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
#include <model/Weapon.h>
#include <view/MyDrawable.h>

using namespace std;
using namespace sf;



/*!\class AmmoView
 * \brief Un objet Ammo affichable et sonore.
 */
class AmmoView : public Ammo, public MyDrawable
{
	
	protected :

		static vector<Texture*> textures; /*!< \brief Variable de classe contenant les différentes textures de projectiles. */
		static vector<Sound*> sounds; /*!< \brief Variable de classe contenant les sons des tirs. */
		static vector<Animation> animations_list[NB_TYPE_AMMO]; /*!< \brief Variable de classe contenant les différentes animations nécessaires aux ammos. */


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
		AmmoView(Ammo a);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe Ammo
	     */
		~AmmoView();

		/*!
	     * \brief Chargement des ressources
	     *
	     * Methode statique permettant de charger les ressources des projectiles.
	     * ATTENTION : Cette méthode doit impérativement être appelée avant d'afficher des projectiles !
	     */
		static void loadRessources();

		/*!
	     * \brief Deletion des ressources 
	     *
	     * Methode statique permettant de libérer la mémoire allouée aux ressources de la classe.
	     */
		static void deleteRessources();

		/*!
		 * \brief Associe l'ammo aux ressources qui lui correspondent.
		 */
		void initRessources();

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
		
		/*!
	     * \brief Modifier volume
	     *
	     * Modifie le volume des projectiles.
	     * \param volume : Nouveau volume des projectiles.
	     */
		static void setVolume(float volume);
		
		/*!
	     * \brief Reprendre
	     *
	     * Relance tous les éléments/sons de la classe AmmoView.
	     */
		static void resume();
		
		/*!
	     * \brief Pause
	     *
	     * Met en pause tous les éléments/sons de la classe AmmoView.
	     */
		static void pause();

};


/** @}*/

#endif
