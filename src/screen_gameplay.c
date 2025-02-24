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
#include "player/player.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
Image perlinImage;
Texture2D perlinTex;
struct Ground* ground;
struct Player* player;

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
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    framesCounter++;
    UpdateGround(ground, framesCounter*4);
    UpdatePlayer(player);

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
    DrawGround(ground, WHITE);
    DrawPlayer(player);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    UnloadGround(ground);
    FreePlayer(player);
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
