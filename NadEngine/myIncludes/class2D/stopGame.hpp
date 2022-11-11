#ifndef STOPGAME_HPP
# define STOPGAME_HPP

// # include "envitems.hpp"
// # include "player.hpp"
// # include "props.hpp"
// # include "squareProps.hpp"
// # include "weapon.hpp"
# include "../game.hpp"

class Stop
{
	public:
		Stop(void);
		~Stop(void);

		// void		ftSaveGame(Game *game);
		void		ftSavePlayer(Player *player);
		void		ftSaveEnvItems(EnvItems *envItems);
		void		ftSaveBlocks(Props *blocks);

		// Game		*ftReturnGame(void) const;
		Player		*ftReturnPlayer(void) const;
		Props		*ftReturnBlocks(void) const;
		EnvItems	*ftReturnEnvItems(void) const;

		void		ftDeleteVars(void);

	private:
		Player  	*_player = new Player;
		EnvItems	*_envItems = new EnvItems;
		Props		*_blocks = new Props;
		// Game		*_game = new Game;
};

#endif