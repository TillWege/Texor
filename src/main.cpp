#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include "./ui/Editor.h"
#include "./ui/raygui.h"
int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "Texor");
	GuiLoadStyleDefault();
	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);


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