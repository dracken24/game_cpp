#include "../../../myIncludes/game.hpp"

void	ftDrawAll(Game *oldGame, Player *_player, EnvItems *_envItems, Props *_blocks);

void ftSelectItems(Game *game, Player *player, Camera2D *camera, EnvItems *envItems, Props *blocks)
{
	Vector2 mousePos = game->mouse.pos;
	Vector2 rayPos = GetScreenToWorld2D(mousePos, *camera);
	bool	touch = 0;

	rayPos.y -= 40;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 1; i < envItems->ftReturnEnviAllNbr(); i++)
		{
			Rectangle item = envItems->ftReturnRectangle(i);
			if (CheckCollisionPointRec(rayPos, item))
			{
				game->selected2D.type = 3;
				game->selected2D.nbr = i;
				game->selected2D.item = envItems->ftReturnEnvitemPtr(i);
				touch = 1;
			}

			for (int i = 0; i < blocks->ftReturnNbr(); i++)
			{
				Rectangle item = blocks->ftReturnRectangleSqPr(i);
				if (CheckCollisionPointRec(rayPos, item))
				{
					game->selected2D.type = 2;
					game->selected2D.nbr = i;
					game->selected2D.prop = blocks->ftReturnSquareProp(i);
					touch = 1;
				}
			}
			Rectangle	ply = player->ftReturnRectangleCollBox();
			if (CheckCollisionPointRec(rayPos, ply))
			{
				game->selected2D.type = 1;
				game->selected2D.player = player->ftReturnPlayer();
				touch = 1;
			}
			if (touch == 0) // Not select or deselect item
			{
				game->selected2D.type = 0;
			}
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
	game->mouse.camZoom = camera->zoom;
}

void ftRunBuildMode(Game *game, Player *player, EnvItems *envItems, Props *blocks, Camera2D *camera)
{
	ftMoveScreen(game, camera);

	ftDrawAll(game, player, envItems, blocks); // Draw all imgs
	ftSelectItems(game, player, camera, envItems, blocks);
}

void ftDrawAll(Game * oldGame, Player * _player, EnvItems * _envItems, Props * _blocks)
{
	for (int i = 0; i < _envItems->ftReturnEnviAllNbr(); i++)
	{
		Rectangle item = _envItems->ftReturnRectangle(i);
		DrawRectanglePro(item, {0, 0}, 0, _envItems->ftReturnEnviColor(i));
	}

	for (int i = 0; i < _blocks->ftReturnNbr(); i++)
	{
		Rectangle block = _blocks->ftReturnRectangleSqPr(i);
		DrawRectanglePro(block, {0, 0},
			0, _blocks->ftReturnRecColorSqPr(i));
	}

	// Collision Box //
	Rectangle plyCollBox = _player->ftReturnCollisionBox();
	Vector2 AdjCollBox = _player->ftReturnAjustCollisionBox();
	Vector2 plyPos = _player->ftReturnPlayerPosition();
	DrawRectangleRec(plyCollBox, BLACK); 	// Player collision box

	_player->ftSetCollosionBox((Vector2){plyPos.x + AdjCollBox.x, plyPos.y - AdjCollBox.y},
		(Vector2){plyCollBox.width, plyCollBox.height}, (Vector2){AdjCollBox.x, AdjCollBox.y});
	
	// Player //
	_player->ftMovePosition(-_player->ftReturnCtMoveX(), -120);
	DrawTextureEx(_player->ftReturnGoodImage("Idle Ri", 0),
	_player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
	_player->ftMovePosition(_player->ftReturnCtMoveX(), 120);
}

