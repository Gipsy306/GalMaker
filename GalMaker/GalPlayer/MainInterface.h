#pragma once
#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include<iostream>
#include<graphics.h>
#include<string>
#include"UI.h"
using namespace std;

<<<<<<< HEAD:GalMaker/MainInterface.h
class mainInterface
{
=======
//实现对bg的导入完成第一步的绘画和修改
class background {
private:int x, y;	    
	     
public:	  
	  void setgraph(int x,int y,IMAGE);
	  void changegraph();
	  void particles();
};

class TheTitle {
private: 
	int x, y;
>>>>>>> 731f7c4d65156685edb0c53cc2be1d64d5dc4738:GalMaker/GalPlayer/MainInterface.h
public:
	void init_main(ExMessage mouse);
	void init_maker(ExMessage mouse);
	void init_player(ExMessage mouse);
};

#endif
