#include "MainInterface.h"

//��ʼ��������
void mainInterface::init_main(ExMessage mouse)
{
	/*�������������ı���*/
	{
		initgraph(900, 600);
	}
	/*�������GalMaker��Title*/
	{

	}
	/*�������������ť*/
	ChooseBox MainChoose[3] =
	{
		ChooseBox(250,200,300,60,"�����༭��"),
		ChooseBox(250,300,300,60,"����������"),
		ChooseBox(250,400,300,60," �˳����� ")
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
	/*���Ʊ༭���Ľ���*/
	{
		initgraph(900, 600);
	}
	//ѡ��༭�Ķ���
	string path_temp;
	ChooseBox MakerChoose[3] =
	{
		ChooseBox(250,200,300,60," �½���Ŀ "),
		ChooseBox(250,300,300,60,"������Ŀ"),
		ChooseBox(250,400,300,60,"   ����   ")
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
