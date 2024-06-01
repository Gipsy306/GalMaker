#include"DrawCG.h"

void drawCG(const char* cgPicture) {
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());
	putimage(&img, 0, 0);
}

void drawCGGradually(const char* cgPicture) {
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());

    //设置超时时间为510毫秒
    DWORD startTime = GetTickCount();
    DWORD timeout = 510;

    int alpha = 5;

    //在510毫秒内渐变显示CG，并检测用户输入
    while (GetTickCount() - startTime < timeout) {
        putPictureAlpha(0,0,&img,RGB(0,0,0),alpha);
        alpha += 5; //增加CG不透明度

        //检测用户输入
        //若按enter键
        if (_kbhit() && _getch() == '\r') {
            putimage(&img, 0, 0);
            break;
        }

        //如果检测到鼠标左键点击
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
            putimage(&img, 0, 0);
            break;
        }

        //暂停10毫秒
        Sleep(10);
    }
    putimage(&img, 0, 0);//保证最终绘制一张不透明的CG
}