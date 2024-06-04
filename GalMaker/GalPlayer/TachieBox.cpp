#include"TachieBox.h"

tachieBox::tachieBox(int box_x,int box_y,int box__x,int box__y,COLORREF transparentColor) :box_x(box_x), box_y(box_y), box__x(box__x), box__y(box__y), transparentColor(transparentColor){};

void tachieBox::draw(const char* character) 
{
    IMAGE img;
    loadimage(&img, _T(character));
    putPictureAlpha(box_x, box_y, &img, transparentColor, 255);
}

void tachieBox::drawGradually(const char* character) {
	IMAGE img;
	loadimage(&img, _T(character));

    //设置超时时间为510毫秒
    DWORD startTime = GetTickCount();
    DWORD timeout = 510;

    int alpha = 5;

    //在510毫秒内渐变显示立绘，并检测用户输入
    while (GetTickCount() - startTime < timeout) {
        putPictureAlpha(box_x, box_y, &img, transparentColor, alpha);
        alpha += 5; //增加立绘不透明度

        //检测用户输入
        //若按enter键
        if (_kbhit() && _getch() == '\r') {
            putPictureAlpha(box_x, box_y, &img, transparentColor, 255);
            break;
        }

        //如果检测到鼠标左键点击
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
            putPictureAlpha(box_x, box_y, &img, transparentColor, 255);
            break;
        }

        //暂停10毫秒
        Sleep(10);
    }
    putPictureAlpha(box_x, box_y, &img, transparentColor, 255);//保证最终绘制一张不透明的立绘
}