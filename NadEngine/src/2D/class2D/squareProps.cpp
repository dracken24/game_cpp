#include "../../../myIncludes/class2D/squareProps.hpp"

SquareProps::SquareProps(void)
{
	return ;
}

SquareProps::~SquareProps(void)
{
	return ;
}

SquareProps	*SquareProps::ftReturnCopySquareProp(void)
{
	SquareProps *ret = new SquareProps;

	ret = this;
	return (ret);
}

void	SquareProps::ftInitSquareprops(Vector2 pos, Vector2 size, Color color, bool blocking, int nbr)
{
	this->rect.width = size.x;
	this->rect.height = size.y;
	this->rect.x = pos.x;
	this->rect.y = pos.y;
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->color = color;
	this->speed = 0;
	this->_nbr = nbr;
	this->blocking = blocking;
}

Rectangle	SquareProps::ftReturnRectangle(void) const
{
	return (this->rect);
}

Color	SquareProps::ftReturnRecColor(void) const
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
float	SquareProps::ftReturnWideorHigh(char c) const
{
	if (c == 'W') // Width
		return (this->rect.width);
	if (c == 'H') // Hight
		return (this->rect.height);
	return (0);
}

float	SquareProps::ftReturnSpeedX(char c) const
{
	if (c == 'X')
		return (this->speedX);
	return (0);
}

void	SquareProps::ftSetSpeedX(float speed, char c)
{
	if (c == 'X')
		this->speedX = speed;
}

void	SquareProps::ftChangeSpeedX(float speed, char c)
{
	if (c == 'X')
		this->speedX += speed;
}

int		SquareProps::ftReturnNbr(void) const
{
	return (this->_nbr);
}

float	SquareProps::ftReturnSqurtPos(char c) const
{
	if (c == 'X')
		return (this->pos.x);
	if (c == 'Y')
		return (this->pos.y);
	return (0);
}

float	SquareProps::ftReturnSpeedModifier(char c) const
{
	if (c == 'X')
		return (this->speedModifier.x);
	if (c == 'Y')
		return (this->speedModifier.y);
	return (0);
}

void	SquareProps::ftSetSpeedModifier(float speed, char c)
{
	if (c == 'X')
		this->speedModifier.x = speed;
	if (c == 'Y')
		this->speedModifier.y = speed;
}

void	SquareProps::ftChangeSpeedModifier(float speed, char c)
{
	if (c == 'X')
		this->speedModifier.x += speed;
	if (c == 'Y')
		this->speedModifier.y += speed;
}
