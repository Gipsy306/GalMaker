#define _CRT_SECURE_NO_WARNINGS
#include"TextBox.h"

TextBox::TextBox(int box_x, int box_y, int box__x, int box__y, COLORREF TEXTCOLOR , const char* TYPEFACE, int nHeight) :
	box_x(box_x), box_y(box_y), box__x(box__x), box__y(box__y), TEXTCOLOR(TEXTCOLOR), TYPEFACE(TYPEFACE), nHeight(nHeight) {}//TextBox��Ĺ��캯��

void TextBox::draw(const char* content) {
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = nHeight;						// ��������߶�
	_tcscpy(f.lfFaceName, _T(TYPEFACE));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	settextcolor(TEXTCOLOR);                // ����������ɫ
	RECT r = { box_x,box_y,box__x,box__y };      //�������ֿ����λ���Լ���Χ
	setbkmode(TRANSPARENT);
	drawtext(_T(content), &r, DT_LEFT | DT_WORDBREAK);//�ڿ��ڻ�������
}

void TextBox::drawGradually(const char* content) {
	std::string temp = (std::string)content;
    int i = 0;
    while (i<=temp.length()) {
        draw((temp.substr(0, i)).c_str());
        i++;

        //����û�����
        //����enter��
        if (_kbhit() && _getch() == '\r') 
        {
            draw(content);
            break;
        }

        //�����⵽���������
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
            draw(content);
            break;
        }
        //��ͣ30����
        Sleep(30);
    }
    draw(content);
}