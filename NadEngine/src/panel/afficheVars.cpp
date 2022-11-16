#include "../../myIncludes/game.hpp"

//** Select Box **//              Collision Box   /    Visual Box     /               / Affichable/ Variable Struct/ Nbr to put
void    ftSelectBox(Game *Game, Rectangle textBox1, Rectangle textBox2, Vector2 posText, char *name, char *varName, char *nbr, int ct)
{
	// static Rectangle textBox1;
	static bool mouseOnText[512];
	static int 	letterCount[512];
	static int 	framesCounter[512];
	// char 		*tmpText[512];

	// static char tmpText[512][MAX_INPUT_CHARS + 1];

	// tmpText[ct][MAX_INPUT_CHARS + 1] = '\0';

	if (!name && !varName && !nbr)
	{
		std::cout << "NO" << std::endl;
		framesCounter[ct] = 0;
		// std::cout << "1" << std::endl;
		letterCount[ct] = 0;
		// std::cout << "2" << std::endl;
		return;
	}

	mouseOnText[ct] = false;
	if (!letterCount[ct] || !framesCounter[ct])
	{
		letterCount[ct] = 0;
		// framesCounter[ct] = 0;
	}

	if (CheckCollisionPointRec(Game->mouse.pos, textBox1))
		mouseOnText[ct] = true;
	else
		mouseOnText[ct] = false;
	if (mouseOnText[ct])
	{
		// Set the window's cursor to the Box
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		while (key > 0)
		{
			if ((key >= 32) && (key <= 125) && (letterCount[ct] < MAX_INPUT_CHAR))
			{
				varName[letterCount[ct]] = (char)key;
				varName[letterCount[ct] + 1] = '\0';
				letterCount[ct]++;
			}
			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			letterCount[ct]--;
			if (letterCount[ct] < 0)
				letterCount[ct] = 0;
			varName[letterCount[ct]] = '\0';
		}
	}
	else
	{
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	}
	if (mouseOnText[ct])
		framesCounter[ct]++;

	// Draw on screen
	DrawText(name, posText.x, posText.y, 14, LIGHTGRAY);
	DrawRectangleRec(textBox2, LIGHTGRAY);
	if (mouseOnText[ct])
		DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, RED);
	else
		DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, LIGHTGRAY);
	DrawText(varName, (int)textBox2.x + 5, (int)textBox2.y + 4, 14, MAROON);
	if (mouseOnText[ct])
	{
		if (letterCount[ct] < MAX_INPUT_CHARS)
		{
			if (((framesCounter[ct] / 20) % 2) == 0)
				DrawText("_", (int)textBox2.x + MeasureText(varName, 14), (int)textBox2.y + 12, 14, MAROON);
		}
	}
	else if (varName[0] == '\0')
	{
		DrawText(nbr, (int)textBox2.x + MeasureText(varName, 14) + 2, (int)textBox2.y + 4, 14, MAROON);
	}
}

