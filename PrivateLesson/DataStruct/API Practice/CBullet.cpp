#include "stdafx.h"
#include "CBullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

HRESULT CBullet::init(const POINT& pos, const float& fAngle)
{
	m_BulletInfo.m_fAngle = fAngle;
	m_BulletInfo.m_Centerpos = pos;
	return E_NOTIMPL;
}

void CBullet::Update(void)
{	
	float radian = m_BulletInfo.m_fAngle * 3.141592 / 180.f;

	m_BulletInfo.m_Centerpos.x = m_BulletInfo.m_Centerpos.x + cos(radian) * 3.F;
	m_BulletInfo.m_Centerpos.y = m_BulletInfo.m_Centerpos.y + sin(radian) * 3.f;

}

void CBullet::Render(HDC hdc)
{
	Ellipse(hdc, m_BulletInfo.m_Centerpos.x - 10, m_BulletInfo.m_Centerpos.y - 10, m_BulletInfo.m_Centerpos.x + 10, m_BulletInfo.m_Centerpos.y + 10);
}

void CBullet::Release(void)
{
}
