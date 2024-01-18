#include "raylib.h"
#include "./ui/Editor.h"

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "Texor");

	Editor edit = Editor();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		edit.draw();
		EndDrawing();

		edit.handleControls();
	}

	CloseWindow();

	return 0;
}