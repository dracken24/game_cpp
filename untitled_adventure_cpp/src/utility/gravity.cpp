#include "../../vendor/raylib/src/raylib.h"
#include "../../myIncludes/class/player.hpp"
#include "../../myIncludes/game.hpp"

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
	int 		hitObstacle = 0;

	for (int i = 0; i < envItemsLength; i++)
	{
		EnvItem *ei = envItems + i;
		Vector2 *p = prop->ftReturnPositionPtr();
		if (ei->blocking &&
			ei->rect.x <= p->x &&
			ei->rect.x + ei->rect.width >= p->x &&
			// ei->rect.x + ei->rect.width >= p->x + prop->ftReturnWideorHigh(0) &&
			ei->rect.y >= p->y &&
			ei->rect.y <= p->y + prop->ftReturnWideorHigh(0) + prop->ftReturnSpeed() * delta)
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

