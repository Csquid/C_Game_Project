#include "stdafx.h"
#include "Player.h"

#define DEFAULT_SPEED_DEFAULT 5
#define DEFAULT_SPEED_FAST 20

#define DEFAULT_JMP_UP 0
#define DEFAULT_JMP_DOWN 0
#define DEFAULT_CHECK_SHIFT FALSE

//»ý¼ºÀÚ
void Player::PlayerMoveInfo()
{
	this->setJmp  (DEFAULT_JMP_UP, DEFAULT_JMP_DOWN);
	this->setSpeed();
	this->setCheckShift(DEFAULT_CHECK_SHIFT);
}

void PlayerMoveInfo::setCheckShift(bool nCheck)
{
	this->checkShift = nCheck;
}

void PlayerMoveInfo::setSpeed()
{
	this->speedDefault = DEFAULT_SPEED_DEFAULT;
	this->speedFast = DEFAULT_SPEED_FAST;
}

void PlayerMoveInfo::setJmp(int nJmp_up, int nJmp_down)
{
	this->jmp_up = nJmp_up;
	this->jmp_down = nJmp_down;
}

void PlayerMoveInfo::setJmpDown(int jmp_up)
{
}

void PlayerMoveInfo::setJmpUp(int jmp_down)
{
}

bool PlayerMoveInfo::getCheckShift()
{
	return this->checkShift;
}

int PlayerMoveInfo::getDefaultSpeed()
{
	return this->speedDefault;
}

int PlayerMoveInfo::getFastSpeed()
{
	return this->speedFast;
}
