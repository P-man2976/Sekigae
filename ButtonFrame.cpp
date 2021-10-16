#include "function.h"
#include "DxLib.h"
#include <stdlib.h>

int Drawnumber;



void DrawFrame(int x1, int y1, int x2, int y2, int color, int FillFlag, int Thickness)
{

	for (Drawnumber = 0; Drawnumber < Thickness; Drawnumber++)
	{
		DrawBox(x1 + Drawnumber, y1 + Drawnumber, x2 - Drawnumber, y2 - Drawnumber, color, FillFlag);

		DrawBox(x1 - Drawnumber, y1 - Drawnumber, x2 + Drawnumber, y2 + Drawnumber, color, FillFlag);

	}



}