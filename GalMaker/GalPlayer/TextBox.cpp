#define _CRT_SECURE_NO_WARNINGS
#include"TextBox.h"

TextBox::TextBox(int box_x, int box_y, int box__x, int box__y, COLORREF TEXTCOLOR , const char* TYPEFACE, int nHeight) :
	box_x(box_x), box_y(box_y), box__x(box__x), box__y(box__y), TEXTCOLOR(TEXTCOLOR), TYPEFACE(TYPEFACE), nHeight(nHeight) {}//TextBox类的构造函数

void TextBox::draw(const char* content) {
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = nHeight;						// 设置字体高度
	_tcscpy(f.lfFaceName, _T(TYPEFACE));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	settextcolor(TEXTCOLOR);                // 设置字体颜色
	RECT r = { box_x,box_y,box__x,box__y };      //设置文字框具体位置以及范围
	setbkmode(TRANSPARENT);
	drawtext(_T(content), &r, DT_LEFT | DT_WORDBREAK);//在框内绘制文字
}

void TextBox::drawGradually(const char* content) {
	std::string temp = (std::string)content;
    int i = 0;
    while (i<=temp.length()) {
        draw((temp.substr(0, i)).c_str());
        i++;

        //检测用户输入
        //若按enter键
        if (_kbhit() && _getch() == '\r') 
        {
            draw(content);
            break;
        }

        //如果检测到鼠标左键点击
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
            draw(content);
            break;
        }
        //暂停30毫秒
        Sleep(30);
    }
    draw(content);
}