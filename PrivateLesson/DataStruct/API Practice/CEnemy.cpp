#include "stdafx.h"
#include "CEnemy.h"


CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{
}

HRESULT CEnemy::init(void)
{
	m_EnemyPos.x = 500;
	m_EnemyPos.y = 500;
	return E_NOTIMPL;
}

void CEnemy::Update(void)
{
}

void CEnemy::Render(HDC hdc)
{
	Rectangle(hdc, m_EnemyPos.x - 50, m_EnemyPos.y - 50, m_EnemyPos.x + 50, m_EnemyPos.y + 50 );
}

void CEnemy::Release(void)
{
}
