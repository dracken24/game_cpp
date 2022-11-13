#include "../../../myIncludes/game.hpp"

void	ftDrawAll(Game *oldGame, Player *_player, EnvItems *_envItems, Props *_blocks);

	void ftSelectItems(Game *game, Player *player, Camera2D *camera, EnvItems *envItems, Props *blocks)
	{
		Vector2 mousePos = game->mouse.pos;
		Vector2 rayPos = GetScreenToWorld2D(mousePos, *camera);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			for (int i = 1; i < envItems->ftReturnEnviAllNbr(); i++)
			{
				Rectangle item = envItems->ftReturnRectangle(i);
				if (CheckCollisionPointRec(rayPos, item))
				{
					std::cout << "Hit Envi: " << i << std::endl;
				}

			}
			for (int i = 0; i < blocks->ftReturnNbr(); i++)
			{
				Rectangle item = blocks->ftReturnRectangleSqPr(i);
				if (CheckCollisionPointRec(rayPos, item))
				{

					std::cout << "Hit Blocks: " << i << std::endl;
				}
			}
			Rectangle	ply = player->FtReturnRectanglePlayer();
			if (CheckCollisionPointRec(rayPos, ply))
			{
				std::cout << "Hit Player: " << std::endl;
			}
		}
	}

	void ftMoveScreen(Game *game, Camera2D *camera)
	{
		Vector2 mousePos = GetMousePosition();
		Vector2 lastPos = game->mouse.pos;
		Vector2 forMove = {lastPos.x - mousePos.x, lastPos.y - mousePos.y};

		if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
		{
			game->posCam.x += forMove.x / camera->zoom;
			game->posCam.y += forMove.y / camera->zoom;
		}
		camera->zoom += ((float)GetMouseWheelMove() * 0.05f);
		if (camera->zoom > 3.0f)
			camera->zoom = 3.0f;
		else if (camera->zoom < 0.25f)
			camera->zoom = 0.25f;
	}

	void ftRunBuildMode(Game *game, Player *player, EnvItems *envItems, Props *blocks, Camera2D *camera)
	{
		ftMoveScreen(game, camera);
		ftSelectItems(game, player, camera, envItems, blocks);

		ftDrawAll(game, player, envItems, blocks); // Draw all imgs
	}

	void ftDrawAll(Game * oldGame, Player * _player, EnvItems * _envItems, Props * _blocks)
	{
		for (int i = 0; i < _envItems->ftReturnEnviAllNbr(); i++)
			DrawRectangleRec(_envItems->ftReturnRectangle(i), _envItems->ftReturnEnviColor(i));

		for (int i = 0; i < _blocks->ftReturnNbr(); i++)
		{
			Rectangle block = _blocks->ftReturnRectangleSqPr(i);
			DrawRectanglePro(block, (Vector2){block.width / 2, block.height / 2},
							 0, _blocks->ftReturnRecColorSqPr(i));
		}

		DrawTextureEx(_player->ftReturnGoodImage("Idle Ri", oldGame->ct_action / _player->ftReturnCtIdle()),
					  _player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
	}

