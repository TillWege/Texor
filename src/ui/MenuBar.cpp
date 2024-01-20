//
// Created by tillw on 18/01/2024.
//

#include "MenuBar.h"
#include "raylib.h"
#include "./raygui.h"

MenuBar::MenuBar()
{
	int newButtonWidth = MeasureText(newButtonCaption, fontSize);
	newButtonRect = { 0, 0, (float)((2 * paddingHor) + newButtonWidth), (float)height };

	int infoButtonWidth = MeasureText(infoButtonCaption, fontSize);
	infoButtonRect =
		{ newButtonRect.x + newButtonRect.width, 0, (float)((2 * paddingHor) + infoButtonWidth),
		  (float)height };
}

void MenuBar::draw()
{
	if (GuiButton(newButtonRect, newButtonCaption) && onNewFileClicked != nullptr) onNewFileClicked();

	if (GuiButton(infoButtonRect, infoButtonCaption))
	{
		showDlg = true;
	}

	if (showDlg)
	{
		if (GuiMessageBox({ 100, 100, 200, 200 }, "Hello", "World", "Closed") != -1)
		{
			showDlg = false;
		}

	}

	float end = infoButtonRect.x + infoButtonRect.width;
	GuiDummyRec({ end, 0, (float)GetRenderWidth() - end, (float)height }, "");
}