#include "head.h"
#include "struct.h"

static int threadCounter;
Pos* bullets;

extern DWORD mainThreadID;

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

void Show_Monster()
{
	for (int i = 0; i < 5; i++)
	{
		Pos gotoPos;
		gotoPos.setPos(i, 1);
		GotoXY(gotoPos);

		printf("■");
	}
}

void Show_Map(Pos nMaxPos, int** mapArray)
{
	for (int i = 0; i < nMaxPos.y; i++)
	{
		for (int j = 0; j < nMaxPos.x; j++)
		{
			Pos gotoPos;
			gotoPos.setPos(j, i);

			GotoXY(gotoPos);
			if (mapArray[i][j] == 1)
			{
				printf("■");
			}
			else if (mapArray[i][j] == 0)
			{
				printf("  ");
			}
		}
	}
}

void InitDpMapArray(int** dpMap, Pos mapMaxPos, FILE* fp)
{
	for (int i = 0; i < mapMaxPos.y; i++)
	{
		dpMap[i] = (int*)malloc(sizeof(int) * mapMaxPos.x);
	}

	for (int i = 0; i < mapMaxPos.y; i++)
	{
		for (int j = 0; j < mapMaxPos.x; j++)
		{
			fscanf_s(fp, "%d", &dpMap[i][j]);
		}
	}
}

void InitConfig(Pos* consoleSizePos, Pos* planePos)
{
	consoleSizePos->setPos(CONSOLE_X, CONSOLE_Y);
	SetConsoleSize(*consoleSizePos);

	planePos->setPos(PLANE_X, PLANE_Y);
	SetCursor(FALSE);
}

void Move_AirPlane(Pos* airPlanePos, int mapMax_Width)
{
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && airPlanePos->x > 1)
	{
		airPlanePos->x -= 1;
	}
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && airPlanePos->x <= mapMax_Width - 3)
	{
		airPlanePos->x += 1;
	}
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		bullets = (Pos*) malloc (sizeof(Pos));
		bullets->setPos(airPlanePos->x, (airPlanePos->y) - 1);
		GotoXY(*bullets);
		printf("│");

		//쓰래드 호출
		ConfigThread(bullets);
	}

	GotoXY(*airPlanePos);
	printf("▲");
}

void ConfigThread(Pos* bullets)
{
	HANDLE hThrd;
	DWORD threadID;
	Pos threadCounterPos;

	//LPVOID = void*
	hThrd = CreateThread(NULL, 0, ThreadFunc, (LPVOID)bullets, 0, &threadID);

	//ThreadFunc(bullets);
}

DWORD WINAPI ThreadFunc(LPVOID data)
{
 	Pos* nPos = (Pos*)data;
	int a = 0;

	while (1)
	{
		if (nPos->y <= 1)
		{
			break;
		}

		GotoXY(*nPos);
		printf(" ");

		Sleep(33);

		nPos->y -= 1;
		nPos->setPos(nPos->x, nPos->y);

		GotoXY(*nPos);
		printf("│");

		Sleep(33);
	}
	
	if (GetCurrentThreadId() != mainThreadID)
	{
		free(nPos);
	}

	return 0;
}

void Launch_Bullets()
{

}