#include "TxtMaker.h"

//ѡ����Ҫ��ӵ�����
void FiletoTxt::ContentsAdd(const string& save_name,ExMessage mouse)
{
	ChooseBox AddChoose[6] =
	{
		ChooseBox(250,100,300,50,"����ı�����"),
		ChooseBox(250,180,300,50,"���(ת��)CG"),
		ChooseBox(250,260,300,50,"     NULL   "),
		ChooseBox(250,340,300,50,"     NULL   "),
		ChooseBox(250,420,300,50,"     NULL   "),
		ChooseBox(250,500,300,50,"  �����༭  ")
	};
	int type[6] = { 0,1,2,3,4,5 };
	switch (UI_Link::getInstance()->Link_ChooseBox(AddChoose, type, 6, mouse))
	{
	case(0):cleardevice(); FileIn(TexttoTxt::getInstance()->TextSets(mouse),save_name); break;
	case(1):cleardevice(); FileIn(CGtoTxt::getInstacne()->CGSets(mouse),save_name); break;
	case(2):cleardevice();; break;
	case(3):cleardevice();; break;
	case(4):cleardevice();; break;
	case(5):cleardevice();exit(0); break;
	default: break;
	}
}

//���ļ������ú����ݴ��롰�籾.txt���ļ���
void FiletoTxt::FileIn(string sets, const string& save_name)
{
	if (sets.substr(0, 2) == "01")	//��֤sets��ǰ��λ���ж�������
	{
		ofstream out(save_name, ios::out | ios::app);
		char sets_content[100];
		InputBox(sets_content, 100, "�������ı�����");
		if (out.is_open())
		{
			//�����洢������
			out << sets << endl;
			out << CharToStr(sets_content) << endl;
		}
		else { cout << "�洢ʧ��" << endl; }
		cleardevice();
	}
	else if(sets.substr(0,2)=="02")
	{
		ofstream out(save_name, ios::out | ios::app);

	}
}

//�����ı����õĺ���
string TexttoTxt::TextSets(ExMessage mouse)
{
	string sets_text="01";
	if (TextColor(mouse)!="0")
	{
		sets_text += TextColor(mouse);		//����ɫд���ܵ�Sets֮��
		return sets_text;
	}
	else
	{
		return "esc";
	}
}

string TexttoTxt::TextColor(ExMessage mouse)
{
	string color_text;
	ChooseBox TextColorChoose[6] =
	{
		ChooseBox(10,10,50,20,"��ɫ"),
		ChooseBox(110,10,50,20,"��ɫ"),
		ChooseBox(210,10,50,20,"��ɫ"),
		ChooseBox(310,10,50,20,"��ɫ"),
		ChooseBox(410,10,50,20,"��ɫ"),
		ChooseBox(510,10,50,20,"�˳�")
	};
	int color[6] = { 0,1,2,3,4,5 };
	switch (UI_Link::getInstance()->Link_ChooseBox(TextColorChoose, color, 6, mouse))
	{
	case(0):color_text = "000000"; break;
	case(1):color_text = "000001"; break;
	case(2):color_text = "000002"; break;
	case(3):color_text = "000003"; break;
	case(4):color_text = "000004"; break;
	case(5):cleardevice(); FiletoTxt::getInstance()->ContentsAdd("test.txt", mouse); break;
	default: break;
	}

	return color_text;
}


//����CG���õĺ���

string CGtoTxt::CGSets(ExMessage mouse)
{
	string sets_CG = "02";
	sets_CG += CGSpeed(mouse);
	
	return sets_CG;
}

string CGtoTxt::CGSpeed(ExMessage mouse)
{
	string speed_CG;
	ChooseBox CGSpeedChoose[3] =
	{
		ChooseBox(100,10,100,25,"���ٷ���"),
		ChooseBox(250,10,100,25,"��������"),
		ChooseBox(400,10,100,25,"  �˳�  ")
	};
	int speed[3] = { 1,2,3 };
	switch (UI_Link::getInstance()->Link_ChooseBox(CGSpeedChoose, speed, 3, mouse))
	{

	}
	return speed_CG;
}

string CharToStr(char* contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}
