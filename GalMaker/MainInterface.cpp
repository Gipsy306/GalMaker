#include "MainInterface.h"

//��ʼ��������
void mainInterface::init_main(ExMessage mouse)
{
	/*�������������ı���*/
	{

	}
	/*�������GalMaker��Title*/
	{

	}
	/*�������������ť*/
	ChooseBox MainChoose[3] =
	{
		ChooseBox(500,450,200,40,"�����༭��"),
		ChooseBox(500,450,200,40,"����������"),
		ChooseBox(500,450,200,40," �˳����� ")
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
