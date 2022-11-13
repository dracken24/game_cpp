#ifndef STOPGAME_HPP
# define STOPGAME_HPP

// # include "envitems.hpp"
// # include "player.hpp"
// # include "props.hpp"
// # include "squareProps.hpp"
# include "weapon.hpp"
# include "../game.hpp"

// typedef struct NeedBy2DCam{
// 	Camera2D 		camera;
// 	RenderTexture 	textForCam;
// 	Rectangle		rectForCam;
// }	NeedBy2DCam;

// typedef struct MultipleCam2D{
// 	NeedBy2DCam	camera00;
// 	NeedBy2DCam camera01;
// 	NeedBy2DCam camera02;
// 	NeedBy2DCam camera03;
// 	NeedBy2DCam camera04;
// 	NeedBy2DCam camera05;
// 	NeedBy2DCam camera06;
// 	NeedBy2DCam camera07;
// 	NeedBy2DCam camera08;
// 	NeedBy2DCam camera09;
// }	MultipleCam2D;

// class Stop
// {
// 	public:
// 		Stop(void);
// 		~Stop(void);

// 		void			ftSavePlayer(Player *player);
// 		void			ftSaveEnvItems(EnvItems *envItems);
// 		void			ftSaveBlocks(Props *blocks);
// 		void			ftSaveCameras(MultipleCam2D *allCameras);
// 		void			ftSaveGame(Game *game);
// 		void			ftSaveMenu(Menu *menu);

// 		Player			*ftReturnPlayerPtr(void) const;
// 		Props			*ftReturnBlocksPtr(void) const;
// 		EnvItems		*ftReturnEnvItemsPtr(void) const;
// 		MultipleCam2D	*ftReturnAllCamerasPtr(void) const;
// 		Game            *ftReturnGamePtr(void) const;
// 		Menu            *ftReturnMenuPtr(void) const;

// 		// Player			ftReturnPlayer(void) const;
// 		// Props			ftReturnBlocks(void) const;
// 		// EnvItems		ftReturnEnvItems(void) const;
// 		// MultipleCam2D	ftReturnAllCameras(void) const;
// 		// Game            ftReturnGame(void) const;
// 		// Menu            ftReturnMenu(void) const;

// 		void			ftDeleteVars(void);

// 	private:
// 		Player  		*_player = new Player;
// 		EnvItems		*_envItems = new EnvItems;
// 		Props			*_blocks = new Props;
// 		MultipleCam2D	*_allCameras = new MultipleCam2D;
// 		Game		    *_game = new Game;
// 		Menu            *_menu = new Menu; 
// };

#endif