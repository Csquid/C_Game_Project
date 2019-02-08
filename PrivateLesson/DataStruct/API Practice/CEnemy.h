#pragma once
class CEnemy
{
private:
	POINT					m_EnemyPos;
public:
	CEnemy();
	~CEnemy();

public:
	HRESULT init(void);
	void Update(void);
	void Render(HDC hdc);
	void Release(void);
};

