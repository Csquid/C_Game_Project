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
	//������
	CMainGame();
	//�Ҹ���
	~CMainGame();
public:
	HRESULT init(void);
	void Update(void);
	void Render(void);
	void Release(void);
};

