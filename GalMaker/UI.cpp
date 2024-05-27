#include"UI.h"
constexpr auto err = 5;
void ChooseBox::BoxPrint(ExMessage mouse)
{
	bool before = false, present = true;		//检查鼠标是否放在选择框上；
	mouse = getmessage(EX_MOUSE | EX_KEY);
	if ((mouse.x >= box_x) && (mouse.x <= box_x + length) && (mouse.y >= box_y) && (mouse.y <= box_y + width))
	{
		present = true;

	}
}

void ChooseBox::BoxDraw(bool before, bool present)
{
	//进行这样的操作以减少不断画图造成的性能损耗
	if(before==present){}
	else
	{
		//当鼠标进入选择框中时：
		if (present)
		{
			/*具体绘制选择框的函数*/
			setfillcolor(WHITE);
			fillrectangle(box_x, box_y, box_x + length, box_y + width);
			setfillcolor(BLUE);
			fillrectangle(box_x, box_y, box_x + length, box_y + err);
			fillrectangle(box_x, box_y, box_x + err, box_y + width);
		}
	}
}
