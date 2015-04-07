#ifndef EVENTENEMY_H
#define EVENTENEMY_H

/*!
 * \file EventEnemy.h
 * \author Jules
 * \brief Déclaration de la classe EventEnemy
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <sstream>

#include <controller/EventGame.h>

#include <controller/Game.h>
#include <model/Enemy.h>


using namespace std;



/*!\class EventEnemy
 * \brief Un EventGame déclenchant l'apparition d'un ennemi.
 */
class EventEnemy : public EventGame
{

	protected :

		Int2 enemy_pos; /*!< \brief Position de l'ennemi à générer. */
		Enemy::TypeEnemy enemy_type; /*!< \brief Type de l'ennemi à générer. */
		bool have_IA;

	public :


		/*!
	     * \brief Constructeur
	     *
	     * Constructeur par défaut de la classe EventEnemy
	     */
		EventEnemy();

		/*!
	     * \brief Constructeur
	     *
	     * Constructeur complet de la classe EventEnemy
	     * \param pos : Position de l'événement.
	     * \param pos_e : Position de l'ennemi à générer.
	     * \param t : Type de l'ennemi à générer.
	     */
		EventEnemy(int pos, Int2 pos_e, Enemy::TypeEnemy t);

		/*!
	     * \brief Destructeur
	     *
	     * Destructeur de la classe EventEnemy
	     */
		~EventEnemy();

		/*!
		 * \brief Définit le type de l'ennemi à génèrer lors de l'événement.
		 */
		void setEnemyType(Enemy::TypeEnemy t);

		/*!
		 * \brief Définit la position de l'ennemi à génèrer lors de l'événement.
		 */
		void setEnemyPosition(Int2 pos);

		/*!
		 * \brief Définit si l'ennemi à générer doit être intelligent ou non.
		 */
		void setEnemyIA(bool b);

		/*!
		 * \brief Déclenche l'événement dans une partie.
		 * \param g : Jeu auquel appliquer l'événement.
		 */
		virtual void trigger(Game* g);


};



/** @}*/

#endif