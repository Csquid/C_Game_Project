#pragma once

class Nife
{

};

class PlayerMoveInfo
{
private:
	int checkShift;
	int speedDefault;
	int speedFast;
	int jmp_up;
	int jmp_down;
public:
	void setCheckShift(bool nCheck);
	void setSpeed();
	void setJmp(int nJmp_up, int nJmp_down);
	void setJmpDown(int jmp_up);
	void setJmpUp(int jmp_down);
	bool getCheckShift();
	int getDefaultSpeed();
	int getFastSpeed();
};

class Player : public PlayerMoveInfo
{
private:
	Nife* m_pNife;
public:
	//»ý¼ºÀÚ
	void PlayerMoveInfo();
};
