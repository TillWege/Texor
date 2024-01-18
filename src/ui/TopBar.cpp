//
// Created by tillw on 18/01/2024.
//

#include "TopBar.h"
#include "raylib.h"

void TopBar::draw()
{
	// New File Button
	const char* newCaption = "New File";
	DrawText(newCaption, 5, 0, height, RED);
	int TextWidth = MeasureText(newCaption, height);
	int LinePos = TextWidth + 10;
	DrawLine(LinePos, 0, LinePos, height, RED);

}
