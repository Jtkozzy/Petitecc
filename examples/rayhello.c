// To compile this, you need raylib obviously :)
// I have it in my home directory $HOME/raylib and both raylib.h and
// libraylib.a are in my $HOME/raylib/src
// So, in that scenario, compile / link:
// ./petitecc -o=rayhello -I=$HOME/raylib/src -L=$HOME/raylib/src/ -l=m -l=X11 examples/rayhello.c libraylib.a

#include <raylib.h>
#include <stdio.h>

int main() { 
    InitWindow(800, 600, "Hello from Petitecc!");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();    
    }

    return 0; 
}

