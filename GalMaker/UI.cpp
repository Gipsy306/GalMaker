#include"UI.h"
constexpr auto err = 5;
void ChooseBox::BoxPrint(ExMessage mouse)
{
	bool before = false, present = true;		//�������Ƿ����ѡ����ϣ�
	mouse = getmessage(EX_MOUSE | EX_KEY);
	if ((mouse.x >= box_x) && (mouse.x <= box_x + length) && (mouse.y >= box_y) && (mouse.y <= box_y + width))
	{
		present = true;

	}
}

void ChooseBox::BoxDraw(bool before, bool present)
{
	//���������Ĳ����Լ��ٲ��ϻ�ͼ��ɵ��������
	if(before==present){}
	else
	{
		//��������ѡ�����ʱ��
		if (present)
		{
			/*�������ѡ���ĺ���*/
			setfillcolor(WHITE);
			fillrectangle(box_x, box_y, box_x + length, box_y + width);
			setfillcolor(BLUE);
			fillrectangle(box_x, box_y, box_x + length, box_y + err);
			fillrectangle(box_x, box_y, box_x + err, box_y + width);
		}
	}
}
