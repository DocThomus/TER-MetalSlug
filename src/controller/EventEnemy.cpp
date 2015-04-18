#include "controller/EventEnemy.h"


EventEnemy::EventEnemy()
:EventGame(), enemy_pos(0), enemy_type(Enemy::REBEL)
{
	have_IA = false;
}


EventEnemy::EventEnemy(int pos, Int2 pos_e, Enemy::TypeEnemy t)
:EventGame(pos), enemy_pos(pos_e), enemy_type(t)
{
	have_IA = false;
}


EventEnemy::~EventEnemy()
{

}


void EventEnemy::setEnemyType(Enemy::TypeEnemy t)
{
	enemy_type = t;
}


void EventEnemy::setEnemyPosition(Int2 pos)
{
	enemy_pos = pos;
}


void EventEnemy::setEnemyIA(bool b)
{
	have_IA = b;
}


void EventEnemy::trigger(Game* g)
{
	EnemyView* enemy = new EnemyView(enemy_pos, enemy_type, have_IA);
	if(have_IA)
		enemy->walk(-1);
	g->enemies.push_back(enemy);
}
