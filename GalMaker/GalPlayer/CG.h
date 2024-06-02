//CG类，用于CG（或BG）的绘制
#pragma once
#ifndef CG_H
#define CG_H
#include<graphics.h>
#include"PutPictuerAlpha.h"
#include <conio.h>

//单例类
class cg 
{
private:
	static cg* pcg;
	char* cgPicture;
public:
	static cg* getInstacne()
	{
		return pcg;
	}

	void setCGPicture(const char* cgpicture);		//存储CG图片的函数
	void draw();				//瞬间绘制CG（或BG）的函数
	void CGdrawGradually();		//渐变绘制出CG（或BG）的函数
	void MICGdrawGradually();

#endif // !CG_H
