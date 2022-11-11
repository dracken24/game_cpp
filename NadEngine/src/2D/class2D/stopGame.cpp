#include "../../../myIncludes/class2D/stopGame.hpp"

Stop::Stop(void)
{
	return ;
	
}

Stop::~Stop(void)
{
	return;
}

//*=-=* Saves fonctions *=-=*//

// void		Stop::ftSaveGame(Game *Gamee)
// {
// 	this->_game = Gamee;
// }

void		Stop::ftSavePlayer(Player *player)
{
	this->_player = player;
}

void		Stop::ftSaveEnvItems(EnvItems *envItems)
{
	this->_envItems = envItems;
}

void		Stop::ftSaveBlocks(Props *blocks)
{
	this->_blocks = blocks;
}

//** Return fonctions *=-=*/

// Game		*Stop::ftReturnGame(void) const
// {
// 	return (this->_game);
// }

Player		*Stop::ftReturnPlayer(void) const
{
	return (this->_player);
}

Props		*Stop::ftReturnBlocks(void) const
{
	return (this->_blocks);
}

EnvItems	*Stop::ftReturnEnvItems(void) const
{
	return (this->_envItems);
}

//** Delete fonctions *=-=*/

void		Stop::ftDeleteVars(void)
{
	delete this->_player;
	delete this->_envItems;
	delete this->_blocks;
	// delete this->_game;
}
