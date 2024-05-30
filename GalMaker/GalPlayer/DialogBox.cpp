#include"DialogBox.h"

void putPictureAlpha(int dstx, int dsty, IMAGE* img, int alpha = 50) 
{
	//0~255,255表示不透明
	COLORREF color = RGB(85, 85, 85);
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

dialogBox::dialogBox(int box_x, int box_y, int box__x, int box__y, char* dialogBoxBackground,int alpha,
	int nameBox_x, int nameBox_y, int nameBox__x, int nameBox__y, COLORREF NAMECOLOR, char* NAMETYPEFACE, int nameNHeight,
	int sentenceBox_x, int sentenceBox_y, int sentenceBox__x, int sentenceBox__y, COLORREF SENTENCECOLOR, char* SENENCETYPEFACE, int sentenceNHeight):
	box_x(box_x),box_y(box_y),box__x(box__x),box__y(box__y),dialogBoxBackground(dialogBoxBackground),alpha(alpha),
	nameBox(nameBox_x, nameBox_y, nameBox__x, nameBox__y, NAMECOLOR, NAMETYPEFACE, nameNHeight),
	sentenceBox(sentenceBox_x, sentenceBox_y, sentenceBox__x, sentenceBox__y, SENTENCECOLOR, SENENCETYPEFACE, sentenceNHeight){}//dialogBox的构造函数

void dialogBox::draw(char* name, char* sentence) {
	IMAGE img;
	loadimage(&img, _T(dialogBoxBackground), box__x - box_x, box__y - box_y);
	putPictureAlpha(box_x, box_y, &img, alpha);
	nameBox.draw(name);
	sentenceBox.draw(sentence);
}//绘制姓名为name，语句为sentence的对话框画面