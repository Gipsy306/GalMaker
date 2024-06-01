#include"PutPictuerAlpha.h"

void putPictureAlpha(int dstx, int dsty, IMAGE* img, COLORREF color = RGB(255, 255, 255), int alpha = 50)
{
	//color表示要设置为透明的颜色
	//alpha取值0~255,255表示不透明
	DWORD* imgp = GetImageBuffer(img);
	DWORD* bgimgp = GetImageBuffer();
	int w, bw, h, i, j;
	w = img->getwidth();
	bw = getwidth();
	h = img->getheight();
	color += 0xff000000;
	if (alpha < 0)alpha = 0;
	else if (alpha > 255)alpha = 255;
	for (i = 0; i < h; ++i)
		for (j = 0; j < w; ++j)
			if (imgp[i * w + j] != color)
				bgimgp[(i + dsty) * bw + j + dstx] = RGB(
					((int)(alpha / 255.0 * GetRValue(imgp[i * w + j]) + (1 - alpha / 255.0) * GetRValue(bgimgp[(i + dsty) * bw + j + dstx]))),
					((int)(alpha / 255.0 * GetGValue(imgp[i * w + j]) + (1 - alpha / 255.0) * GetGValue(bgimgp[(i + dsty) * bw + j + dstx]))),
					((int)(alpha / 255.0 * GetBValue(imgp[i * w + j]) + (1 - alpha / 255.0) * GetBValue(bgimgp[(i + dsty) * bw + j + dstx])))
				);
}//绘制半透明图片的函数