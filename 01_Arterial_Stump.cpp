
#include "raylib.h"

#include <vector>

struct vessel {
    Vector3 start;
    Vector3 end;
    float radius; 
};
int main (){
    std::vector<vessel> tree;
        tree.push_back({{ 0 , 0 , 0  } , { 0 , 2 , 0 } ,  0.5f });
    // 1. Define the camera
    Camera3D camera = { 0 };
    camera.position = { 5.0f, 5.0f, 5.0f }; // Modern brace initialization
    camera.target = { 0.0f, 1.0f, 0.0f };   // Looking at the middle of the stump
    camera.up = { 0.0f, 1.0f, 0.0f };       // Y-axis is UP
    camera.fovy = 45.0f;                    // Perspective angle
    camera.projection = CAMERA_PERSPECTIVE;
    InitWindow(800,600 , "vascular");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);

            for (const auto& v : tree){
                DrawCylinderEx(v.start , v.end , v .radius , v.radius , 8 , MAROON);

            }
            DrawGrid(10 , 1.0f);
        EndMode3D();
    EndDrawing();
    }
    
    return 0 ;
    
}
