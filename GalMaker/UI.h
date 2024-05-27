//图形化界面的制作，这里用于存放所需要的图形化函数；
//这里设定的类并没有什么实际的含义，只不过是为了便于管理相对应的函数，便于同名的重载。
//因此，这里设置的类都采用了“饿汉”的单例化类
//这里设置了一些选择的“数据接口”
#pragma once
#ifndef UI_H
#define UI_H
#include<string>
#include<iostream>
#include<graphics.h>
using namespace std;
constexpr auto DEFAULT = 1;
/*基本的模块构建函数*/
class UI_Basic
{
private:
	static UI_Basic* pUI_Basic;
public:
	static UI_Basic* getInstance()
	{
		return pUI_Basic;
	}
	/*基本的构建的制作*/
};

/*选择框的构建*/
class ChooseBox
{
private:
public:
/*选择框的属性设计*/
	/*选择框的位置确定（左上角坐标）*/
	int box_x;
	int box_y;
	/*选择框的大小确定*/
	int length;
	int width;
	/*选择框上的标签*/
	string box_title;
	/*选择框的格式*/
	int box_type;
/*选择框的构造函数*/
	ChooseBox(int xx,int yy,int ll,int ww,string title,int type):box_x(xx),box_y(yy),length(ll),width(ww),box_title(title),box_type(type){}
	ChooseBox(int xx, int yy, int ll, int ww, string title) :box_x(xx), box_y(yy), length(ll), width(ww), box_title(title),box_type(DEFAULT) {}

/*选择框的函数*/
	void BoxPrint(ExMessage mouse);
	/*绘制框的两种形态的函数*/
	void BoxDraw(bool, bool);
};


UI_Basic* UI_Basic::pUI_Basic = new UI_Basic;

//文件处理有关的
class UI_File
{
private:
	static UI_File* pUI_File;
public:
	static UI_File* getInstance()
	{
		return pUI_File;
	}

};
UI_File* UI_File::pUI_File = new UI_File;

#endif // !UI_H
