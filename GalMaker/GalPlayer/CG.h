//CG�࣬����CG����BG���Ļ���
#pragma once
#ifndef CG_H
#define CG_H
#include<graphics.h>
#include"PutPictuerAlpha.h"

class cg {
private:
	const char* cgPicture;
public:
	cg(const char* cgPicture);//���캯��
	void draw();//˲�����CG����BG���ĺ���
	void drawGradually();//������Ƴ�CG����BG���ĺ���
};

#endif // !DRAWCG_H
