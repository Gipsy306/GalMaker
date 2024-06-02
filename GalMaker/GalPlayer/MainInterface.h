#pragma once
#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include<iostream>
#include<graphics.h>
#include <string>
#include <iostream>
using namespace std;


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
};

#endif