//*** Draw variables on side right down panel ***//
void	ftDrawVarsRiDownPanel(Game *game)
{
	int nbr = game->selected2D.nbr;

	if (game->selected2D.nbr != game->selected2D.lastNbr || game->selected2D.type != game->selected2D.lastType)
	{
		static int i = 0;
		// std::cout << "Last " << i++ << std::endl;
		if (game->selected2D.lastType == 1) // Player
		{
			std::cout << "Reset Player" << i++ << std::endl;
			VarChar	*varsPlayer = game->selected2D.player->ftReturnVarsChar();

			varsPlayer->plyPosX[0] = '\0';
			varsPlayer->plyPosY[0] = '\0';
			varsPlayer->plyWidth[0] = '\0';
			varsPlayer->plyHeight[0] = '\0';
			varsPlayer->collBoxPosX[0] = '\0';
			varsPlayer->collBoxPosY[0] = '\0';
			varsPlayer->collBoxWidth[0] = '\0';
			varsPlayer->collBoxHeight[0] = '\0';

			for (int i = 0; i < 8; i++)
			{
				ftSelectBox(game, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0}, NULL, NULL, NULL, i);
			}
			
			game->selected2D.lastNbr = game->selected2D.nbr;
			game->selected2D.lastType= game->selected2D.type;
			std::cout << "Reset Player" << i++ << std::endl;
		}
		else if (game->selected2D.lastType == 2) // Items Blocks Props
		{
			std::cout << "Reset Props" << i++ << std::endl;
			VarCharPr	*varsProp = game->selected2D.prop->ftReturnVarsProp();
			varsProp->propPosX[0] = '\0';
			varsProp->propPosY[0] = '\0';
			varsProp->propWidth[0] = '\0';
			varsProp->propHeight[0] = '\0';

			for (int i = 0; i < 4; i++)
			{
				ftSelectBox(game, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0}, NULL, NULL, NULL, i + 100);
			}

			game->selected2D.lastNbr = game->selected2D.nbr;
			game->selected2D.lastType = game->selected2D.type;
		}
		else if (game->selected2D.lastType == 3) // Platforms
		{
			VarCharEnvi	*varsEnvi = &game->selected2D.item->_varCharEnvi;
			varsEnvi->enviPosX[0] = '\0';
			varsEnvi->enviPosY[0] = '\0';
			varsEnvi->enviWidth[0] = '\0';
			varsEnvi->enviHeight[0] = '\0';

			for (int i = 0; i < 4; i++)
			{
				ftSelectBox(game, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0}, NULL, NULL, NULL, i + 200);
			}

			game->selected2D.lastNbr = game->selected2D.nbr;
			game->selected2D.lastType = game->selected2D.type;
			std::cout << "Reset Items" << i++ << std::endl;
		}
	}
	if (game->selected2D.type == 1) // Player selected
	{
		VarChar     *varsPlayer = game->selected2D.player->ftReturnVarsChar();
		Rectangle   recPlayer = game->selected2D.player->ftReturnCollisionBox();

		char *tmp = ft_ftoa(recPlayer.x - game->selected2D.player->ftReturnAjustCollBox('X'), 0);
		ftSelectBox(game, {1260, 317, 75, 20}, {60, 10, 75, 20}, {10, 14}, "Pos X:", varsPlayer->plyPosX, tmp, 0);
		tmp = ft_ftoa(recPlayer.y + game->selected2D.player->ftReturnAjustCollBox('Y'), 0);
		ftSelectBox(game, {1400, 317, 75, 20}, {200, 10, 75, 20}, {150, 14}, "Pos Y:", varsPlayer->plyPosY, tmp, 1);
		tmp = ft_ftoa(recPlayer.width, 0);
		ftSelectBox(game, {1260, 347, 75, 20}, {60, 40, 75, 20}, {10, 44}, "Width:", varsPlayer->plyWidth, tmp, 2);
		tmp = ft_ftoa(recPlayer.height, 0);
		ftSelectBox(game, {1400, 347, 75, 20}, {200, 40, 75, 20}, {150, 44}, "Height:", varsPlayer->plyHeight, tmp, 3);
	}
	else if (game->selected2D.type == 2) // Items Blocks Props
	{
		VarCharPr	*varsProp = game->selected2D.prop->ftReturnVarsProp();
		Rectangle   recProp = game->selected2D.prop->ftReturnRectangle();

		char *tmp = ft_ftoa(recProp.x, 0);
		ftSelectBox(game, {1260, 317, 75, 20}, {60, 10, 75, 20}, {10, 14}, "Pos X:", varsProp->propPosX, tmp, 100);
		tmp = ft_ftoa(recProp.y, 0);
		ftSelectBox(game, {1400, 317, 75, 20}, {200, 10, 75, 20}, {150, 14}, "Pos Y:", varsProp->propPosY, tmp, 101);
	}
	else if (game->selected2D.type == 3) // Platforms
	{
		VarCharEnvi	*varsEnvi = &game->selected2D.item->_varCharEnvi;
		Rectangle   recEnvi = game->selected2D.item->rect;

		char *tmp = ft_ftoa(recEnvi.x, 0);
		ftSelectBox(game, {1260, 317, 75, 20}, {60, 10, 75, 20}, {10, 14}, "Pos X:", varsEnvi->enviPosX, tmp, 200);
		tmp = ft_ftoa(recEnvi.y, 0);
		ftSelectBox(game, {1400, 317, 75, 20}, {200, 10, 75, 20}, {150, 14}, "Pos Y:", varsEnvi->enviPosY, tmp, 201);
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		std::cout << "";
		if (game->selected2D.type == 1)
		{
			VarChar *vars = game->selected2D.player->ftReturnVarsChar();
			game->selected2D.player->ftChangePosition(atof(vars->plyPosX), game->selected2D.player->ftReturnCollBoxPos('Y'));
			game->selected2D.player->ftChangePosition(game->selected2D.player->ftReturnCollBoxPos('X'), atof(vars->plyPosY));
		}
	}
}
