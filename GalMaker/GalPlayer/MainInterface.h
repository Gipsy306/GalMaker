#pragma once
#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include<iostream>
#include<graphics.h>
#include<string>

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
public:
	//这里的函数只能输出文字。不能实现艺术字，因而还要写一个图片输出的选项。
	void SetTheTitle1();
	void TitleChange();
	void SetTheTitle2();
};

class buttons {
private:
public:
	void SetTheButtom();
};

#endif
