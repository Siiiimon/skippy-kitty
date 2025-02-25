/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "stdlib.h"
#include "raylib.h"
#include "screens.h"
#include "ground/ground.h"
#include "world/enemies/puddle.h"
#include "world/player.h"
#include "util.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
float scroll_speed_factor = 130.0f;
static int finishScreen = 0;
Image perlinImage;
Texture2D perlinTex;
struct Ground* ground;
struct Player* player;
struct Puddle* puddle;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    ground = NewGround(0, GetScreenHeight() - 150, GetScreenWidth(), 150);
    player = NewPlayer(CLITERAL(Vector2){120, ground->rect.y});
    puddle = NewPuddle(CLITERAL(Vector2){370, ground->rect.y});
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    framesCounter++;
    float scroll = GetFrameTime() * scroll_speed_factor;
    debug_lines = 0;
    UpdateGround(ground, framesCounter*4);
    UpdatePlayer(player, ground->rect.y);
    UpdatePuddle(puddle, scroll);

    // Press enter or tap to change to ENDING screen
    // if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    // {
    //     finishScreen = 1;
    //     PlaySound(fxCoin);
    // }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    DebugText(TextFormat("FPS: %d", GetFPS()));
    DrawGround(ground, WHITE);
    DrawPlayer(player);
    DrawPuddle(puddle);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    UnloadGround(ground);
    FreePlayer(player);
    FreePuddle(puddle);
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
