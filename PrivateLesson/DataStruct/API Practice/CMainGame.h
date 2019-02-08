#pragma once

// privat, public, protected

class CPlayer;
class CEnemy;

class CMainGame
{
private:
	CPlayer*					m_pPlayer;
	CEnemy*						m_PEnemy;
public:
	//持失切
	CMainGame();
	//社瑚切
	~CMainGame();
public:
	HRESULT init(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

