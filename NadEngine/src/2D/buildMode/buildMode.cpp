#include "../../../myIncludes/game.hpp"

void	ftDrawAll(Game *oldGame, Player *_player, EnvItems *_envItems, Props *_blocks);

void	ftMoveScreen(Game *oldGame, Camera2D *camera)
{
	Vector2 mousePos = GetMousePosition();
	Vector2 lastPos = oldGame->mouse.pos;
	Vector2	forMove = {lastPos.x - mousePos.x, lastPos.y - mousePos.y};

	if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
	{
		oldGame->posCam.x += forMove.x / camera->zoom;
		oldGame->posCam.y += forMove.y / camera->zoom;
	}
	camera->zoom += ((float)GetMouseWheelMove() * 0.05f);
	if (camera->zoom > 3.0f)
		camera->zoom = 3.0f;
	else if (camera->zoom < 0.25f)
		camera->zoom = 0.25f;
}

void	ftRunBuildMode(Game *oldGame, Stop *buildGame, Camera2D *camera)
{
	static Player	*_player = buildGame->ftReturnPlayer();
	static EnvItems	*_envItems = buildGame->ftReturnEnvItems();
	static Props	*_blocks = buildGame->ftReturnBlocks();
	static int cameraOption = 0;

	ftMoveScreen(oldGame, camera);

	oldGame->ctImgBuildGame = 0;
	ftDrawAll(oldGame, _player, _envItems, _blocks); // Draw all imgs
	oldGame->cameraUpdaters[cameraOption](oldGame, camera, _player, _envItems->ftReturnEnviAllNbr(),
		oldGame->delta, oldGame->screenWidth, oldGame->screenHeight);
}

void	ftDrawAll(Game *oldGame, Player *_player, EnvItems *_envItems, Props *_blocks)
{
	for (int i = 0; i < _envItems->ftReturnEnviAllNbr(); i++)
		DrawRectangleRec(_envItems->ftReturnRectangle(i), _envItems->ftReturnEnviColor(i));

	for (int i = 0; i < _blocks->ftReturnNbr(); i++)
	{
		Rectangle	block = _blocks->ftReturnRectangleSqPr(i);
		DrawRectanglePro(block, (Vector2){block.width / 2, block.height / 2},
				0, _blocks->ftReturnRecColorSqPr(i));
	}

	DrawTextureEx(_player->ftReturnGoodImage("Idle Ri", oldGame->ct_action / _player->ftReturnCtIdle()),
		_player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
}
