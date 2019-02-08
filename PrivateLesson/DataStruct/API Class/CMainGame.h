#pragma once

// privat, public, protected
class CMainGame
{
private:

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