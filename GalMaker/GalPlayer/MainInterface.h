#pragma once
#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include<iostream>
#include<graphics.h>

#include <string>
#include <iostream>
using namespace std;

class mainInterface
{
=======
//实现对bg的导入完成第一步的绘画和修改
>>>>>>> 4ff2032e663ee1b7bdacf7994d75c2922bfee11e
class background {
private:char*MIpicture;    
public:	  
	  background(char*MIpicture) :MIpicture(MIpicture) {};
	  void setgraph();
	   //void particles
};

class Title {
private: 
	int x, y;
<<<<<<< HEAD
	int destWidth, destHeight;
	char*Tpicture;
public:
	Title(int x, int y, int destWidth, int destHeight, char*Tpicture) :x(x), y(y), destWidth(destWidth), destHeight(destHeight), Tpicture(Tpicture) {};
	void SetTheTitle();
};

class buttons {
private:
public:
	void SetTheButtom();
=======
>>>>>>> 731f7c4d65156685edb0c53cc2be1d64d5dc4738:GalMaker/GalPlayer/MainInterface.h
public:
	void init_main(ExMessage mouse);
	void init_maker(ExMessage mouse);
	void init_player(ExMessage mouse);
>>>>>>> 4ff2032e663ee1b7bdacf7994d75c2922bfee11e
};

#endif
