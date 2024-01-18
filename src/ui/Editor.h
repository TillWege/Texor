//
// Created by tillw on 18/01/2024.
//

#ifndef TEXOR_EDITOR_H
#define TEXOR_EDITOR_H

#include "../core/File.h"
#include <vector>
#include "TopBar.h"
#include "StatusBar.h"

class Editor
{
private:
	Files files = {};
	File* currentFile = nullptr;
	int currentLine = 0;
	int currentCol = 0;

	TopBar topBar;
	StatusBar statusBar;
public:
	Editor();

	void draw();
	void handleControls();
};


#endif //TEXOR_EDITOR_H
