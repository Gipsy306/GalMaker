#include"CG.h"

<<<<<<< HEAD

=======
>>>>>>> 3fb151c29ea63c9c1f0228c82637c2733a5526cc
void cg::setCGPicture(const char* cgpicture)
{
    cgPicture = (char*)cgpicture;
}

void cg::draw() {
	
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