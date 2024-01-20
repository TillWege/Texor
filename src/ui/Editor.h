//
// Created by tillw on 18/01/2024.
//

#ifndef TEXOR_EDITOR_H
#define TEXOR_EDITOR_H

#include "../core/File.h"
#include <vector>
#include "MenuBar.h"
#include "StatusBar.h"
#include "raylib.h"

class Editor
{
private:
	Files files = {};
	File* currentFile = nullptr;
	int currentLine = 0;
	int currentCol = 0;

	MenuBar menuBar;
	StatusBar statusBar;
public:
	Editor();

	void draw();
	void drawEditorTabs(Rectangle rec);
	void handleControls();

	void newFile();
};


#endif //TEXOR_EDITOR_H
