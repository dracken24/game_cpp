#include "../../../myIncludes/class2D/envitems.hpp"

EnvItems::EnvItems(void)
{
	return ;
}

EnvItems::~EnvItems(void)
{
    return ;
}

void	EnvItems::ftNewEnvItem(int nbr)
{

	this->_envItems = new EnvItem[nbr];
	this->_allNbr = nbr;
}

void 	EnvItems::ftInitEnvitem(Vector2 pos, Vector2 size,
			int blocking, Color color, Texture texture, int nbr)
{
	this->_envItems[nbr].rect.x = pos.x;
	this->_envItems[nbr].rect.y = pos.y;
	this->_envItems[nbr].rect.width = size.x;
	this->_envItems[nbr].rect.height = size.y;
	this->_envItems[nbr].color = color;
	this->_envItems[nbr].texture = texture;
	this->_envItems[nbr].blocking = blocking;
	this->_envItems[nbr].nbr = nbr;
}

EnvItem		*EnvItems::ftReturnEnvitemPtr(int nbr)
{
	return (&this->_envItems[nbr]);
}

Rectangle	EnvItems::ftReturnRectangle(int nbr) const
{
	return (this->_envItems[nbr].rect);
}

Vector2		EnvItems::ftReturnEnviPos(int nbr) const
{
	return ((Vector2){this->_envItems[nbr].rect.x, this->_envItems[nbr].rect.y});
}

Vector2		EnvItems::ftReturnEnviSize(int nbr) const
{
	return ((Vector2){this->_envItems[nbr].rect.width, this->_envItems[nbr].rect.height});
}

Color		EnvItems::ftReturnEnviColor(int nbr) const
{
	return (this->_envItems[nbr].color);
}

Texture		EnvItems::ftReturnEnviTexture(int nbr) const
{
	return (this->_envItems[nbr].texture);
}

int			EnvItems::ftReturnEnviAllNbr(void) const
{
	return (this->_allNbr);
}
