#include "../../../myIncludes/game.hpp"

void	ftDrawAll(Game *oldGame, Player *_player, EnvItems *_envItems, Props *_blocks);

void	ftRunBuildMode(Game *oldGame, Stop *buildGame)
{
	// static Game		*_Game = buildGame->ftReturnGame();
	static Player	*_player = buildGame->ftReturnPlayer();
	static EnvItems	*_envItems = buildGame->ftReturnEnvItems();
	static Props	*_blocks = buildGame->ftReturnBlocks();
	oldGame->ctImgBuildGame = 0;
	ftDrawAll(oldGame, _player, _envItems, _blocks); // Draw all imgs
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
