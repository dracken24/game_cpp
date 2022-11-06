#include "../myIncludes/player.hpp"
#include "../myIncludes/game.hpp"
#include "../myIncludes/menu.hpp"

void	ftChooseMenu(Menu *menu)
{
	static int	ct; 
	static int	warning;

	if (!ct)
		ct = 1;
	if (!warning || warning > 80)
		warning = 0;

	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S))
		ct *= -1;
	if (IsKeyPressed(KEY_ENTER))
	{
		if (ct == 1)
			menu->ftChangeStart(1);
		else if (ct == -1 && menu->ftReturnPlayer() != 0)
			menu->ftChangeStart(2);
		else
			warning = 1;
	}

	if (ct == 1)
	{
		DrawText("<---*", 420, 200, 20, DARKGRAY);
	}
	else if (ct == -1)
	{
		DrawText("<---*", 420, 250, 20, DARKGRAY);
	}

	if (warning >= 1)
	{
		DrawText("Please, Choose A Character First", 150, 0, 20, ORANGE);
		warning++;
	}
}

void	ftChooseCharacter(Menu *menu)
{
	static int ct;


	if (!ct)
		ct = 1;

	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S))
	{
		ct *= -1;
	}
	if (IsKeyPressed(KEY_ENTER))
	{
		if (ct == 1)
			menu->ftChangePlayer(1);
		if (ct == -1)
			menu->ftChangePlayer(2);
	}

	if (ct == 1)
	{
		DrawText("<---*", 400, 200, 20, DARKGRAY);
	}
	else if (ct == -1)
	{
		DrawText("<---*", 400, 250, 20, DARKGRAY);
	}
}

void	ftMenuChooseCharacter(Player * player, Menu * menu)
{
	menu->ftChangePlayer(0);
	ftChooseCharacter(menu);
	DrawText("Choose Your Character", 150, 100, 40, BLACK);
	DrawText("Edward Elric", 150, 200, 20, DARKGRAY);
	DrawText("Ichigo Kurosaki", 150, 250, 20, DARKGRAY);
	if (menu->ftReturnPlayer() == 1)
	{
		player->ftInitPlayerImgs(1);
		player->ftChangeCtIdle(15);
		player->ftChangeCtMove(10);
		player->ftChangeCtJump(25);
		player->ftChangeCtFall(10);
		player->ftInitCtMoveX(25);
		player->ftInitCtMoveY(100, "Idle");
		player->ftInitCtMoveY(95, "Move");
		player->ftChangeCtAttack(42 / 7);
		player->ftChangeMoveAttackX(101);
		player->ftChangeMoveAttackY(102);
		menu->ftChangeStart(0);
	}
	else if (menu->ftReturnPlayer() == 2)
	{
		player->ftInitPlayerImgs(2);
		player->ftChangeCtIdle(15);
		player->ftChangeCtMove(8);
		player->ftChangeCtJump(15);
		player->ftChangeCtFall(10);
		player->ftInitCtMoveX(55);
		player->ftInitCtMoveY(108, "Idle");
		player->ftInitCtMoveY(86, "Move");
		player->ftChangeCtAttack(42 / 7);
		player->ftChangeMoveAttackX(30);
		player->ftChangeMoveAttackY(100);
		menu->ftChangeStart(0);
	}
}
