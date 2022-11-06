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
	this->rect.width = size.x;
	this->rect.height = size.y;
	this->color = color;
}

Rectangle	SquareProps::ftReturnRectangle(void)
{
	return (this->rect);
}

Color	SquareProps::ftReturnRecColor(void)
{
	return (this->color);
}
