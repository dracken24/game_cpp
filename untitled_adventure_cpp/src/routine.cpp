#include "../myIncludes/player.hpp"
#include "../myIncludes/game.hpp"
#include "../myIncludes/menu.hpp"

void ftRoutine(Game *Game, Player *player, Camera2D *camera)
{
    static int i;
    static int k;
    static int cameraOption = 0;

    if (!i)
        i = 0;

    EnvItem envItems[] = {
        {{0, 0, 1000, 400}, 0, LIGHTGRAY},
        {{0, 400, 1000, 200}, 1, GRAY},
        {{300, 200, 400, 10}, 1, GRAY},
        {{250, 300, 100, 10}, 1, GRAY},
        {{650, 300, 100, 10}, 1, GRAY},
        {{-850, 550, 700, 25}, 1, GRAY},
        {{1100, 380, 400, 13}, 1, GRAY},
        {{700, 100, 150, 10}, 1, GRAY},
        {{450, 500, 180, 15}, 1, GRAY}};

    int envItemsLength = sizeof(envItems) / sizeof(envItems[0]);

    k = player->ftReturnCt();
    if (i >= 60 || k != player->ftReturnCt())
        i = 0;
    float deltaTime = GetFrameTime();

    Game->cameraUpdaters[cameraOption](camera, player, envItems, envItemsLength, deltaTime, Game->screenWidth, Game->screenHeight);

    ftUpdatePlayer(player, envItems, envItemsLength, deltaTime);
    if (k != player->ftReturnCt())
        i = 0;

    camera->zoom += ((float)GetMouseWheelMove() * 0.05f);

    if (camera->zoom > 3.0f)
        camera->zoom = 3.0f;
    else if (camera->zoom < 0.25f)
        camera->zoom = 0.25f;
    if (IsKeyPressed(KEY_R))
    {
        camera->zoom = 1.0f;
        player->ftSetPosition({500.0f, 300.0f});
    }

    for (int i = 0; i < envItemsLength; i++)
        DrawRectangleRec(envItems[i].rect, envItems[i].color);

    ftImgsGestion(player, &i);

    DrawText("Controls:", 20, 20, 10, BLACK);
    DrawText("- Right/Left to move", 40, 40, 10, DARKGRAY);
    DrawText("- Space to jump", 40, 60, 10, DARKGRAY);
    DrawText("- Mouse Wheel to Zoom in-out, R to reset zoom", 40, 80, 10, DARKGRAY);
}
