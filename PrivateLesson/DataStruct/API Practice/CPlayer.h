#pragma once
class CBullet;

class CPlayer
{
	const int PLAYER_MAX_BULLET;
private:
	//POINT						m_PlayerPos;
	INFO						m_PlayerInfo;
	CBullet*					m_BulletArr[100];
	int							m_iBulletCnt;
public:
	CPlayer();
	~CPlayer();
public:
	HRESULT init(void);
	void Update(void);
	void Render(HDC hdc);
	void Release(void);
};

