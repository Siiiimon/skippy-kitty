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

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
int noiseWidth = 0;
int noiseHeight = 250;
int noiseY = 0;
Image perlinImage;
Texture2D perlinTex;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    noiseWidth = GetScreenWidth();
    noiseY = GetScreenHeight() - noiseHeight;
    perlinImage = GenImagePerlinNoise(noiseWidth, noiseHeight, 0, 0, 4.0f);
    perlinTex = LoadTextureFromImage(perlinImage);
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    framesCounter++;
    perlinImage = GenImagePerlinNoise(noiseWidth, noiseHeight, framesCounter, 0, 4.0f);
    UpdateTexture(perlinTex, perlinImage.data);

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
    DrawTexture(perlinTex, 0, noiseY, WHITE);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    UnloadTexture(perlinTex);
    UnloadImage(perlinImage);
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
