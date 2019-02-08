// API Class.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "API Class.h"
#include "CMainGame.h"
#include "Player.h"
#define MAX_LOADSTRING 100
#define PI 3.141592

CMainGame MainGame;
Player user;

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_APICLASS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_APICLASS));

	MSG msg;

	user.PlayerMoveInfo();

	if (MainGame.init() == E_FAIL)
	{
		return 0;
	}


	//기본 메시지 루프입니다:
	// while (GetMessage(&msg, nullptr, 0, 0))
	// {
	//     if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
	//     {
	//         TranslateMessage(&msg);
	//         DispatchMessage(&msg);
	//     }
	   //else
	   //{
	   //}
	// }
	msg.message = WM_NULL;

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			MainGame.Update();
			MainGame.Render();
		}
	}
	return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance) //윈도우 설정해주는 함수
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APICLASS));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_APICLASS);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int x = 100;
	static int y = 100;
	static int jmp_up = 0;
	static int jmp_down = 0;
	static int currentSpeed = 5;

	POINT Npc_1;

	Npc_1.x = 300;
	Npc_1.y = 300;


	static POINT sPt[3], ePt[3];
	static POINT posinPt;
	static float fAngle = 0.f;
	static float flen = 0;

	switch (message)
	{
	case WM_CREATE:
	{
		sPt[0].x = 100, sPt[0].y = 100;
		ePt[0].x = 500, ePt[0].y = 500;


		sPt[1].x = 500, sPt[1].y = 500;
		ePt[1].x = 800, ePt[1].y = 500;

		sPt[2].x = 800, sPt[2].y = 500;
		ePt[2].x = 1200, ePt[2].y = 100;

		//posinPt.x = x, posinPt.y = y-100;


		SetTimer(hWnd, 1, 30, NULL);

		//float fRadian = fAngle * PI / 180.f;

	}
	break;
	case WM_TIMER:
	{
		//점프
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && jmp_up == 0 && jmp_down == 0)
		{
			jmp_up = 100;
		}
		if (jmp_up != 0)
		{
			jmp_up -= 5;
			y -= 5;
			jmp_down += 5;
		}
		if (jmp_up == 0 && jmp_down != 0)
		{
			jmp_down -= 5;
			y += 5;
		}
		//while (jmp_down > 0)
		//{
		//	if (jmp_down > 0)
		//	{
		//		y++;
		//		jmp_down--;
		//	}
		//	InvalidateRect(hWnd, NULL, TRUE);
		//}
	}
	InvalidateRect(hWnd, NULL, TRUE);
	break;
	case WM_LBUTTONDOWN:
	{
		RECT rect;
		POINT pt;


		GetCursorPos(&pt);

		ScreenToClient(hWnd, &pt);

		//pt.x;
		//pt.y;

		if (((pt.x > x) && (pt.x < x + 100)) && ((pt.y > y) && (pt.y < y + 100)))
		{
			MessageBox(hWnd, L"마우스 왼쪽 버튼을 눌렀습니다", L"메시지 박스", MB_OK);
		}

		//if()
		/*if( ( pt.x > 100 && pt.x < 200 ) && (pt.y > 100 && pt.y < 200) )
		{
			MessageBox(hWnd, L"마우스 왼쪽 버튼을 눌렀습니다", L"메시지 박스", MB_OK);
		}*/
	}
	break;
	case WM_KEYDOWN:
	{
		/*
			MoveToEx(hdc, 500, 500, NULL);
			LineTo(hdc, 100, 100);
		*/
		switch (wParam)
		{
		case VK_SHIFT:
		{
			if (user.getCheckShift() == false)
			{
				user.setCheckShift(true);
				break;
			}
			else if (user.getCheckShift() == true)
			{
				user.setCheckShift(false);
				break;
			}
		}
		case VK_UP:
		{
			// 라디안값 * 180 / PI ->육십분법 각을 호도법으로 바꿔주는 공식
			float fRadian = fAngle * PI / 180.f;

			posinPt.x = cos(fRadian) * 100;
			posinPt.y = sin(fRadian) * 100;

			if (fAngle > 360.f)
				fAngle = 0.f;

			fAngle += 5.f;

		}
		break;
		case VK_LEFT:
		{
			if (user.getCheckShift() == false)
			{
				x -= user.getDefaultSpeed();
			}
			else
			{
				x -= user.getFastSpeed();
			}

			float a = 0;
			float b = 0;
			
			
			//대각선
			if (x > sPt[0].x && x < ePt[0].x)
			{
				// 기울기 = (x의 증가량) / (y의 증가량) --> (x1 - x2) / (y1 - y2)
				a = (float)(sPt[0].y - ePt[0].y) / (sPt[0].x - ePt[0].x);
				b = -a * ePt[0].x + ePt[0].y;
			}

			//직선
			else if (x >= sPt[1].x && x <= ePt[1].x)
			{
				// y증가량 / x증가량 = 기울기
				a = (float)(sPt[1].y - ePt[0].y) / (sPt[1].x - ePt[1].x);
				b = -a * sPt[1].x + sPt[1].y;
			}

			if (x >= sPt[2].x && x <= ePt[2].x)
			{
				//y = ax + b
				//기울기
				a = (float)(sPt[2].x - ePt[2].x) / (sPt[2].y - ePt[2].y);
				b = -a * sPt[2].x + sPt[2].y;
			}

			y = a * x + b;
		}
		break;
		case VK_RIGHT:
		{
			if (user.getCheckShift() == false)
			{
				x += user.getDefaultSpeed();
			}
			else
			{
				x += user.getFastSpeed();
			}

			float a = 0;
			float b = 0;
			//if(sPt[0].x < x && ePt[0].x > x)
			if (x > sPt[0].x && x < ePt[0].x)
			{
				// y증가량 / x증가량 = 기울기
				a = (float)(sPt[0].y - ePt[0].y) / (sPt[0].x - ePt[0].x);
				b = -a * sPt[0].x + sPt[0].y;
			}
			else if (x >= sPt[1].x && x <= ePt[1].x)
			{
				// y증가량 / x증가량 = 기울기
				a = (float)(sPt[1].y - ePt[0].y) / (sPt[1].x - ePt[1].x);
				b = -a * sPt[1].x + sPt[1].y;
			}

			if (x > sPt[2].x && x < ePt[2].x)
			{
				//y = ax + b
				//기울기
				a = (float)(sPt[2].x - ePt[2].x) / (sPt[2].y - ePt[2].y);
				b = (-a * sPt[2].x) + sPt[2].y;
			}

			y = a * x + b;
		}
		break;
		}
		//클라이언트 영역 무효화 시켜서 WM_PAINT 메세지 발생시킨다.
		InvalidateRect(hWnd, NULL, TRUE);
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, x - 50, y - 50, x + 50, y + 50); //사각형 그리는 함수5
		//Rectangle(hdc, Npc_1.x, Npc_1.y, Npc_1.x + 50, Npc_1.y + 50); //사각형 그리는 함수
		//Ellipse(hdc, 500, 500, 550, 550); 원그리는 함수

		//MovetoEx: start Pointer move
		//Lineto: draw line to end pointer

		//선그리는 함수

		for (int i = 0; i < 3; i++)
		{
			MoveToEx(hdc, ePt[i].x, ePt[i].y, NULL);
			LineTo(hdc, sPt[i].x, sPt[i].y);
		}

		/*MoveToEx(hdc, 800, 500, NULL);
		LineTo(hdc, 500, 500);*/

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}