#include "raylib.h"
#include <stdio.h>
#include <string.h>

struct character{
  int health;
  Texture2D texture;
  int frameWidth;
  int currentFrameCount;
  Rectangle rectangle;
  Vector2 position;
  int speed;
  char* direction;
  int animIdleFrames;
  char* animIdle;
  int  animWalkFrames;
  char* animWalk;
};

struct character createPlayer(int screenWidth, int screenHeight) {
  struct character player;
  player.health = 100;
  player.direction = "right";


  player.animIdleFrames = 1;
  player.animIdle = "../assets/player/player-idle.png";  

  player.animWalkFrames = 5;
  player.animWalk = "../assets/player/player-walk.png";  
    
  player.texture = LoadTexture(player.animIdle);
  player.currentFrameCount = player.animIdleFrames;
  player.frameWidth = player.texture.width/player.currentFrameCount;
  
  Rectangle rectangle = {0.0f, 0.0f, (float) player.frameWidth, (float)player.texture.height};
  player.rectangle = rectangle;
  
  Vector2 position = {(float) screenWidth/2, (float) screenHeight/2};
  player.position = position;

  player.speed = 5;
  
  return player;
}

struct character changeCharAnimation(struct character character, char* direction, char* animPath, int frameCount){
  if(strcmp(direction, character.direction) != 0 && strcmp(direction, "-") != 0) {
    character.rectangle.width = -character.rectangle.width;
  }

  if(strcmp(direction, "-") != 0) {
    character.direction = direction;
  }

  character.texture = LoadTexture(animPath);
  character.currentFrameCount = frameCount;

  character.frameWidth = character.texture.width/character.currentFrameCount;
  
  return character;
}
