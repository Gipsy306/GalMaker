#include"CG.h"

<<<<<<< HEAD
cg::cg(const char* cgPicture):cgPicture(cgPicture){}
=======

void cg::setCGPicture(const char* cgpicture)
{
    cgPicture = (char*)cgpicture;
}
>>>>>>> 32fd40f237196192c5c54088ab1e06d5dcb33405

void cg::draw() {
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());
	putimage( 0, 0,&img);
}

void cg::CGdrawGradually() 
{
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
            putimage(0, 0, &img);
            break;
        }

        //�����⵽���������
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
            putimage(0, 0, &img);
            break;
        }

        //��ͣ10����
        Sleep(10);
    }
    putimage(0, 0, &img);//��֤���ջ���һ�Ų�͸����CG
}
