#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"


struct Background {
    int width;
    int height;
};
struct Tile {
    int length;
    int x;
    int y;

};
struct Position {
    int x;
    int y;
};
struct Snake {
   Position head_pos;
   int length; 
};




int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    Background bg {.width = 800, .height = 800};
    const int dist_tile = 93;


    std::vector<Tile> tiles;
    for (int row = 0; row < 10; row++) {
        for (int i = 0; i < 10; i++) {
            tiles.emplace_back(Tile{.length = 90, .x = 50+dist_tile*i, .y = 50+dist_tile*row});
        }
    }

    InitWindow(screenWidth, screenHeight, "Emils Snake Game");
    SetTargetFPS(60);               



    while (!WindowShouldClose())    
    {

        ClearBackground(RAYWHITE);
        BeginDrawing();
        for (const auto &tile : tiles) {
            DrawRectangle(tile.x, tile.y, tile.length, tile.length, DARKGREEN);
        } 
        for (int i = 0; i < 3; i++) {
            DrawRectangle(tiles[i].x, tiles[i].y, tiles[i].length, tiles[i].length, GREEN);
        }

        EndDrawing();

    }

    CloseWindow();        

    return 0;
}
