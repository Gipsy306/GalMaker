//CG类，用于CG（或BG）的绘制
#pragma once
#ifndef CG_H
#define CG_H
#include<graphics.h>
#include"PutPictuerAlpha.h"

class cg {
private:
	const char* cgPicture;
public:
	cg(const char* cgPicture);//构造函数
	void draw();//瞬间绘制CG（或BG）的函数
	void drawGradually();//渐变绘制出CG（或BG）的函数
};

#endif // !DRAWCG_H
