#pragma once
#ifndef TXTPLAYER_H
#define TXTPLAYER_H
#include<fstream>
#include<conio.h>
#include"UI.h"


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

};
#endif // !TXTPLAYER_H
