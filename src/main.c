#include "raylib.h"

int screenWidth = 800;
int screenHeight = 450;

#define SCREEN_WIDTH (screenWidth)
#define SCREEN_Height (screenHeight)
#define WINDOW_TITLE "Ludum Dare 56 - Tiny Creatures"

int main() {
  InitWindow(screenWidth, screenHeight ,  WINDOW_TITLE);

  unsigned frameCounter = 0;
  unsigned frameDelayCounter = 0;
  unsigned frameDelay = 15;

  SetTargetFPS(60);

  
  
}
