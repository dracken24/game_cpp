#include "../../myIncludes/squareProps.hpp"

SquareProps::SquareProps(void)
{
	return ;
}

SquareProps::~SquareProps(void)
{
	return ;
}

void	SquareProps::ftInitSquareprops(Vector2 pos, Vector2 size, Color color)
{
	this->rect.x = pos.x;
	this->rect.y = pos.y;
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->rect.width = size.x;
	this->rect.height = size.y;
	this->color = color;
	this->speed = 0;
}

Rectangle	SquareProps::ftReturnRectangle(void)
{
	return (this->rect);
}

Color	SquareProps::ftReturnRecColor(void)
{
	return (this->color);
}

Vector2	*SquareProps::ftReturnPositionPtr(void)
{
	return (&this->pos);
}

float	SquareProps::ftReturnSpeed(void) const
{
	return (this->speed);
}

void	SquareProps::ftSetSpeed(float speed)
{
	this->speed = speed;
}

void	SquareProps::ftChangeSpeed(float speed)
{
	this->speed += speed;
}

void	SquareProps::ftMovePosition(float x, float y)
{
	this->pos.x += x;
	this->rect.x += x;
	this->pos.y += y;
	this->rect.y += y;
}

void	SquareProps::ftInitPosition(Vector2 pos)
{
	this->pos.x = pos.x;
	this->rect.x = pos.x;
	this->pos.y = pos.y;
	this->rect.y = pos.y;
}
float	SquareProps::ftReturnWideorHigh(int nbr)
{
	if (nbr == 0) // Width
		return (this->rect.width);
	if (nbr == 1) // Hight
		return (this->rect.height);
	return (0);
}
