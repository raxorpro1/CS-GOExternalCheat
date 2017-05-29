#pragma once

class cBhop
{
public:
	cBhop();
	~cBhop();
	void Bhop();
	int fl_onGround();
	DWORD getBhopKey();
private:
	//Int da valor no chão
	//HEX da tecla
	int onGround = 257;
	DWORD bhopKey = 0x20;
};

extern cBhop *pBhop;
