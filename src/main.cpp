#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"


struct Background {
    int width;
    int height;
};
struct Tile {
    int width;
    int height;
    int x;
    int y;

};
std::ostream& operator<<(std::ostream &os, Tile t) {
        os << "Width: " << t.width << std::endl;
        os << "Height: " << t.height << std::endl;
        os << "x: " << t.x << std::endl;
        os << "y: " << t.y << std::endl;
        return os;
}




int main(void)
{


    const int screenWidth = 1250;
    const int screenHeight = 1250;
    Background bg (1000, 1000);
    std::vector<Tile> tiles;
    for (int row = 0; row < 10; row++) {
        for (int i = 0; i < 10; i++) {
            tiles.emplace_back(Tile(10, 10, 250+10*i, 250+row*10));
        }
    }
    


       InitWindow(screenWidth, screenHeight, "Emils Snake Game");


    SetTargetFPS(60);               
    // for (auto t : tiles) {std::cout << t;}



    while (!WindowShouldClose())    
    {

        ClearBackground(RAYWHITE);
        BeginDrawing();
        for (const auto &tile : tiles) {
            DrawRectangle(tile.x, tile.y, tile.width, tile.height, GREEN);
        } 
        EndDrawing();



    }

    CloseWindow();        

    return 0;
}
