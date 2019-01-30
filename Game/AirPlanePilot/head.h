#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "struct.h"

#define CONSOLE_X 40
#define CONSOLE_Y 30

#define PLANE_X 7
#define PLANE_Y 23

enum Color
{
	Black = 0,
	White = 7,
	Blue = 9,
	Green,
	Sky,
	Red,
	Purple,
	Yello
};

void Clear(void);
void GotoXY(Pos nPos);
void SetTitle(const char* _szConsoleName);
void SetColor(unsigned char _BgColor, unsigned char _TextColor);
void SetCursor(BOOL _bShow);

//default Value []
void Bullet(Pos PlanePos, Node** tail, Node* cur);
void SetConsoleSize(Pos ConsolePos);
void Show_Monster();
void Show_Map(Pos nMaxPos, int** mapArray);
void InitDpMapArray(int** dpMap, Pos mapMaxPos, FILE* fp);
void InitConfig(Pos* consoleSizePos, Pos* planePos);
void Move_AirPlane(Pos* airPlanePos, int mapMax_Width);

//CirCle_Doubly_Linked_List
void Linked_Insert(Node** tail, Pos planePos);
void Linked_Search(Node* tail, Node* cur);
void Linked_Delete(Node** tail, Node* cur);
void Linked_PrintNode(Node* tail, Node* cur);
void Linked_Free(Node** tail, Node* cur);