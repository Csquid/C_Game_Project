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

void SetTitle(const char* _szConsoleName)
{
	printf("Call SetTitle \n");
	SetConsoleTitle(L"TEST");
}

void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void SetCursor(BOOL _bShow)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void SetConsoleSize(Pos ConsolePos)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", ConsolePos.x, ConsolePos.y);
	system(setText);
}
