//定义对话框类
#pragma once
#ifndef DIALOGBOX_H
#define DIALOGBOX_H
#include"TextBox.h"
#include"PutPictuerAlpha.h"
#include<graphics.h>
#include<conio.h>
using namespace std;

class dialogBox
{
private:
	int box_x, box_y;//对话框左上角位置
	int box__x,box__y;//对话框右下角位置
	const char* dialogBoxBackground;//对话框背景图片文件位置
	COLORREF transparentColor;//背景图片中要设置为透明的颜色
	int alpha;//背景图片透明度，范围为0~255，255表示不透明
	TextBox nameBox, sentenceBox;//姓名栏和对话文字栏
public:
	dialogBox(int box_x, int box_y, int box__x, int box__y,\
		const char* dialogBoxBackground, COLORREF transparentColor,int alpha,\
		int nameBox_x, int nameBox_y, int nameBox__x, int nameBox__y, \
		COLORREF NAMECOLOR, const char* NAMETYPEFACE, int nameNHeight,
		int sentenceBox_x, int sentenceBox_y, int sentenceBox__x, int sentenceBox__y,\
		COLORREF SENTENCECOLOR, const char* SENENCETYPEFACE, int sentenceNHeight);//构造函数
	void draw(const char* name, const char* sentence);//显示一句对话
	void emerge(const char* name, const char* sentence); //对话框浮现，随后显示一句对话
};

#endif // !DIALOGBOX_H
