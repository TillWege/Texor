//
// Created by tillw on 18/01/2024.
//

#ifndef TEXOR_TOPBAR_H
#define TEXOR_TOPBAR_H
#include "functional"
#include "raylib.h"

class MenuBar
{
private:
	const char* newButtonCaption = "New File";
	Rectangle newButtonRect;

	const char* infoButtonCaption = "Info";
	Rectangle infoButtonRect;

	bool showDlg = false;
public:
	MenuBar();
	int height = 25;
	int paddingHor = 5;
	int paddingVert = 1;
	int fontSize = height - (2 * paddingVert);
	std::function<void()> onNewFileClicked = nullptr;
	void draw();
};


#endif //TEXOR_TOPBAR_H
