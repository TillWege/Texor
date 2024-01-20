//
// Created by tillw on 18/01/2024.
//

#include "Editor.h"
#include "raylib.h"

Editor::Editor()
{
	menuBar = MenuBar();
	menuBar.onNewFileClicked = [this]
	{ newFile(); };
	statusBar = StatusBar();
}

void Editor::draw()
{
	int height = GetRenderHeight();
	int width = GetRenderWidth();
	//BeginScissorMode(0, 0, width, menuBar.height);
	{
		menuBar.draw();
	}
	//EndScissorMode();

	BeginScissorMode(0, menuBar.height, width, height - (menuBar.height + statusBar.height));
	{
		DrawLine(0, menuBar.height, GetRenderWidth(), menuBar.height, RED);

		drawEditorTabs({ 0, (float)menuBar.height + 1, (float)GetRenderWidth(), 20 });

		DrawLine(0, height - (statusBar.height + 1), GetRenderWidth(), height - (statusBar.height + 1), BLUE);
	}
	EndScissorMode();

	BeginScissorMode(0, height - (statusBar.height), width, statusBar.height);
	{
		statusBar.draw();
	}
	EndScissorMode();
}

void Editor::drawEditorTabs(Rectangle rec)
{
	if (files.empty() || currentFile == nullptr) return;

	DrawRectangleRec(rec, YELLOW);
}

void Editor::handleControls()
{

	return;

	if (IsKeyReleased(KEY_ENTER))
	{
		currentFile->data.emplace_back("");
		currentLine++;
	}

	if (IsKeyReleased(KEY_BACKSPACE))
	{
		if (!currentFile[currentLine].data.empty())
		{
			currentFile[currentLine].data.pop_back();
		}
	}

	if (IsKeyReleased(KEY_UP))
	{
		if (currentLine != 0)
		{
			currentLine -= 1;
		}
	}

	if (IsKeyReleased(KEY_DOWN))
	{
		if (currentLine != (currentFile->data.size() - 1))
		{
			currentLine += 1;
		}
	}

	bool running = true;
	while (running)
	{
		int val = GetCharPressed();
		if (val == 0)
		{
			running = false;
		}
		else
		{
			currentFile->data[currentLine] += char(val);
		}
	}
}
void Editor::newFile()
{
	File* f = new File();

	files.emplace_back(f);
	currentFile = f;
}
