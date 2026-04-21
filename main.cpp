#include <vector>
#include "raylib.h"
#include "raymath.h"

// This function is "Majboor" (Compelled) to repeat until depth is 0
void GrowVascularTree(Vector3 start, Vector3 dir, float len, float rad, int depth) {
    // 1. THE TERMINAL CONDITION (The Wall)
    if (depth <= 0 || rad < 0.05f) return;

    // 2. COMPUTE THE SEGMENT
    Vector3 end = { 
        start.x + dir.x * len, 
        start.y + dir.y * len, 
        start.z + dir.z * len 
    };

    // 3. RENDER (The Blood-Maroon Vessel)
    DrawCylinderEx(start, end, rad, rad * 0.8f, 12, YELLOW);

    // 4. THE BIFURCATION (The Split)
    // We create two children, slightly tilted
    float angle = 30.0f * DEG2RAD; 
    
    // Left Branch
    Vector3 leftDir = Vector3RotateByAxisAngle(dir, {0, 0, 1}, angle);
    GrowVascularTree(end, leftDir, len * 0.75f, rad * 0.7f, depth - 1);

    // Right Branch
    Vector3 rightDir = Vector3RotateByAxisAngle(dir, {0, 0, 1}, -angle);
    GrowVascularTree(end, rightDir, len * 0.75f, rad * 0.7f, depth - 1);
} 

int main(){
    InitWindow(1200 , 800 , "VASCULAR TREE");

    Camera3D Camera = {0};
    Camera.position = (Vector3){ 10.0f , 10.0f , 10.0f};
    Camera.target = (Vector3){ 0.0f , 2.0f , 0.0f};
    Camera.up = (Vector3){0.0f , 1.0f , 0.0f};
    Camera.fovy = 45.0f;
    Camera.projection = CAMERA_PERSPECTIVE;
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        UpdateCamera(&Camera , CAMERA_ORBITAL);
        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode3D(Camera);
                DrawGrid(20,1.0f);
                GrowVascularTree({ 0 , 0 , 0 } , { 0 , 1 , 0}, 4.0f ,  0.3f , 8);
            EndMode3D();
            DrawFPS(10 ,10);
            DrawText("SYSTEM: VASCULAR SIMULATION ACTIVE" , 10 , 40 ,20 , GREEN);
        EndDrawing();
    }
    CloseWindow();
    return 0 ;

}