#include "../tools/cJSON.c"
#include <raylib.h>

struct textureRec {
  Rectangle rectangle;
  Vector2 position;
  Texture2D texture;
};

const cJSON *loadMap(char* mapPath) {
  FILE *fp = fopen(mapPath, "r"); 

  char buffer[1024]; 
  int len = fread(buffer, 1, sizeof(buffer), fp); 
  fclose(fp); 

  cJSON *mapJson = cJSON_Parse(buffer); 

  return mapJson;
}

struct textureRec* getMapLayer(char* tileMapPath, cJSON *layerJson, int tileSize) {
  struct textureRec* result;

  Texture2D texture = LoadTexture(tileMapPath);
  const cJSON *tileJson = cJSON_GetObjectItem(layerJson, "tiles");
  for (int i=0;i<cJSON_GetArraySize(tileJson)-1;i++) {
    cJSON *tileEl = cJSON_GetArrayItem(tileJson, i);
    struct textureRec newTextureRec;

    result[i] = newTextureRec;
  }

  return result;
}
