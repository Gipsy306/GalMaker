#include"DrawCG.h"

void drawCG(const char* cgPicture) {
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());
	putimage(&img, 0, 0);
}

void drawCGGradually(const char* cgPicture) {
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());

    //���ó�ʱʱ��Ϊ510����
    DWORD startTime = GetTickCount();
    DWORD timeout = 510;

    int alpha = 5;

    //��510�����ڽ�����ʾCG��������û�����
    while (GetTickCount() - startTime < timeout) {
        putPictureAlpha(0,0,&img,RGB(0,0,0),alpha);
        alpha += 5; //����CG��͸����

        //����û�����
        //����enter��
        if (_kbhit() && _getch() == '\r') {
            putimage(&img, 0, 0);
            break;
        }

        //�����⵽���������
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
            putimage(&img, 0, 0);
            break;
        }

        //��ͣ10����
        Sleep(10);
    }
    putimage(&img, 0, 0);//��֤���ջ���һ�Ų�͸����CG
}