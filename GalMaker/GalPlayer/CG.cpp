#include"CG.h"

void cg::setCGPicture(const char* cgpicture)
{
    cgPicture = (char*)cgpicture;
}

<<<<<<< HEAD
=======

>>>>>>> fcc3626466b9e19a507ddbdba22b547ac89eb2e2
void cg::draw() {
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());
	putimage( 0, 0,&img);
}

void cg::CGdrawGradually() 
{
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());

    //设置超时时间为510毫秒
    DWORD startTime = GetTickCount();
    DWORD timeout = 510;

    int alpha = 5;

<<<<<<< HEAD
    //��510�����ڽ�����ʾCG��������û�����
    while (GetTickCount() - startTime < timeout)
    {
        putPictureAlpha(0, 0, &img, RGB(0, 0, 0), alpha);
        alpha += 5; //����CG��͸����

        //����û�����
        //����enter��
        if (_kbhit() && _getch() == '\r') 
        {
=======
    //在510毫秒内渐变显示CG，并检测用户输入
    while (GetTickCount() - startTime < timeout) {
        putPictureAlpha(0,0,&img,RGB(0,0,0),alpha);
        alpha += 5; //增加CG不透明度

        //检测用户输入
        //若按enter键
        if (_kbhit() && _getch() == '\r') {
>>>>>>> fcc3626466b9e19a507ddbdba22b547ac89eb2e2
            putimage(0, 0, &img);
            break;
        }

        //如果检测到鼠标左键点击
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
        {
            putimage(0, 0, &img);
            break;
        }

        //暂停10毫秒
        Sleep(10);
    }
    putimage(0, 0, &img);//保证最终绘制一张不透明的CG
}
