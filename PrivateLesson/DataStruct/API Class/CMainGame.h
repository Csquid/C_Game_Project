#pragma once

// privat, public, protected
class CMainGame
{
private:

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