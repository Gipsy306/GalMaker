#include "TxtMaker.h"


//ѡ����Ҫ��ӵ�����
int FiletoTxt::ContentsAdd(const string& save_name,ExMessage mouse)
{
	ChooseBox AddChoose[6] =
	{
		ChooseBox(250,100,300,50,"��Ӵ��ı�����"),
		ChooseBox(250,180,300,50,"���(ת��) CG "),
		ChooseBox(250,260,300,50,"����ı�������"),
		ChooseBox(250,340,300,50,"��ӵ�ǰ������"),
		ChooseBox(250,420,300,50,"������ǰ�Ĳ���"),
		ChooseBox(250,500,300,50,"  �����༭  ")
	};
	int type[6] = { 0,1,2,3,4,5 };
	switch (UI_Link::getInstance()->Link_ChooseBox(AddChoose, type, 6, mouse))
	{
	case(0):cleardevice(); FileIn(TexttoTxt::getInstance()->TextSets(mouse), save_name, mouse); return true; break;
	case(1):cleardevice(); FileIn(CGtoTxt::getInstacne()->CGSets(mouse), save_name, mouse); return true; break;
	case(2):cleardevice(); FileIn(DialogtoTxt::getInstacne()->DialogSets(mouse), save_name, mouse); return true; break;
	case(3):cleardevice(); FileIn(TachietoTxt::getInstance()->TachieSets(mouse), save_name, mouse); return true; break;
	case(4):cleardevice();FileIn("0514", save_name, mouse); break;
	case(5):cleardevice();return false; break;
	default: break;
	}
}

//���ļ������ú����ݴ��롰�籾.txt���ļ���
void FiletoTxt::FileIn(string sets, const string& save_name,ExMessage mouse)
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
	//������CG�����
	else if(sets.substr(0,2)=="02")
	{
		ofstream out(save_name, ios::out | ios::app);
		string temp = Folder::getInstance()->GetFiles(save_name+"/../img", mouse);
		if (out.is_open())
		{
			//����CG������
			out << sets << endl;
			out << temp << endl;
		}
		else { cout << "�洢ʧ��" << endl; }
		cleardevice();
	}
	//�������ı�������
	else if (sets.substr(0, 2) == "03")
	{
		//����ͼƬ���޸�
		if (sets.substr(2, 2) == "01")
		{
			sets += DialogtoTxt::getInstacne()->DialogSpeed(mouse);
			sets += DialogtoTxt::getInstacne()->DialogColor(mouse);
			ofstream out(save_name, ios::out | ios::app);
			char name_content[20];
			InputBox(name_content, 20, "������Ի��˵�������");
			char dialog_content[100];
			InputBox(dialog_content, 100, "������Ի������ݣ�");
			if (out.is_open())
			{
				//�����洢������
				out << sets << endl;
				out << CharToStr(name_content) << "#"<<CharToStr(dialog_content)<<endl;
			}
			else { cout << "�洢ʧ��" << endl; }
			cleardevice();
		}
		//����ͼƬ���޸�
		else
		{
			sets += DialogtoTxt::getInstacne()->DialogBKSpeed(mouse);
			sets += DialogtoTxt::getInstacne()->DialogBKAlpha(mouse);
			ofstream out(save_name, ios::out | ios::app);
			string temp = Folder::getInstance()->GetFiles(save_name + "/../dialog", mouse);
			if (out.is_open())
			{
				//����CG������
				out << sets << endl;
				out << temp << endl;
			}
			else { cout << "�洢ʧ��" << endl; }
			cleardevice();
		}
	}
	//��������������
	else if (sets.substr(0, 2) == "04")
	{
		sets += SelfDeleteColor();
		ofstream out(save_name, ios::out | ios::app);
		string temp = Folder::getInstance()->GetFiles(save_name + "/../Tachie", mouse);
		if (out.is_open())
		{
			//����CG������
			out << sets << endl;
			out << temp << endl;
		}
		else { cout << "�洢ʧ��" << endl; }
		cleardevice();
	}
	else if (sets.substr(0, 2) == "05")
	{
		ofstream out(save_name, ios::out | ios::app);
		if (out.is_open())
		{
			//����CG������
			out << "&114514&" << endl;
			out << "���������������������Ҫ������д�Ļ���ɾ���������ʾ������仰����";
		}
		else { cout << "�洢ʧ��" << endl; }
		cleardevice();
		exit(0);
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
	case(5):cleardevice(); break;
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
	case(1):speed_CG = "01"; break;
	case(2):speed_CG = "02"; break;
	case(3): break;
	default:break;
	}
	cleardevice();
	return speed_CG;
}



//�����ı������õĺ���
string DialogtoTxt::DialogSets(ExMessage mouse)
{
	string sets_dialog = "03";
	sets_dialog += DialogBK(mouse);

	return sets_dialog;
}

/*�����Ƿ�ı䱳����ͼƬ��ʽ*/
string DialogtoTxt::DialogBK(ExMessage mouse)
{

	string BK_dialog;
	ChooseBox BKDialogChoose[2] =
	{
		ChooseBox(100,10,100,25,"��������"),
		ChooseBox(250,10,100,25,"���ı���")
	};
	int type[2] = { 1,2 };
	switch (UI_Link::getInstance()->Link_ChooseBox(BKDialogChoose, type, 2, mouse))
	{
	case(1):BK_dialog = "01"; break;
	case(2):BK_dialog = "02"; break;
	default:break;
	}
	cleardevice();
	return BK_dialog;
}

