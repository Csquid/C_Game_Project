#include "stdafx.h"
#include "CPlayer.h"
#include "CBullet.h"

#define VK_W 0x57
#define VK_S 0x53

CPlayer::CPlayer()
	: PLAYER_MAX_BULLET(100), m_iBulletCnt(0)
{

}

CPlayer::~CPlayer()
{
}

HRESULT CPlayer::init(void)
{
	float a = 0.f;
	float b = 0.f;

	m_PlayerInfo.m_Centerpos.x = 200;
	m_PlayerInfo.m_Centerpos.y = 200;

	m_PlayerInfo.m_PosinPos.x = 300;
	m_PlayerInfo.m_PosinPos.y = 200;

	m_PlayerInfo.m_fAngle = 0.f;

	return E_NOTIMPL;
}

void CPlayer::Update(void)
{



	//if (GetKeyState('A') & 0x8000)
	//{
	//	if (m_iBulletCnt > PLAYER_MAX_BULLET)
	//	{
	//		m_BulletArr[m_iBulletCnt] = new CBullet;
	//		m_BulletArr[m_iBulletCnt]->init(m_PlayerInfo.m_PosinPos, m_PlayerInfo.m_fAngle);

	//		m_iBulletCnt++;
	//	}
	//}

	//y = ax + b
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (m_iBulletCnt < PLAYER_MAX_BULLET)
		{
			m_BulletArr[m_iBulletCnt] = new CBullet;
			m_BulletArr[m_iBulletCnt]->init(m_PlayerInfo.m_PosinPos, m_PlayerInfo.m_fAngle);

			m_iBulletCnt++;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		float radian = m_PlayerInfo.m_fAngle * 3.141592 / 180.f;

		m_PlayerInfo.m_PosinPos.x = m_PlayerInfo.m_Centerpos.x + cos(radian) * 100;
		m_PlayerInfo.m_PosinPos.y = m_PlayerInfo.m_Centerpos.y + sin(radian) * 100;

		m_PlayerInfo.m_fAngle += 5.f;

		if (m_PlayerInfo.m_fAngle > 360)
			m_PlayerInfo.m_fAngle = 0;

		//if (m_iBulletCnt < PLAYER_MAX_BULLET)
		//{
		//	m_BulletArr[m_iBulletCnt] = new CBullet;
		//	m_BulletArr[m_iBulletCnt]->init(m_PlayerInfo.m_PosinPos, m_PlayerInfo.m_fAngle);

		//	m_iBulletCnt++;
		//}
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		float radian = m_PlayerInfo.m_fAngle * 3.141592 / 180.f;

		m_PlayerInfo.m_PosinPos.x = m_PlayerInfo.m_Centerpos.x + cos(radian) * 100;
		m_PlayerInfo.m_PosinPos.y = m_PlayerInfo.m_Centerpos.y + sin(radian) * 100;

		m_PlayerInfo.m_fAngle -= 5.f;

		if (m_PlayerInfo.m_fAngle > 360)
			m_PlayerInfo.m_fAngle = 0;
	}

	if (GetAsyncKeyState(VK_W) & 0x8000)
	{
		//m_PlayerInfo.m_PosinPos.x += 5;
		float radian = m_PlayerInfo.m_fAngle * 3.141592 / 180.f;
		m_PlayerInfo.m_Centerpos.x = (float)m_PlayerInfo.m_Centerpos.x + cos(radian) * 5.f;
		m_PlayerInfo.m_Centerpos.y = (float)m_PlayerInfo.m_Centerpos.y + sin(radian) * 5.f;

		m_PlayerInfo.m_PosinPos.x = m_PlayerInfo.m_Centerpos.x + cos(radian) * 100;
		m_PlayerInfo.m_PosinPos.y = m_PlayerInfo.m_Centerpos.y + sin(radian) * 100;
	}

	if (GetAsyncKeyState(VK_S) & 0x8000)
	{
		//m_PlayerInfo.m_PosinPos.x += 5;
		float radian = m_PlayerInfo.m_fAngle * 3.141592 / 180.f;
		m_PlayerInfo.m_Centerpos.x = (float)m_PlayerInfo.m_Centerpos.x - cos(radian) * 5.f;
		m_PlayerInfo.m_Centerpos.y = (float)m_PlayerInfo.m_Centerpos.y - sin(radian) * 5.f;

		m_PlayerInfo.m_PosinPos.x = m_PlayerInfo.m_Centerpos.x + cos(radian) * 100;
		m_PlayerInfo.m_PosinPos.y = m_PlayerInfo.m_Centerpos.y + sin(radian) * 100;
	}

	for (int i = 0; i < m_iBulletCnt; ++i)
	{
		m_BulletArr[i]->Update();
	}
}

void CPlayer::Render(HDC hdc)
{

	Rectangle(hdc, m_PlayerInfo.m_Centerpos.x - 50, m_PlayerInfo.m_Centerpos.y - 50, m_PlayerInfo.m_Centerpos.x + 50, m_PlayerInfo.m_Centerpos.y + 50);

	MoveToEx(hdc, m_PlayerInfo.m_Centerpos.x, m_PlayerInfo.m_Centerpos.y, NULL);
	LineTo(hdc, m_PlayerInfo.m_PosinPos.x, m_PlayerInfo.m_PosinPos.y);



	for (int i = 0; i < m_iBulletCnt; ++i)
	{
		m_BulletArr[i]->Render(hdc);
	}

}

void CPlayer::Release(void)
{
}
