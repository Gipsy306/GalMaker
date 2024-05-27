#include"UI.h"


//边框属性的一些参数
static int err = 1;		//设置边框的长度
static COLORREF UNCHOSEN_1 = RGB(0, 162, 232);		//未被选中时的颜色
static COLORREF CHOSEN_1 = RGB(34, 177, 76);		//被选中后的颜色

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

/*具体绘制选择框的函数*/
void ChooseBox::BoxDraw(COLORREF COLORTYPE) 
{
	/*绘制底部颜色*/
	setfillcolor(WHITE);
	solidrectangle(box_x, box_y, box_x + length, box_y + width);
	/*绘制边框颜色*/
	setfillcolor(COLORTYPE);
	solidrectangle(box_x, box_y, box_x + length, box_y + err);
	solidrectangle(box_x, box_y, box_x + err, box_y + width);
	solidrectangle(box_x, box_y + width - err, box_x + length, box_y + width);
	solidrectangle(box_x + length - err, box_y, box_x + length, box_y + width);
	/*打印文字*/

	settextcolor(COLORTYPE);
	setbkmode(TRANSPARENT);
	settextstyle(width-err, (length-err)/strlen(box_title), "黑体");
	LOGFONT f;
	gettextstyle(&f);
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);
	outtextxy(box_x + 2*err, box_y + err, box_title);
}