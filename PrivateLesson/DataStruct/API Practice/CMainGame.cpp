#include "stdafx.h"
#include "CMainGame.h"
#include "CPlayer.h"
#include "CEnemy.h"

CMainGame::CMainGame()
	: m_pPlayer(nullptr), m_PEnemy(nullptr)
{
}


CMainGame::~CMainGame()
{
}

HRESULT CMainGame::init(void)
{
	m_pPlayer = new CPlayer;
	if (m_pPlayer->init() == E_FAIL)
		return E_FAIL;

	m_PEnemy = new CEnemy;
	if (m_PEnemy->init() == E_FAIL)
		return E_FAIL;
	return S_OK;
}

void CMainGame::Update(void)
{
	static DWORD  dwNowTime = GetTickCount();



	if (dwNowTime + 5 <= GetTickCount())
	{
		dwNowTime = GetTickCount();
		m_pPlayer->Update();
		m_PEnemy->Update();
	}
}

void CMainGame::Render(void)
{
	InvalidateRect(g_hWnd, NULL, TRUE);
	HDC hdc = GetDC(g_hWnd);
	//Rectangle(hdc, 0, 0, 1000, 1000);
	m_pPlayer->Render(hdc);
	m_PEnemy->Render(hdc);
	ReleaseDC(g_hWnd, hdc);
}

void CMainGame::Release(void)
{
}
