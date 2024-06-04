#include "MainInterface.h"

//初始化主界面
void mainInterface::init_main(ExMessage mouse)
{
	/*这里绘制主界面的背景*/
	{
		initgraph(900, 600);
	}
	/*这里绘制GalMaker的Title*/
	{

	}
	/*主界面的索引按钮*/
	ChooseBox MainChoose[3] =
	{
		ChooseBox(250,200,300,60,"启动编辑器"),
		ChooseBox(250,300,300,60,"启动播放器"),
		ChooseBox(250,400,300,60," 退出程序 ")
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
	/*绘制编辑器的界面*/
	{
		initgraph(900, 600);
	}
	//选择编辑的对象
	string path_temp;
	ChooseBox MakerChoose[3] =
	{
		ChooseBox(250,200,300,60," 新建项目 "),
		ChooseBox(250,300,300,60,"打开现有目"),
		ChooseBox(250,400,300,60,"   返回   ")
	};
	int type[3] = { 0,1,2 };
	switch (UI_Link::getInstance()->Link_ChooseBox(MakerChoose, type, 3, mouse))
	{
	case(0):cleardevice(); path_temp=Folder::getInstance()->CreateProject(); break;
	case(1):cleardevice(); path_temp=Folder::getInstance()->OpenProject(mouse); break;
	case(2):cleardevice(); init_main(mouse); break;
	default:break;
	}
	while (1)
	{
		if (FiletoTxt::getInstance()->ContentsAdd((path_temp), mouse));
		else init_main(mouse);
	}
}

void mainInterface::init_player(ExMessage mouse)
{
	string temp = Folder::getInstance()->GetTxtFiles("projects", mouse);
	initgraph(1600, 900);
	TxtPlay::getInstacne()->TxtShowCase(temp);
}
