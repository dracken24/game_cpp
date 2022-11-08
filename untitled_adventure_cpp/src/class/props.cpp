#include "../../myIncludes/class/props.hpp"

Props::Props(int nbr)
{
	this->_squareProps = new SquareProps[nbr];
	this->_nbr = nbr;
	return ;
}

Props::~Props(void)
{
	// delete this->_squareProps;
	return ;
}

/************************************** Gestion square props *****************************************/

// Modify //

void	Props::ftAddSquareProps(Vector2 pos, Vector2 size, Color color, int nbr)
{
	this->_squareProps[nbr].ftInitSquareprops(pos, size, color, nbr);
}

void	Props::ftSetPosSquareProp(Vector2 pos, int nbr)
{
	this->_squareProps[nbr].ftInitPosition(pos);
}

void	Props::ftMoveSquareProp(Vector2 pos, int nbr)
{
	this->_squareProps[nbr].ftMovePosition(pos.x, pos.y);
}

void	Props::ftSetSpeedModifier(float speed, char c, int nbr)
{
	
	if (c == 'X')
		this->_squareProps[nbr].ftSetSpeedModifier(speed, c);
	else if (c == 'Y')
		this->_squareProps[nbr].ftSetSpeedModifier(speed, c);
}

void	Props::ftChangeSpeedModifier(float speed, char c, int nbr)
{
	if (c == 'X')
		this->_squareProps[nbr].ftChangeSpeedModifier(speed, c);
	else if (c == 'Y')
		this->_squareProps[nbr].ftChangeSpeedModifier(speed, c);
}

// Return //

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

int		Props::ftReturnNbr(void) const
{
	return (this->_nbr);
}

int	Props::ftReturnOneNbr(int	nbr) const
{
	return (this->_squareProps[nbr].ftReturnNbr());
}

float	Props::ftReturnSqurtPos(char c, int nbr) const
{
	if (c == 'X')
		return (this->_squareProps[nbr].ftReturnSqurtPos('X'));
	else if (c == 'Y')
		return (this->_squareProps[nbr].ftReturnSqurtPos('Y'));
	return (0);
}

float	Props::ftReturnSqurtWorH(char c, int nbr) const
{
	if (c == 'W')
		return (this->_squareProps[nbr].ftReturnWideorHigh('W'));
	else if (c == 'H')
		return (this->_squareProps[nbr].ftReturnWideorHigh('H'));
	return (0);
}

float	Props::ftReturnSpeedModifier(char c, int nbr) const
{
	if (c == 'X')
		return (this->_squareProps[nbr].ftReturnSpeedModifier('X'));
	else if (c == 'Y')
		return (this->_squareProps[nbr].ftReturnSpeedModifier('Y'));
	return (0);
}

/***************************************** --------- ********************************************/
