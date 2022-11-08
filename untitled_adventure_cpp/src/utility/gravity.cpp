#include "../../vendor/raylib/src/raylib.h"
#include "../../myIncludes/class/player.hpp"
#include "../../myIncludes/game.hpp"

void	ftGravityX(Game *Game, Player *player, Props *blocks)
{
	int k;

	for (int j = 0; j < blocks->ftReturnNbr(); j++)
	{
		Rectangle rect = blocks->ftReturnRectangleSqPr(j);
		k = 0;
		if (j == k)
			k++;

		if (CheckCollisionRecs(blocks->ftReturnRectangleSqPr(j), player->ftReturnCollisionBox())) // Test collision
		{

			if (rect.x - rect.width / 2 > player->ftReturnCollBoxPos('X') + player->ftReturnCollBoxSize('X') / 2) // Right
			{
				blocks->ftMoveSquareProp({PLAYER_HOR_SPD * Game->delta, 0}, j);
			}
			else
			{
				blocks->ftMoveSquareProp({-PLAYER_HOR_SPD * Game->delta, 0}, j);
			}
		}
		else if(CheckCollisionRecs(blocks->ftReturnRectangleSqPr(j), player->ftReturnWeaponCollRect()) && player->ftReturnDoAttack() == true)
		{
			if (player->ftReturnFace() == 0) // Right
			{
				blocks->ftMoveSquareProp({PLAYER_HOR_SPD * Game->delta * 20, -5}, j);
			}
			else
			{
				blocks->ftMoveSquareProp({-PLAYER_HOR_SPD * Game->delta * 20, -5}, j);
			}
		}

		if (CheckCollisionRecs(blocks->ftReturnRectangleSqPr(j), blocks->ftReturnRectangleSqPr(k)))
		{
			if (blocks->ftReturnSqurtPos('X', j) > blocks->ftReturnSqurtPos('X', k))
			{
				blocks->ftMoveSquareProp({-PLAYER_HOR_SPD * Game->delta, 0}, k);
			}
			else
			{
				blocks->ftMoveSquareProp({PLAYER_HOR_SPD * Game->delta, 0}, k);
			}
		}
	}
	player->ftChangeDoAttack(false);
}

void	ftGravityGestion(Game *Game, Player *player, Props *blocks)
{
	ftGravityX(Game, player, blocks);
}

void	ftUsePlayerGravity(Player *player, EnvItem *envItems, float delta, int envItemsLength)
{
	int hitObstacle = 0;

	for (int i = 0; i < envItemsLength; i++)
	{
		EnvItem *ei = envItems + i;
		Vector2 *p = player->ftReturnPlayerPositionPtr();
		if (ei->blocking &&
			ei->rect.x <= p->x &&
			ei->rect.x + ei->rect.width >= p->x + player->ftReturnCollBoxSize('w') &&
			ei->rect.y >= p->y &&
			ei->rect.y <= p->y + player->ftReturnSpeed() * delta)
		{
			hitObstacle = 1;
			player->ftSetSpeed(0);
			p->y = ei->rect.y;
		}
	}
	if (!hitObstacle)
	{
		player->ftMovePosition(0, player->ftReturnSpeed() * delta);
		player->ftChangeSpeed(G * delta);
		player->ftChangeJump(false);
	}
	else
	{
		player->ftChangeJump(true);
	}
}

void	ftUseGravity(SquareProps *prop, EnvItem *envItems, float delta, int envItemsLength)
{
	// static int	rebound;
	int 		hitObstacle = 0;

	// if (!rebound)
	// 	rebound = 0;
	for (int i = 0; i < envItemsLength; i++)
	{
		EnvItem *ei = envItems + i;
		Vector2 *p = prop->ftReturnPositionPtr();
		if (ei->blocking &&
			ei->rect.x - prop->ftReturnWideorHigh('W') <= p->x &&
			ei->rect.x + ei->rect.width >= p->x &&
			ei->rect.y - prop->ftReturnWideorHigh('H') >= p->y &&
			ei->rect.y - prop->ftReturnWideorHigh('H') <= p->y + prop->ftReturnSpeed() * delta)
		{
			hitObstacle = 1;
			prop->ftSetSpeed(0);
			p->y = ei->rect.y;
			Rectangle tmp = prop->ftReturnRectangle();
			prop->ftInitPosition({tmp.x, p->y - tmp.height});
		}
	}
	if (!hitObstacle)
	{
		prop->ftMovePosition(0, prop->ftReturnSpeed() * delta);
		prop->ftChangeSpeed(G * delta);
	}
}

