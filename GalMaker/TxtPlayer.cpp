#include "TxtPlayer.h"
using namespace std;
//自动播放的check
int check = 1;
void TxtPlay::TxtShowCase(const string& save_name)
{
	string linereader;
	string setsline;
	ifstream in(save_name);
	while (true)
	{
		if (check == 1)
		{
			getline(in, setsline);
			getline(in, linereader);
			TypeSort(setsline, linereader);
		}
		else if (_kbhit())
		{
			int input = _getch();
			if (input == '\r' )
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

//设置需要多次调用的一些配置性的语句
/*CG存储*/
static string CG_sets, CG_contents;
/*文本框背景图片*/
static string DialogBK_sets, DialogBK_contents;
/*立绘图片存储*/
static string Tachie_sets, Tachie_contents;
/*BGM播放存储*/
static string BGM_sets, BGM_contents;

void TxtPlay::TypeSort(string sets, string contents)
{
	if (sets == "&114514&")
	{
		exit(0);
	}
	else
	{
		switch (stoi(sets.substr(0, 2)))
		{
		case(1):Text_TxtPlay::getInstance()->TextShowcase(sets, contents); break;
		case(2):CG_TxtPlay::getInstacnce()->CGShowcase(sets, contents); break;
		case(3):DialogBK_TxtPlay::getInstance()->BKShowCase(sets, contents); break;
		case(4):Tachie_TxtPlay::getInstance()->TachieShowCase(sets, contents); break;
		default:break;
		}
	}
}
//文本设置的处理
void Text_TxtPlay::TextShowcase(string sets, string contents)
{
	settextcolor(TextColor(sets));
	setbkmode(TRANSPARENT);
	outtextxy(0, 0, contents.data());
}
//CG设置的处理
void CG_TxtPlay::CGShowcase(string sets,string contents)
{
	//将图片与加载的配置相对比
	if (sets != CG_sets)
	{
		CG_sets = sets;
	}
	if (contents != CG_contents)
	{
		CG_contents = contents;
		check = 1;
	}
	//check = 0;
	int type = stoi(sets.substr(2, 2));
	if (type == 1)CGDraw_Immediately(contents);
	else CGDraw_Gradually(contents);
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


//瞬间画出CG图片
void CG_TxtPlay::CGDraw_Immediately(string contents)
{
	IMAGE img;
	loadimage(&img, _T(contents.c_str()), getwidth(), getheight());
	putimage(0, 0, &img);
}

//渐变画出CG图片
void CG_TxtPlay::CGDraw_Gradually(string contents)
{
	IMAGE img;
	loadimage(&img, _T(contents.c_str()), getwidth(), getheight());

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







//迅速显示文本框中的文字
void DialogWord_TxtPlay::Word_draw(const char* content,int choose,COLORREF color)
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 40;						// 设置字体高度
	_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	settextcolor(color);                // 设置字体颜色
	/*设置文本框的*/
	setbkmode(TRANSPARENT);
	if(choose==2)
		drawtext(_T(content), &name_pos, DT_LEFT | DT_WORDBREAK);//选择位置为Name
	else if(choose==1)
		drawtext(_T(content), &content_pos, DT_LEFT | DT_WORDBREAK);//选择位置为Content
}

//逐字缓慢显示文本框文字
void DialogWord_TxtPlay::Word_drawGradually(const char* content,int choose,COLORREF color)
{
	std::string temp = (std::string)content;
	int i = 0;
	while (i <= temp.length()) {
		Word_draw((temp.substr(0, i)).c_str(),choose,color);
		i++;
		//检测用户输入
		//若按enter键
		if (_kbhit() && _getch() == '\r')
		{
			Word_draw(content,choose,color);
			break;
		}
		//如果检测到鼠标左键点击
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			Word_draw(content,choose,color);
			break;
		}
		//暂停30毫秒
		Sleep(30);
	}
	Word_draw(content,choose,color);
}



void DialogBK_TxtPlay::BKShowCase(string sets, string contents)
{
	//读取设置sets进行选择
	/*选择修改图片*/
	if (stoi(sets.substr(2, 2)) == 2)
	{
		//将新的图片存入
		if(DialogBK_sets!=sets)
		DialogBK_sets = sets;
		if(DialogBK_contents!=contents)
		DialogBK_contents = contents;
		check = 1;
	}
	/*仅仅修改文字*/
	else
	{
		check = 0;
		stringstream ss(contents);
		//设置分隔符为“#”
		char c = '#';
		string name;
		string content;
		getline(ss, name, c);
		getline(ss, content, c);
		/*显示背景CG*/
		CG_TxtPlay::getInstacnce()->CGShowcase(CG_sets, CG_contents);
		/*显示立绘*/
		Tachie_TxtPlay::getInstance()->TachieShowCase(Tachie_sets, Tachie_contents);
		/*选择快速播放文本框*/
		if (stoi(DialogBK_sets.substr(4, 2)) == 1)
		{
			BK_draw(DialogBK_sets, DialogBK_contents);
		}
		/*选择缓慢播放文本框*/
		else if(stoi(DialogBK_sets.substr(4, 2)) == 2)
		{
			BK_emerge(DialogBK_sets, DialogBK_contents);
		}

		DialogWord_TxtPlay::getInstance()->Word_draw(name.c_str(), 1,DialogColorChoose(sets));
		if (stoi(sets.substr(4, 2)) == 1)		//直接显示文字
		{
			DialogWord_TxtPlay::getInstance()->Word_draw(content.c_str(), 2, DialogColorChoose(sets));
		}
		else if (stoi(sets.substr(4, 2)) == 2)	//逐渐打印文字
		{
			DialogWord_TxtPlay::getInstance()->Word_drawGradually(content.c_str(), 2,DialogColorChoose(sets));
		}
	}
}

//直接打印文本框背景
void DialogBK_TxtPlay::BK_draw(string sets, string contents)
{
	IMAGE img;
	loadimage(&img, _T(contents.c_str()), 1600, 360);
	putPictureAlpha(0, 539, &img, RGB(0,0,0), BK_alpha(DialogBK_sets));

}
//文本框背景浮现
void DialogBK_TxtPlay::BK_emerge(string sets, string contents)
{
	IMAGE img;
	loadimage(&img, _T(DialogBackGround), 1600, 360);

	//设置超时时间为510毫秒
	DWORD startTime = GetTickCount();
	DWORD timeout = 510;

	int Alpha = 5;

	//在510毫秒内渐变显示背景图，并检测用户输入
	while ((GetTickCount() - startTime < timeout) && (Alpha <= BK_alpha(DialogBK_sets) / 5)) {
		putPictureAlpha(0, 539, &img, RGB(0, 0, 0), Alpha);
		Alpha += 5; //增加背景图不透明度

		//检测用户输入
		//若按enter键
		if (_kbhit() && _getch() == '\r') {
			putPictureAlpha(0, 539, &img, RGB(0, 0, 0), BK_alpha(DialogBK_sets));
			break;
		}

		//如果检测到鼠标左键点击
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			putPictureAlpha(0, 539, &img, RGB(0, 0, 0), BK_alpha(DialogBK_sets));
			break;
		}
		
		//暂停10毫秒
		Sleep(10);

	}
	putPictureAlpha(0, 539, &img, RGB(0, 0, 0), BK_alpha(DialogBK_sets));//保证最终绘制出透明度为设定值的背景图
	
}

/*设置文本框的背景图片的Alpha值*/
int DialogBK_TxtPlay::BK_alpha(string sets)
{
	//BK_Alpha = stoi(sets.substr(6, 3));
	return stoi(sets.substr(6, 3));
}

void Tachie_TxtPlay::TachieShowCase(string sets, string contents)
{
	bool flag = 1;
	//将图片与加载的配置相对比
	if (sets != Tachie_sets)
	{
		Tachie_sets = sets;
		flag = 0;
	}
	if (contents != Tachie_contents)
	{
		Tachie_contents = contents;
		check = 1;
		flag = 0;
	}
	//check = 0;
	if(flag)
	{
		int type = stoi(sets.substr(2, 2));
		if (type == 1)Tachie_draw(contents,TachieColorChoose(sets));
		else Tachie_drawGradually(contents,TachieColorChoose(sets));
	}
}
//立绘的抠图的颜色
COLORREF Tachie_TxtPlay::TachieColorChoose(string sets)
{
	return RGB(stoi(sets.substr(4, 3)), stoi(sets.substr(7, 3)), stoi(sets.substr(10, 3)));
}
//迅速加载出立绘
void Tachie_TxtPlay::Tachie_draw(string contents,COLORREF deletecolor)
{
	IMAGE img,new_img;
	loadimage(&img, _T(contents.c_str()));
	// 获取图片的宽度和高度
	int imgWidth = img.getwidth();
	int imgHeight = img.getheight();

	// 计算缩放比例
	float scaleX = (float)(500) / (float)imgWidth;
	float scaleY = (float)(1500) / (float)imgHeight;
	float scale = min(scaleX, scaleY); // 选择较小的缩放比例

	// 设置缩放后的图片大小
	int newWidth = (int)(imgWidth * scale);
	int newHeight = (int)(imgHeight * scale);
	loadimage(&new_img, _T(contents.c_str()), newWidth, newHeight);
	putPictureAlpha(100, 179, &new_img, deletecolor, 255);
}
//缓慢加载出立绘
void Tachie_TxtPlay::Tachie_drawGradually(string contents,COLORREF deletecolor)
{
	IMAGE img,new_img;
	loadimage(&img, _T(contents.c_str()), 500, 720);
	// 获取图片的宽度和高度
	int imgWidth = img.getwidth();
	int imgHeight = img.getheight();

	// 计算缩放比例
	float scaleX = (float)(500) / (float)imgWidth;
	float scaleY = (float)(1500) / (float)imgHeight;
	float scale = min(scaleX, scaleY); // 选择较小的缩放比例

	// 设置缩放后的图片大小
	int newWidth = (int)(imgWidth * scale);
	int newHeight = (int)(imgHeight * scale);
	loadimage(&new_img, _T(contents.c_str()), newWidth, newHeight);
	//设置超时时间为510毫秒
	DWORD startTime = GetTickCount();
	DWORD timeout = 510;

	int alpha = 5;

	//在510毫秒内渐变显示立绘，并检测用户输入
	while (GetTickCount() - startTime < timeout) {
		putPictureAlpha(149, 179, &img, deletecolor, alpha);
		alpha += 5; //增加立绘不透明度

		//检测用户输入
		//若按enter键
		if (_kbhit() && _getch() == '\r') {
			putPictureAlpha(149, 179, &img, deletecolor, 255);
			break;
		}

		//如果检测到鼠标左键点击
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			putPictureAlpha(149, 179, &img, deletecolor, 255);
			break;
		}

		//暂停10毫秒
		Sleep(10);
	}
	putPictureAlpha(149, 179, &img, deletecolor, 255);//保证最终绘制一张不透明的立绘
}

COLORREF DialogBK_TxtPlay::DialogColorChoose(string sets)
{
	return RGB(stoi(sets.substr(6, 3)), stoi(sets.substr(9, 3)), stoi(sets.substr(12, 3)));
}