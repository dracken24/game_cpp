#include "../../myIncludes/class/props.hpp"

Props::Props(int nbr)
{
	this->_squareProps = new SquareProps[nbr];
	return ;
}

Props::~Props(void)
{
	// delete this->_squareProps;
	return ;
}

void	Props::ftAddSquareProps(Vector2 pos, Vector2 size, Color color, int nbr)
{
	this->_squareProps[nbr].ftInitSquareprops(pos, size, color);
}

Rectangle	Props::ftReturnRectangleSqPr(int nbr)
{
	return (this->_squareProps[nbr].ftReturnRectangle());
}

Color	Props::ftReturnRecColorSqPr(int nbr)
{
	return (this->_squareProps[nbr].ftReturnRecColor());
}

SquareProps	*Props::ftReturnSquareProp(int nbr) const
{
	return (&this->_squareProps[nbr]);
}

void	Props::ftSetPosSquareProp(Vector2 pos, int nbr)
{
	this->_squareProps[nbr].ftInitPosition(pos);
}

void	Props::ftMoveSquareProp(Vector2 pos, int nbr)
{
	this->_squareProps[nbr].ftMovePosition(pos.x, pos.y);
}
