#include"CG.h"

<<<<<<< HEAD
<<<<<<< HEAD
cg::cg(const char* cgPicture):cgPicture(cgPicture){}
=======

=======
>>>>>>> 4ff2032e663ee1b7bdacf7994d75c2922bfee11e
void cg::setCGPicture(const char* cgpicture)
{
    cgPicture = (char*)cgpicture;
}
>>>>>>> 32fd40f237196192c5c54088ab1e06d5dcb33405


void cg::draw() 
{
<<<<<<< HEAD

=======
=======
void cg::draw() {
<<<<<<< HEAD
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());
	putimage( 0, 0,&img);
=======
>>>>>>> 731f7c4d65156685edb0c53cc2be1d64d5dc4738
>>>>>>> f948ad27a4c067d8b2abcf3a3e4a6dcaa6d12269
    IMAGE img;
    loadimage(&img, _T(cgPicture), getwidth(), getheight());
    putimage(0, 0, &img);
>>>>>>> 4ff2032e663ee1b7bdacf7994d75c2922bfee11e
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
