#include "../../myIncludes/game.hpp"

void	ftKeyGestion(Game *Game, Player *player, float delta)
{
	// std::cout << player->ftReturnNbr() << std::endl;
	if (IsKeyDown(KEY_A)) // Move left
	{
		if (player->ftReturnNbr() == 2)
		{
			player->ftChangeCollisionBoxSize({70, 85});
			player->ftChangeWeaponCollBoxSize(85, 'H');
			player->ftSetAjustCollBox({-45, 85});
		}
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
	else if (IsKeyDown(KEY_D)) // Move right
	{
		if (player->ftReturnNbr() == 2)
		{
			player->ftChangeCollisionBoxSize({70, 85});
			player->ftChangeWeaponCollBoxSize(85, 'H');
			player->ftSetAjustCollBox({-25, 85});
		}
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
	else if (player->ftReturnNbr() == 2)
	{
		player->ftSetAjustCollBox({-20, 110});
		player->ftChangeWeaponCollBoxSize((float)player->ftReturnCollBoxSize('H'), 'H');
		player->ftChangeCollisionBoxSize({50, 110});
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
			player->ftChangeDoAttack(true);
			player->ftChangeAttackCt(1);
		}
	}
	player->ftChangeCollX(false);
}