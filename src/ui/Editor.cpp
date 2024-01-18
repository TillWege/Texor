//
// Created by tillw on 18/01/2024.
//

#include "Editor.h"
#include "raylib.h"

Editor::Editor()
{
	topBar = TopBar();
	statusBar = StatusBar();
}

void Editor::draw()
{
	int height = GetRenderHeight();
	int width = GetRenderWidth();
	BeginScissorMode(0, 0, width, topBar.height);
	{
		topBar.draw();
	}
	EndScissorMode();

	BeginScissorMode(0, topBar.height, width, height - (topBar.height + statusBar.height));
	{
		DrawLine(0, topBar.height, GetRenderWidth(), topBar.height, RED);

		DrawLine(0, height - (statusBar.height + 1), GetRenderWidth(), height - (statusBar.height + 1), BLUE);
	}
	EndScissorMode();

	BeginScissorMode(0, height - (statusBar.height), width, statusBar.height);
	{
		statusBar.draw();
	}
	EndScissorMode();
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
