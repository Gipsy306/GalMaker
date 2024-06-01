//绘制半透明图片的函数
#pragma once
#ifndef PUTPICTUREALPHA
#define PUTPICTUREALPHA
#include<graphics.h>

void putPictureAlpha(int dstx, int dsty, IMAGE* img, COLORREF color , int alpha);
	//color表示要设置为透明的颜色
	//alpha取值0~255,255表示不透明

#endif // !PUTPICTUREALPHA
