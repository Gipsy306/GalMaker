#include "TxtMaker.h"


//选择需要添加的内容
int FiletoTxt::ContentsAdd(const string& save_name,ExMessage mouse)
{
	ChooseBox AddChoose[6] =
	{
		ChooseBox(250,100,300,50,"添加纯文本内容"),
		ChooseBox(250,180,300,50,"添加(转换) CG "),
		ChooseBox(250,260,300,50,"添加文本框内容"),
		ChooseBox(250,340,300,50,"添加当前的立绘"),
		ChooseBox(250,420,300,50,"结束当前的部分"),
		ChooseBox(250,500,300,50,"  放弃编辑  ")
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

//将文件的设置和内容存入“剧本.txt”文件中
void FiletoTxt::FileIn(string sets, const string& save_name,ExMessage mouse)
{
	if (sets.substr(0, 2) == "01")	//验证sets的前两位以判断其类型
	{
		ofstream out(save_name, ios::out | ios::app);
		char sets_content[100];
		InputBox(sets_content, 100, "请输入文本内容");
		if (out.is_open())
		{
			//声明存储的内容
			out << sets << endl;
			out << CharToStr(sets_content) << endl;
		}
		else { cout << "存储失败" << endl; }
		cleardevice();
	}
	//对于是CG的情况
	else if(sets.substr(0,2)=="02")
	{
		ofstream out(save_name, ios::out | ios::app);
		string temp = Folder::getInstance()->GetFiles(save_name+"/../img", mouse);
		if (out.is_open())
		{
			//存入CG的设置
			out << sets << endl;
			out << temp << endl;
		}
		else { cout << "存储失败" << endl; }
		cleardevice();
	}
	//对于是文本框的情况
	else if (sets.substr(0, 2) == "03")
	{
		//不做图片的修改
		if (sets.substr(2, 2) == "01")
		{
			sets += DialogtoTxt::getInstacne()->DialogSpeed(mouse);
			sets += DialogtoTxt::getInstacne()->DialogColor(mouse);
			ofstream out(save_name, ios::out | ios::app);
			char name_content[20];
			InputBox(name_content, 20, "请输入对话人的姓名：");
			char dialog_content[100];
			InputBox(dialog_content, 100, "请输入对话的内容：");
			if (out.is_open())
			{
				//声明存储的内容
				out << sets << endl;
				out << CharToStr(name_content) << "#"<<CharToStr(dialog_content)<<endl;
			}
			else { cout << "存储失败" << endl; }
			cleardevice();
		}
		//进行图片的修改
		else
		{
			sets += DialogtoTxt::getInstacne()->DialogBKSpeed(mouse);
			sets += DialogtoTxt::getInstacne()->DialogBKAlpha(mouse);
			ofstream out(save_name, ios::out | ios::app);
			string temp = Folder::getInstance()->GetFiles(save_name + "/../dialog", mouse);
			if (out.is_open())
			{
				//存入CG的设置
				out << sets << endl;
				out << temp << endl;
			}
			else { cout << "存储失败" << endl; }
			cleardevice();
		}
	}
	//对于是立绘的情况
	else if (sets.substr(0, 2) == "04")
	{
		sets += SelfDeleteColor();
		ofstream out(save_name, ios::out | ios::app);
		string temp = Folder::getInstance()->GetFiles(save_name + "/../Tachie", mouse);
		if (out.is_open())
		{
			//存入CG的设置
			out << sets << endl;
			out << temp << endl;
		}
		else { cout << "存储失败" << endl; }
		cleardevice();
	}
	else if (sets.substr(0, 2) == "05")
	{
		ofstream out(save_name, ios::out | ios::app);
		if (out.is_open())
		{
			//存入CG的设置
			out << "&114514&" << endl;
			out << "本部分在这里结束力，想要继续编写的话请删掉恶臭的提示符和这句话即可";
		}
		else { cout << "存储失败" << endl; }
		cleardevice();
		exit(0);
	}
}

//设置文本配置的函数
string TexttoTxt::TextSets(ExMessage mouse)
{
	string sets_text="01";
	if (TextColor(mouse)!="0")
	{
		sets_text += TextColor(mouse);		//将颜色写入总的Sets之中
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
		ChooseBox(10,10,50,20,"黑色"),
		ChooseBox(110,10,50,20,"红色"),
		ChooseBox(210,10,50,20,"黄色"),
		ChooseBox(310,10,50,20,"蓝色"),
		ChooseBox(410,10,50,20,"绿色"),
		ChooseBox(510,10,50,20,"退出")
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


//设置CG设置的函数

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
		ChooseBox(100,10,100,25,"快速放完"),
		ChooseBox(250,10,100,25,"缓慢播放"),
		ChooseBox(400,10,100,25,"  退出  ")
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



//设置文本框配置的函数
string DialogtoTxt::DialogSets(ExMessage mouse)
{
	string sets_dialog = "03";
	sets_dialog += DialogBK(mouse);

	return sets_dialog;
}

/*设置是否改变背景的图片格式*/
string DialogtoTxt::DialogBK(ExMessage mouse)
{

	string BK_dialog;
	ChooseBox BKDialogChoose[2] =
	{
		ChooseBox(100,10,100,25,"更改文字"),
		ChooseBox(250,10,100,25,"更改背景")
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
		ChooseBox(100,10,100,25,"快速放完"),
		ChooseBox(250,10,100,25,"缓慢播放"),
		ChooseBox(400,10,100,25,"  退出  ")
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
		ChooseBox(10,10,50,20,"黑色"),
		ChooseBox(110,10,50,20,"白色"),
		ChooseBox(210,10,50,20,"红色"),
		ChooseBox(310,10,50,20,"黄色"),
		ChooseBox(410,10,50,20,"蓝色"),
		ChooseBox(510,10,50,20,"绿色"),
		ChooseBox(610,10,50,20,"自定义"),
		ChooseBox(710,10,50,20,"退出")
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
	InputBox(Red, 5, "请输入 R 的值（0~255）：");
	SelfSetRGB += ColorCheck(Red);
	InputBox(Green, 5, "请输入 G 的值（0~255）：");
	SelfSetRGB += ColorCheck(Green);
	InputBox(Blue, 5, "请输入 B 的值（0~255）：");
	SelfSetRGB += ColorCheck(Blue);
	return SelfSetRGB;
}

string SelfDeleteColor()
{
	string SelfSetRGB;
	char Red[5], Green[5], Blue[5];
	InputBox(Red, 5, "请输入要去除的 R 的值（0~255）：");
	SelfSetRGB += ColorCheck(Red);
	InputBox(Green, 5, "请输入要去除的 G 的值（0~255）：");
	SelfSetRGB += ColorCheck(Green);
	InputBox(Blue, 5, "请输入要去除的 B 的值（0~255）：");
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
		ChooseBox(100,10,100,25,"快速放完"),
		ChooseBox(250,10,100,25,"缓慢播放"),
		ChooseBox(400,10,100,25,"  退出  ")
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
		ChooseBox(100,10,100,25,"修改透明度"),
		ChooseBox(250,10,100,25," 放弃修改 "),
	};
	int type[2] = { 1,2 };
	char alpha_temp[5];
	switch (UI_Link::getInstance()->Link_ChooseBox(DialogSpeedChoose, type, 2, mouse))
	{
	case(1):InputBox(alpha_temp, 5, "请输入透明度的值（0~255，255为不透明）：");alpha_Dialog=CharToStr(alpha_temp); break;
	case(2): break;
	default:break;
	}
	cleardevice();
	return alpha_Dialog;
}



string TachietoTxt::TachieSets(ExMessage mouse)
{
	string sets_Tachie = "04";
	/*播放时间*/
	sets_Tachie += TachieSpeed(mouse);

	return sets_Tachie;
}

string TachietoTxt::TachieSpeed(ExMessage mouse)
{
	string speed_Tachie;
	ChooseBox TachieSpeedChoose[3] =
	{
		ChooseBox(100,10,100,25,"快速放完"),
		ChooseBox(250,10,100,25,"缓慢播放"),
		ChooseBox(400,10,100,25,"  退出  ")
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


