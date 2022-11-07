#include "../../vendor/raylib/src/raylib.h"
#include "../../myIncludes/game.hpp"
#include "../../myIncludes/player.hpp"

void	ftUsePlayerGravity(Player *player, EnvItem *envItems, float delta, int envItemsLength)
{
	int hitObstacle = 0;

	for (int i = 0; i < envItemsLength; i++)
	{
		EnvItem *ei = envItems + i;
		Vector2 *p = player->ftReturnPlayerPositionPtr();
		if (ei->blocking &&
			ei->rect.x <= p->x &&
			ei->rect.x + ei->rect.width >= p->x &&
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
		// player->ftMoveCollisionBox({0, player->ftReturnSpeed() * delta});
		player->ftMovePosition(0, player->ftReturnSpeed() * delta);
		// player->ftSetCollosionBox({player->ftReturnPlayerPositionX() + 25, player->ftReturnPlayerPositionY() - 97}, {(float)player->ftReturnCollBoxSize('W'), (float)player->ftReturnCollBoxSize('H')});
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
	int 		hitObstacle = 0;

	for (int i = 0; i < envItemsLength; i++)
	{
		EnvItem *ei = envItems + i;
		Vector2 *p = prop->ftReturnPositionPtr();
		if (ei->blocking &&
			ei->rect.x <= p->x &&
			ei->rect.x + ei->rect.width >= p->x &&
			ei->rect.y >= p->y &&
			ei->rect.y <= p->y + prop->ftReturnWideorHigh(0) + prop->ftReturnSpeed() * delta)
		{
			hitObstacle = 1;
			prop->ftSetSpeed(0);
			p->y = ei->rect.y;
		}
	}
	if (!hitObstacle)
	{
		prop->ftMovePosition(0, prop->ftReturnSpeed() * delta);
		prop->ftChangeSpeed(G * delta);
	}
	// else // Rebondit
	// 	prop->ftMovePosition(0, -1);
}

// CheckCollisionRecs()
