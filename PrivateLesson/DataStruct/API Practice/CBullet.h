#pragma once


class CBullet
{
private:
	INFO						m_BulletInfo;
public:
	CBullet();
	~CBullet();
public:
	HRESULT init(const POINT& pos, const float& fAngle);
	void Update(void);
	void Render(HDC hdc);
	void Release(void);
};

