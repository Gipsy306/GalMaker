#include "TxtMaker.h"

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
	case(5):color_text = "0"; break;
	default: break;
	}
	return color_text;
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

void FiletoTxt::FileIn(string sets, const string& save_name)
{
	if (sets.substr(0,2) == "01")	//验证sets的前两位以判断其类型
	{
		ofstream out(save_name,ios::out|ios::app);
		char sets_content[100];
		InputBox(sets_content, 100, "请输入文本内容");
		if (out.is_open())
		{
			//声明存储的内容
			out << sets << endl;
			out << CharToStr(sets_content) << endl;
		}
		else { cout << "存储失败" << endl; }
	}
	else
	{}
}
