#pragma once
#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include<iostream>
#include<graphics.h>
#include<string>

//ʵ�ֶ�bg�ĵ�����ɵ�һ���Ļ滭���޸�
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
	//����ĺ���ֻ��������֡�����ʵ�������֣������Ҫдһ��ͼƬ�����ѡ�
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
