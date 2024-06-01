#include "MainInterface.h"

//初始化主界面
void mainInterface::init_main(ExMessage mouse)
{
	/*这里绘制主界面的北京*/
	{

	}
	/*这里绘制GalMaker的Title*/
	{

	}
	/*主界面的索引按钮*/
	ChooseBox MainChoose[3] =
	{
		ChooseBox(500,450,200,40,"启动编辑器"),
		ChooseBox(500,450,200,40,"启动播放器"),
		ChooseBox(500,450,200,40," 退出程序 ")
	};
	int type[3] = {0,1,2};
	switch (UI_Link::getInstance()->Link_ChooseBox(MainChoose, type, 3, mouse))
	{
	case(0):cleardevice();init_maker(mouse); break;
	case(1):cleardevice();init_player(mouse); break;
	case(2):cleardevice();exit(0); break;
	default:break;
	}
}

void mainInterface::init_maker(ExMessage mouse)
{
}

void mainInterface::init_player(ExMessage mouse)
{
}
