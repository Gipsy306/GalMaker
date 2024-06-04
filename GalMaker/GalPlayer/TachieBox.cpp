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

    //���ó�ʱʱ��Ϊ510����
    DWORD startTime = GetTickCount();
    DWORD timeout = 510;

    int alpha = 5;

    //��510�����ڽ�����ʾ���棬������û�����
    while (GetTickCount() - startTime < timeout) {
        putPictureAlpha(box_x, box_y, &img, transparentColor, alpha);
        alpha += 5; //�������治͸����

        //����û�����
        //����enter��
        if (_kbhit() && _getch() == '\r') {
            putPictureAlpha(box_x, box_y, &img, transparentColor, 255);
            break;
        }

        //�����⵽���������
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
            putPictureAlpha(box_x, box_y, &img, transparentColor, 255);
            break;
        }

        //��ͣ10����
        Sleep(10);
    }
    putPictureAlpha(box_x, box_y, &img, transparentColor, 255);//��֤���ջ���һ�Ų�͸��������
}