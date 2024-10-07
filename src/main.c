#include "raylib.h" 
#include <stdio.h>
#include <string.h>
#include "character.c"
#include "map.c"

int screenWidth = 800;
int screenHeight = 450;

#define SCREEN_WIDTH (screenWidth)
#define SCREEN_Height (screenHeight)
#define WINDOW_TITLE "Ludum Dare 56 - Tiny Creatures"

int main() {
  InitWindow(screenWidth, screenHeight ,  WINDOW_TITLE);

  unsigned frameCounter = 0;
  unsigned frameDelayCounter = 0;
  unsigned frameDelay = 5;

  SetTargetFPS(60); 

  
  struct character player = createPlayer(screenWidth, screenHeight);
  Vector2 avatarPos = {(float) 1, (float) screenHeight-65};

  //Map
  const cJSON *mapJson = loadMap("../assets/map/map.json");
  struct cJSON *layers = cJSON_GetObjectItem(mapJson, "Layers");

  int tileSize = cJSON_GetObjectItem(mapJson, "tileSize")->valueint;

  struct cJSON *floorLayer = cJSON_GetArrayItem(layers, 2);
  struct cJSON *wallLayer = cJSON_GetArrayItem(layers, 1);
  struct cJSON *itemLayer = cJSON_GetArrayItem(layers, 0);

  struct textureRec* floorTexRec = getMapLayer("../assets/map/tilemap.png", floorLayer, tileSize);
  
  while(!WindowShouldClose()) {
   // 1. Event Handling
    if (IsKeyDown(KEY_RIGHT)) {
      player = changeCharAnimation(player, "right", player.animWalk, player.animWalkFrames);
      player.position.x += player.speed;
    } 
    if (IsKeyDown(KEY_LEFT)) {
      player = changeCharAnimation(player, "left", player.animWalk, player.animWalkFrames);
      player.position.x -= player.speed;
    } 
    if (IsKeyDown(KEY_UP)){
      player = changeCharAnimation(player, "-", player.animWalk, player.animWalkFrames);
      player.position.y -= player.speed;
    } 
    if (IsKeyDown(KEY_DOWN)){
      player = changeCharAnimation(player, "-", player.animWalk, player.animWalkFrames);
      player.position.y += player.speed;
    } 
    if(IsKeyDown(KEY_DOWN) == 0 && IsKeyDown(KEY_UP) == 0 && IsKeyDown(KEY_LEFT) == 0 && IsKeyDown(KEY_RIGHT) == 0) {
      if(strcmp(player.direction, "right")) {
        player = changeCharAnimation(player, player.direction, player.animIdle, player.animIdleFrames);
      } else player = changeCharAnimation(player, player.direction, player.animIdle, player.animIdleFrames);
    }

    printf("\n%d\n", IsKeyDown(KEY_DOWN)); 
      
    // 2. Update Positions

    ++frameDelayCounter;

    if(frameDelayCounter >= frameDelay) {
      ++frameCounter;
      frameDelayCounter = 0;

      frameCounter %= player.currentFrameCount;
      player.rectangle.x = (float) player.frameWidth * frameCounter;
    }
    
    
    // 3. Drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircle(20, 20, 5, RED);

    DrawTextureRec(player.texture, player.rectangle, player.position, WHITE);
            
    EndDrawing();
  }
  return 0;
}
