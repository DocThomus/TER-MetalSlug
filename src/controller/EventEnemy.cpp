#include "controller/EventEnemy.h"


EventEnemy::EventEnemy()
:EventGame(), enemy_pos(0), enemy_type(Enemy::REBEL)
{

}


EventEnemy::EventEnemy(int pos, Int2 pos_e, Enemy::TypeEnemy t)
:EventGame(pos), enemy_pos(pos_e), enemy_type(t)
{

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



void EventEnemy::trigger(Game* g)
{
	EnemyView* enemy = new EnemyView(enemy_pos, enemy_type);
	g->enemies.push_back(enemy);
}