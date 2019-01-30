#include "head.h"

int main()
{
	Pos *arrowPos = (Pos*)malloc(sizeof(Pos));
	Map *pMap = (Map *)malloc(sizeof(map));
	Menu proMenu;

	arrowPos->setPos(ARROW_X, ARROW_Y);
	Window_Size_Config(Default_Window_Config);

	int menu_chose = 0;
	int checkNumber = 0;

	while (1)
	{
		proMenu.Menu_Title();
		proMenu.Menu_Content();

		menu_chose = Move_Arrow(arrowPos);
		pMap->Menu();

		printf("\nChoose Map\n");
		Sleep(50);
		system("cls");

		if (menu_chose != 0)
		{
			while (1)
			{
				Window_Size_Config(menu_chose);

				Pos* mapPos = (Pos*)malloc(sizeof(mapPos));
				Pos userInfo_xy(1, 1);
				mapPos->x = 0;
				mapPos->y = 0;

				char mapPath[25] = "./maps/";
				const char* mapDefault = "default.txt";
				const char* mapPattern = "pattern.txt";
				const char* mapScroll = "scroll.txt";

				int checkEscape = -1;
				int **dPointer;

				switch (menu_chose)
				{
				case 1:
					strcat_s(mapPath, sizeof(mapPath), mapDefault);
					mapLoding(&dPointer, mapPath, &mapPos);

					while (1)
					{
						pMap->DrawMap(*mapPos, dPointer);
						checkEscape = Move_Character(*mapPos, &userInfo_xy, 1, dPointer);
						Sleep(33);
						if (checkEscape == -1)
						{
							break;
						}
					}
					break;
				case 2:
					strcat_s(mapPath, sizeof(mapPath), mapPattern);
					mapLoding(&dPointer, mapPath, &mapPos);

					while (1)
					{
						pMap->DrawMap(*mapPos, dPointer);
						checkEscape = Move_Character(*mapPos, &userInfo_xy, 2, dPointer);
						Sleep(66);
						if (checkEscape == -1)
						{
							break;
						}
					}
					break;
				case 3:
					int** curMapLocation;
					int curMapMax_X = 20;
					int curMapMax_Y = 10;
					int userMoveMax_Right_X = 12;
					int userMoveMax_LEFT_X = 8;

					Pos* curMapPos = (Pos*) malloc (sizeof(Pos));
					curMapPos->setPos(curMapMax_X, curMapMax_Y);

					strcat_s(mapPath, sizeof(mapPath), mapScroll);
					mapLoding(&dPointer, mapPath, &mapPos);

					curMapLocation = (int**)malloc(sizeof(int) * curMapMax_Y);

					for (int i = 0; i < curMapMax_Y; i++)
					{
						curMapLocation[i] = (int*)malloc(sizeof(int) * curMapMax_X);
					}

					int xMax = 0;

					while (1)
					{
						for (int i = 0; i < curMapMax_Y; i++)
						{
							for (int j = 0; j < curMapMax_X; j++)
							{
								curMapLocation[i][j] = dPointer[i][j + xMax];
							}
						}

						int jmp_up = 0;
						int jmp_down = 0;

						while (1)
						{
							Sleep(66);
							pMap->DrawMap(*curMapPos, curMapLocation);
							checkEscape = Move_Character(*mapPos, &userInfo_xy, 1, curMapLocation);
							printf("xMax: %d \n", xMax);
							printf("curMapLocation: [%d, %d]\n", userInfo_xy.x, userInfo_xy.y);
							
							if (GetAsyncKeyState(VK_SPACE) && jmp_up == 0)
							{
								if (curMapLocation[userInfo_xy.y - 2][userInfo_xy.x] == 1)
									jmp_up = 1;
								else
									jmp_up = 4;
							}
							if (jmp_up != 0 && (curMapLocation[userInfo_xy.y - 1][userInfo_xy.x] != 1))
							{
 								//jmp_down++;
								(userInfo_xy.y) -= 1;
								jmp_up--;
							}
							/*if ((jmp_down != 0 && jmp_up == 0))
							{
								(userInfo_xy.y) += 1;
								jmp_down--;
							}*/
							if (((userInfo_xy.y != curMapMax_Y - 2) && jmp_up == 0))
							{
								if(curMapLocation[userInfo_xy.y + 1][userInfo_xy.x] != 1)
									(userInfo_xy.y) += 1;
							}

							if (userInfo_xy.x > userMoveMax_Right_X && xMax < (mapPos->x - curMapMax_X))
							{
								(userInfo_xy.x) -= 1;
								++xMax;
								break;
							}
							else if (userInfo_xy.x < userMoveMax_LEFT_X && xMax > 0)
							{
								(userInfo_xy.x) += 1;
								--xMax;
								break;
							}
							if (checkEscape == -1)
							{
								break;
							}
						}

						if (checkEscape == -1)
						{
							break;
						}
					}
					break;
				}
				break;
			}
		}
		//free(pMap);

	}
}