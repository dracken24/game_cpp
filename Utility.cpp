#include "./myIncludes/player.hpp"

#define G 800 // Gravity

typedef struct Vector2 {
    float x;              
    float y;              
}	Vector2;

// Vector3, 3 components
typedef struct Vector3 {
    float x;              
    float y;              
    float z;              
}	Vector3;

// Vector4, 4 components
typedef struct Vector4 {
    float x;              
    float y;              
    float z;              
    float w;              
}	Vector4;

typedef struct Rectangle {
	float x;	  // Rectangle top-left corner position x
	float y;	  // Rectangle top-left corner position y
	float width;  // Rectangle width
	float height; // Rectangle height
}	Rectangle;

typedef struct Color {
	unsigned char t; // Color alpha value
	unsigned char r; // Color red value
	unsigned char g; // Color green value
	unsigned char b; // Color blue value
}	Color;

typedef struct EnvItem {
	Rectangle rect;
	int blocking;
	Color color;
}	EnvItem;

void	ftUseGravity(Player *player, EnvItem *envItems, float delta, int envItemsLength)
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
		player->ftChangeJump(true);
}