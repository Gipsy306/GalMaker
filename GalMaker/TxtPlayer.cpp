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


	default:break;
	}
}

void Text_TxtPlay::TextShowcase(string sets, string contents)
{
	settextcolor(TextColor(sets));
	outtextxy(0, 0, contents.data());
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

