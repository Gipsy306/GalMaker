#include"UI.h"


//�߿����Ե�һЩ����
static int err = 1;		//���ñ߿�ĳ���
static COLORREF UNCHOSEN_1 = RGB(0, 162, 232);		//δ��ѡ��ʱ����ɫ
static COLORREF CHOSEN_1 = RGB(34, 177, 76);		//��ѡ�к����ɫ

void ChooseBox::BoxPrint(ExMessage mouse)
{
	//BoxDraw(UNCHOSEN_1);
	mouse = getmessage(EX_MOUSE | EX_KEY);
	if ((mouse.x >= box_x) && (mouse.x <= box_x + length) && (mouse.y >= box_y) && (mouse.y <= box_y + width))
	{
		BoxDraw(CHOSEN_1);
	}
	else{
		BoxDraw(RED);
	}
	
}

/*�������ѡ���ĺ���*/
void ChooseBox::BoxDraw(COLORREF COLORTYPE) 
{
	/*���Ƶײ���ɫ*/
	setfillcolor(WHITE);
	solidrectangle(box_x, box_y, box_x + length, box_y + width);
	/*���Ʊ߿���ɫ*/
	setfillcolor(COLORTYPE);
	solidrectangle(box_x, box_y, box_x + length, box_y + err);
	solidrectangle(box_x, box_y, box_x + err, box_y + width);
	solidrectangle(box_x, box_y + width - err, box_x + length, box_y + width);
	solidrectangle(box_x + length - err, box_y, box_x + length, box_y + width);
	/*��ӡ����*/

	settextcolor(COLORTYPE);
	setbkmode(TRANSPARENT);
	settextstyle(width-err, (length-err)/strlen(box_title), "����");
	LOGFONT f;
	gettextstyle(&f);
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);
	outtextxy(box_x + 2*err, box_y + err, box_title);
}