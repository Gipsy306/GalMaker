#pragma once
#ifndef TXTPLAYER_H
#define TXTPLAYER_H
#include<fstream>
#include<conio.h>
#include"UI.h"
#include"GalPlayer/PutPictuerAlpha.h"


class TxtPlay
{
private:
	static TxtPlay* pTxtPlay;
public:
	static TxtPlay* getInstacne()
	{
		return pTxtPlay;
	}
	void TxtShowCase(const string& save_name,ExMessage mouse);
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
	char* CG_Picture;
public:
	static CG_TxtPlay* getInstacnce()
	{
		return pCG_TxtPlay;
	}
	void Set_CG_Picture(const char* cg_picture);
	void CGShowcase(string sets,string contents);
	void CGDraw_Immediately();
	void CGDraw_Gradually();
};
#endif // !TXTPLAYER_H
