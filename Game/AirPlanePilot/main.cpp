#include "head.h"
#include "struct.h"

DWORD mainThreadID;

int main()
{
	mainThreadID = GetCurrentThreadId();

	FILE* fp = (FILE*) malloc (sizeof(FILE));
	Pos ConsolePos;
	Pos mapMaxPos;
	Pos PlanePos;
	Pos Monster;

	Node* tail = nullptr;
	Node* cur = nullptr;

	int** dpMapArray;

	fopen_s(&fp, "./maps/default.txt", "rt");
	fscanf_s(fp, "%d %d", &mapMaxPos.x, &mapMaxPos.y);
	
	dpMapArray = (int**)malloc(sizeof(int) * mapMaxPos.y);

	InitDpMapArray(dpMapArray, mapMaxPos, fp);
	InitConfig(&ConsolePos, &PlanePos);

	while (1)
	{
		Show_Map(mapMaxPos, dpMapArray);
		Move_AirPlane(&PlanePos, mapMaxPos.x);
		Bullet(PlanePos, &tail, cur);
		Show_Monster();
		Sleep(66);
		Clear();
	}

	fclose(fp);
	free(dpMapArray);

	return 0;
}