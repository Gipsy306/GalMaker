#include"UI.h"

void ChooseBox::BoxPrint(ExMessage mouse)
{
	bool before = false,present=true;		//�������Ƿ����ѡ����ϣ�
	mouse = getmessage(EX_MOUSE | EX_KEY);
	if ((mouse.x >= box_x) && (mouse.x <= box_x + length) && (mouse.y >= box_y) && (mouse.y <= box_y + width))
	{
		present = true;

	}
}

void ChooseBox::BoxDraw(bool, bool)
{
}
