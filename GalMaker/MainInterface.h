#pragma once
#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include<iostream>
#include<graphics.h>
#include<string>
#include"UI.h"
#include"TxtMaker.h"
#include"TxtPlayer.h"
#include"FileController.h"
using namespace std;

class mainInterface
{
private:
	static mainInterface* pmainInterface;
public:
	static mainInterface* getInstance() 
	{
		return  pmainInterface;
	}
	void init_main(ExMessage mouse);
	void init_maker(ExMessage mouse);
	void init_player(ExMessage mouse);
};

#endif
