#include "TxtMaker.h"

//选择需要添加的内容
void FiletoTxt::ContentsAdd(const string& save_name,ExMessage mouse)
{
	ChooseBox AddChoose[6] =
	{
		ChooseBox(250,100,300,50,"添加纯文本内容"),
		ChooseBox(250,180,300,50,"添加(转换) CG "),
		ChooseBox(250,260,300,50,"添加文本框内容"),
		ChooseBox(250,340,300,50,"     NULL   "),
		ChooseBox(250,420,300,50,"     NULL   "),
		ChooseBox(250,500,300,50,"  放弃编辑  ")
	};
	int type[6] = { 0,1,2,3,4,5 };
	switch (UI_Link::getInstance()->Link_ChooseBox(AddChoose, type, 6, mouse))
	{
	case(0):cleardevice(); FileIn(TexttoTxt::getInstance()->TextSets(mouse),save_name,mouse); break;
	case(1):cleardevice(); FileIn(CGtoTxt::getInstacne()->CGSets(mouse),save_name,mouse); break;
	case(2):cleardevice();FileIn(DialogtoTxt::getInstacne()->DialogSets(mouse),save_name,mouse); break;
	case(3):cleardevice();; break;
	case(4):cleardevice();; break;
	case(5):cleardevice();exit(0); break;
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
		string temp = Folder::getInstance()->GetFiles("res/img", mouse);
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
			ofstream out(save_name, ios::out | ios::app);
			char name_content[20];
			InputBox(name_content, 20, "请输入对话人的姓名：");
			char dialog_content[100];
			InputBox(dialog_content, 100, "请输入对话的内容：");
			if (out.is_open())
			{
				//声明存储的内容
				out << sets << endl;
				out << CharToStr(name_content) << "#"<<CharToStr(dialog_content);
			}
			else { cout << "存储失败" << endl; }
			cleardevice();
		}
		//进行图片的修改
		else
		{
			ofstream out(save_name, ios::out | ios::app);
			string temp = Folder::getInstance()->GetFiles("res/dialog", mouse);
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
	case(5):cleardevice(); FiletoTxt::getInstance()->ContentsAdd("test.txt", mouse); break;
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
	ChooseBox BKDialogChoose[3] =
	{
		ChooseBox(100,10,100,25,"快速放完"),
		ChooseBox(250,10,100,25,"缓慢播放"),
		ChooseBox(400,10,100,25,"  退出  ")
	};
	int speed[3] = { 1,2,3 };
	switch (UI_Link::getInstance()->Link_ChooseBox(BKDialogChoose, speed, 3, mouse))
	{
	case(1):BK_dialog = "01"; break;
	case(2):BK_dialog = "02"; break;
	case(3):break;
	default:break;
	}
	return BK_dialog;
}
