//直接在全图形窗口绘制CG（以及BG）的函数
//计划写两个，一个瞬间绘制，另一个渐变出现
#pragma once
#ifndef DRAWCG_H
#define DRAWCG_H
#include<graphics.h>
#include"PutPictuerAlpha.h"

void drawCG(const char* cgPicture);//瞬间绘制CG（或BG）的函数
void drawCGGradually(const char* cgPicture);//渐变绘制出CG（或BG）的函数

#endif // !DRAWCG_H
