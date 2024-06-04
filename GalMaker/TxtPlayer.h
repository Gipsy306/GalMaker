#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef TXTPLAYER_H
#define TXTPLAYER_H
#include<fstream>
#include<conio.h>
#include<sstream>
#include<stdio.h>
#include"UI.h"
#include"GalPlayer/PutPictuerAlpha.h"
#include"GalPlayer/DialogBox.h"
#include"GalPlayer/TextBox.h"

#pragma comment(lib,"winmm.lib") 

class TxtPlay
{
private:
	static TxtPlay* pTxtPlay;
public:
	static TxtPlay* getInstacne()
	{
		return pTxtPlay;
	}
	void TxtShowCase(const string& save_name);
	void TypeSort(string sets,string contents);
};

class Text_TxtPlay 
{
private:
	static Text_TxtPlay* pText_TxtPlay;
public:
	static Text_TxtPlay* getInstance()
	{
		return pText_TxtPlay;
	}
	void TextShowcase(string sets,string contents);
	COLORREF TextColor(string sets);
};

class CG_TxtPlay
{
private:
	static CG_TxtPlay*  pCG_TxtPlay;

public:
	static CG_TxtPlay* getInstacnce()
	{
		return pCG_TxtPlay;
	}
	void CGShowcase(string sets,string contents);
	void CGDraw_Immediately(string contents);
	void CGDraw_Gradually(string contents);
};


class DialogBK_TxtPlay
{
private:
	static DialogBK_TxtPlay* pDialog_TxtPlay;
	char* DialogBackGround;
	int BK_Alpha;
public:
	static DialogBK_TxtPlay* getInstance()
	{
		return pDialog_TxtPlay;
	}
	//void Set_BK_Picture(const char* BK_picture);
	void BKShowCase(string sets,string contents);
	void BK_draw(string sets,string contents);
	void BK_emerge(string sets, string contents);
	int  BK_alpha(string sets);
	COLORREF DialogColorChoose(string sets);
};

//文本框文字的显示部分
class DialogWord_TxtPlay
{
private:
	static DialogWord_TxtPlay* pDialogWord_TxtPlay;
	
public:
	RECT content_pos = { 19, 549, 1599, 589 };      //设置文字框具体位置以及范围
	RECT name_pos = { 19, 609, 1599, 899 };
	static  DialogWord_TxtPlay* getInstance()
	{
		return pDialogWord_TxtPlay;
	}
	//void WordShowCase(string sets, string contents);
	void Word_draw(const char* content,int choose,COLORREF color);//在文字框内以构造时设定的文字样式设置绘制文字内容content

	void Word_drawGradually(const char* content,int choose,COLORREF color);//逐字显示

};

//立绘的显示部分
class Tachie_TxtPlay
{
private:
	static Tachie_TxtPlay* pTachie_TxtPlay;
public:
	static Tachie_TxtPlay* getInstance()
	{
		return pTachie_TxtPlay;
	}
	void TachieShowCase(string sets, string contents);
	void Tachie_draw(string contents,COLORREF deletecolor);
	void Tachie_drawGradually(string contents,COLORREF deletecolor);
	COLORREF TachieColorChoose(string sets);
};

class BGM_TxtPlay
{
private:
	static BGM_TxtPlay* pBGM_TxtPlay;
public:
	static BGM_TxtPlay* getInstance()
	{
		return pBGM_TxtPlay;
	}
	void BGMShowCase(string sets, string contents);
};


//工具函数
//颜色识别函数

#endif // !TXTPLAYER_H
