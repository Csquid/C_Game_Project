#include "head.h"

void Clear(void)
{
	system("cls");
}

void GotoXY(Pos nPos)
{
	COORD pos = { nPos.x * 2, nPos.y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(int color, int bgColor)
{
	color &= 0xf;
	bgColor &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | color);
}

void SetConsoleSize(Pos ConsolePos)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", ConsolePos.x, ConsolePos.y);
	system(setText);
}