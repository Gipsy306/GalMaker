#pragma once
#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include<iostream>
#include<graphics.h>
#include<string>
#include"UI.h"
using namespace std;

class mainInterface
{
public:
	void init_main(ExMessage mouse);
	void init_maker(ExMessage mouse);
	void init_player(ExMessage mouse);
};

#endif
