//CG�࣬����CG����BG���Ļ���
#pragma once
#ifndef CG_H
#define CG_H
#include<graphics.h>
#include"PutPictuerAlpha.h"
#include <conio.h>

//������
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

	void setCGPicture(const char* cgpicture);		//�洢CGͼƬ�ĺ���
	void draw();				//˲�����CG����BG���ĺ���
	void CGdrawGradually();		//������Ƴ�CG����BG���ĺ���
	void MICGdrawGradually();

#endif // !CG_H
