//定义文字框，用于生成对话框中的姓名栏以及对话文字栏
#pragma once
#ifndef TEXTBOX_H
#define TEXTBOX_H
#include<graphics.h>
#include<string>
#include<conio.h>
using namespace std;

class TextBox {
private:
	int box_x, box_y;//文字框左上角位置
	int box__x, box__y;//文字框右下角位置
	COLORREF TEXTCOLOR ;//文字颜色
	const char* TYPEFACE ;//文字字体
	int nHeight;//文字高度
public:
	TextBox(int box_x, int box_y, int box__x, int box__y, COLORREF TEXTCOLOR, const char* TYPEFACE, int nHeight);//构造函数
	void draw(const char* content);//在文字框内以构造时设定的文字样式设置绘制文字内容content
	void drawGradually(const char* content);//逐字显示
};

#endif // !TEXTBOX_H