string DialogtoTxt::DialogSpeed(ExMessage mouse)
{
	string speed_Dialog;
	ChooseBox DialogSpeedChoose[3] =
	{
		ChooseBox(100,10,100,25,"���ٷ���"),
		ChooseBox(250,10,100,25,"��������"),
		ChooseBox(400,10,100,25,"  �˳�  ")
	};
	int speed[3] = { 1,2,3 };
	switch (UI_Link::getInstance()->Link_ChooseBox(DialogSpeedChoose, speed, 3, mouse))
	{
	case(1):speed_Dialog = "01"; break;
	case(2):speed_Dialog = "02"; break;
	case(3): break;
	default:break;
	}
	cleardevice();
	return speed_Dialog;
}

string DialogtoTxt::DialogColor(ExMessage mouse)
{
	string color_dialog;
	ChooseBox DialogColorChoose[8] =
	{
		ChooseBox(10,10,50,20,"��ɫ"),
		ChooseBox(110,10,50,20,"��ɫ"),
		ChooseBox(210,10,50,20,"��ɫ"),
		ChooseBox(310,10,50,20,"��ɫ"),
		ChooseBox(410,10,50,20,"��ɫ"),
		ChooseBox(510,10,50,20,"��ɫ"),
		ChooseBox(610,10,50,20,"�Զ���"),
		ChooseBox(710,10,50,20,"�˳�")
	};
	int color[8] = { 0,1,2,3,4,5,6,7 };
	switch (UI_Link::getInstance()->Link_ChooseBox(DialogColorChoose, color, 8, mouse))
	{
	case(0):color_dialog = "000000000"; break;
	case(1):color_dialog = "255255255"; break;
	case(2):color_dialog = "255000000"; break;
	case(3):color_dialog = "255255000"; break;
	case(4):color_dialog = "000000255"; break;
	case(5):color_dialog = "000255000"; break;
	case(6):color_dialog = SelfSetColor(); break;
	case(7):cleardevice(); break;
	default: break;
	}

	return color_dialog;
}

string SelfSetColor()
{
	string SelfSetRGB;
	char Red[5], Green[5], Blue[5];
	InputBox(Red, 5, "������ R ��ֵ��0~255����");
	SelfSetRGB += ColorCheck(Red);
	InputBox(Green, 5, "������ G ��ֵ��0~255����");
	SelfSetRGB += ColorCheck(Green);
	InputBox(Blue, 5, "������ B ��ֵ��0~255����");
	SelfSetRGB += ColorCheck(Blue);
	return SelfSetRGB;
}

string SelfDeleteColor()
{
	string SelfSetRGB;
	char Red[5], Green[5], Blue[5];
	InputBox(Red, 5, "������Ҫȥ���� R ��ֵ��0~255����");
	SelfSetRGB += ColorCheck(Red);
	InputBox(Green, 5, "������Ҫȥ���� G ��ֵ��0~255����");
	SelfSetRGB += ColorCheck(Green);
	InputBox(Blue, 5, "������Ҫȥ���� B ��ֵ��0~255����");
	SelfSetRGB += ColorCheck(Blue);
	return SelfSetRGB;
}

string ColorCheck(char* color)
{
	if (strlen(color) == 3)
		return CharToStr(color);
	else if (strlen(color) == 2)
	return ("0" + CharToStr(color));
	else if (strlen(color) == 1)
	return ("00" + CharToStr(color));
}

string DialogtoTxt::DialogBKSpeed(ExMessage mouse)
{
	string speed_Dialog;
	ChooseBox DialogSpeedChoose[3] =
	{
		ChooseBox(100,10,100,25,"���ٷ���"),
		ChooseBox(250,10,100,25,"��������"),
		ChooseBox(400,10,100,25,"  �˳�  ")
	};
	int speed[3] = { 1,2,3 };
	switch (UI_Link::getInstance()->Link_ChooseBox(DialogSpeedChoose, speed, 3, mouse))
	{
	case(1):speed_Dialog = "01"; break;
	case(2):speed_Dialog = "02"; break;
	case(3): break;
	default:break;
	}
	cleardevice();
	return speed_Dialog;
}

string DialogtoTxt::DialogBKAlpha(ExMessage mouse)
{
	string alpha_Dialog;
	ChooseBox DialogSpeedChoose[2] =
	{
		ChooseBox(100,10,100,25,"�޸�͸����"),
		ChooseBox(250,10,100,25," �����޸� "),
	};
	int type[2] = { 1,2 };
	char alpha_temp[5];
	switch (UI_Link::getInstance()->Link_ChooseBox(DialogSpeedChoose, type, 2, mouse))
	{
	case(1):InputBox(alpha_temp, 5, "������͸���ȵ�ֵ��0~255��255Ϊ��͸������");alpha_Dialog=CharToStr(alpha_temp); break;
	case(2): break;
	default:break;
	}
	cleardevice();
	return alpha_Dialog;
}



string TachietoTxt::TachieSets(ExMessage mouse)
{
	string sets_Tachie = "04";
	/*����ʱ��*/
	sets_Tachie += TachieSpeed(mouse);

	return sets_Tachie;
}

string TachietoTxt::TachieSpeed(ExMessage mouse)
{
	string speed_Tachie;
	ChooseBox TachieSpeedChoose[3] =
	{
		ChooseBox(100,10,100,25,"���ٷ���"),
		ChooseBox(250,10,100,25,"��������"),
		ChooseBox(400,10,100,25,"  �˳�  ")
	};
	int speed[3] = { 1,2,3 };
	switch (UI_Link::getInstance()->Link_ChooseBox(TachieSpeedChoose, speed, 3, mouse))
	{
	case(1):speed_Tachie = "01"; break;
	case(2):speed_Tachie = "02"; break;
	case(3): break;
	default:break;
	}
	return speed_Tachie;
}


