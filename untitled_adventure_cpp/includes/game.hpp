#ifndef GAME_HPP
# define GAME_HPP

#include "../vendor/raylib/src/raylib.h"
#include "../vendor/raylib/src/raymath.h"

#define G 800
#define PLAYER_JUMP_SPD 600.0f
#define PLAYER_HOR_SPD 200.0f

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
}   EnvItem;

/**------------------------->> Fonctions <<-------------------------**/

void 	ftUpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta);
void 	ftUpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems,
		int envItemsLength, float delta, int width, int height);
void	ftImgsGestion(Player *player, int *i);

#endif