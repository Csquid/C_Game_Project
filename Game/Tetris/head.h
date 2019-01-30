#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "struct.h"

void Clear(void);
void ConfigMap(int*** dPointer);
void GotoXY(Pos nPos);
void SetColor(unsigned char _BgColor, unsigned char _TextColor);
void SetConsoleSize(Pos ConsolePos);

#endif