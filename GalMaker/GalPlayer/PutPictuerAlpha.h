//���ư�͸��ͼƬ�ĺ���
#pragma once
#ifndef PUTPICTUREALPHA
#define PUTPICTUREALPHA
#include<graphics.h>

void putPictureAlpha(int dstx, int dsty, IMAGE* img, COLORREF color , int alpha);
	//color��ʾҪ����Ϊ͸������ɫ
	//alphaȡֵ0~255,255��ʾ��͸��

#endif // !PUTPICTUREALPHA
