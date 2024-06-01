//定义立绘框类
#pragma once
#ifndef TACHIEBOX_H
#define TACHIEBOX_H
#include<graphics.h>
#include"PutPictuerAlpha.h"

class tachieBox {
private:
	int box_x, box_y;//立绘框左上角位置
	int box__x, box__y;//立绘右下角位置
public:
	tachieBox(int box_x, box_y, box__x, box__y);//构造函数
	void draw(const char* character);//直接绘制出立绘，主要用于改变同一角色不同表情立绘等
	void drawGradually(const char* character);//渐变显示出立绘
};

#endif // !TACHIEBOX_H
