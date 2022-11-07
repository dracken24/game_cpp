#include "../../myIncludes/game.hpp"

void	ftKeyGestion(Game *Game, Player *player, float delta)
{
	if (IsKeyDown(KEY_A)) // Move left
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5 && player->ftReturnAttackCt() == 0)
		{
			player->ftChangeCt(1);
		}
		if (player->ftReturnAttackCt() == 0)
		{
			player->ftChangeFace(1);
		}
		player->ftMoveCollisionBox({-(PLAYER_HOR_SPD * delta), 0});
		player->ftMovePosition(-(PLAYER_HOR_SPD * delta), 0);
	}
/******************************************************************************************************************/
	if (IsKeyDown(KEY_D)) // Move right
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5 && player->ftReturnAttackCt() == 0)
		{
			player->ftChangeCt(1);
		}
		if (player->ftReturnAttackCt() == 0)
		{
			player->ftChangeFace(0);
		}
		player->ftMoveCollisionBox({PLAYER_HOR_SPD * delta, 0});
		player->ftMovePosition(PLAYER_HOR_SPD * delta, 0);
	}
/******************************************************************************************************************/
	if (IsKeyDown(KEY_SPACE) && player->ftReturnJump()) // Jump
	{
		if (player->ftReturnAttackCt() == 0)
			player->ftChangeCt(4);
		player->ftSetSpeed(-PLAYER_JUMP_SPD);
		player->ftChangeJump(false);
	}
/******************************************************************************************************************/
	if ((IsKeyReleased(KEY_A) || IsKeyReleased(KEY_D)) && player->ftReturnCt() != 4 && player->ftReturnCt() != 5)
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5 && player->ftReturnAttackCt() == 0)
			player->ftChangeCt(0);
	}
/******************************************************************************************************************/
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) // Attack 1
	{
		if (player->ftReturnAttackCt() == 0)
		{
			Game->ct_action = 0;
			player->ftChangeAttackCt(1);
		}
	}
}