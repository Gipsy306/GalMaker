#include "TxtPlayer.h"

void TxtPlay::TxtShowCase(const string& save_name,ExMessage mouse)
{
	string linereader;
	string setsline;
	ifstream in(save_name);
	int count = 1;
	while (true)
	{
		if (_kbhit())
		{
			int input = _getch();
			if (input == '\r')
			{
				getline(in, setsline);
				getline(in, linereader);
				TypeSort(setsline, linereader);
			}
			else if (input == 27)		//ESC对应的ASCII值
			{
				exit(0);
			}
		}
	}
}


void TxtPlay::TypeSort(string sets, string contents)
{
	switch (stoi(sets.substr(0,2)))
	{
	case(1):Text_TxtPlay::getInstance()->TextShowcase(sets, contents); break;
	case(2):CG_TxtPlay::getInstacnce()->CGShowcase(sets);

	default:break;
	}
}
//文本设置的处理
void Text_TxtPlay::TextShowcase(string sets, string contents)
{
	settextcolor(TextColor(sets));
	outtextxy(0, 0, contents.data());
}
//CG设置的处理
void CG_TxtPlay::CGShowcase(string sets)
{
	int type = stoi(sets.substr(2, 2));
	if (type == 1)CGDraw_Immediately();
	else CGDraw_Gradually();
}

COLORREF Text_TxtPlay::TextColor(string sets)
{
	switch (stoi(sets.substr(2, 6)))
	{
	case(0):
		return BLACK; break;
	case(1):
		return RED; break;
	case(2):
		return YELLOW; break;
	case(3):
		return BLUE; break;
	case(4):
		return GREEN; break;
	default:break;
	}
}

//设置CG的保存
void CG_TxtPlay::Set_CG_Picture(const char* cg_picture)
{
	CG_Picture = (char*)cg_picture;
}



//瞬间画出CG图片
void CG_TxtPlay::CGDraw_Immediately()
{
	IMAGE img;
	loadimage(&img, _T(CG_Picture), getwidth(), getheight());
	putimage(0, 0, &img);
}

//渐变画出CG图片
void CG_TxtPlay::CGDraw_Gradually()
{
	IMAGE img;
	loadimage(&img, _T(CG_Picture), getwidth(), getheight());

	//设置超时时间为510毫秒
	DWORD startTime = GetTickCount();
	DWORD timeout = 510;

	int alpha = 5;

	//在510毫秒内渐变显示CG，并检测用户输入
	while (GetTickCount() - startTime < timeout) {
		putPictureAlpha(0, 0, &img, RGB(0, 0, 0), alpha);
		alpha += 5; //增加CG不透明度

		//检测用户输入
		//若按enter键
		if (_kbhit() && _getch() == '\r') {
			putimage(0, 0, &img);
			break;
		}

		//如果检测到鼠标左键点击
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			putimage(0, 0, &img);
			break;
		}

		//暂停10毫秒
		Sleep(10);
	}
	putimage(0, 0, &img);//保证最终绘制一张不透明的CG
}
