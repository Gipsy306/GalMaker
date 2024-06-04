#include "TxtPlayer.h"
using namespace std;
//�Զ����ŵ�check
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
			else if (input == 27)		//ESC��Ӧ��ASCIIֵ
			{
				exit(0);
			}
		}
	}
}

//������Ҫ��ε��õ�һЩ�����Ե����
/*CG�洢*/
static string CG_sets, CG_contents;
/*�ı��򱳾�ͼƬ*/
static string DialogBK_sets, DialogBK_contents;
/*����ͼƬ�洢*/
static string Tachie_sets, Tachie_contents;
/*BGM���Ŵ洢*/
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
//�ı����õĴ���
void Text_TxtPlay::TextShowcase(string sets, string contents)
{
	settextcolor(TextColor(sets));
	setbkmode(TRANSPARENT);
	outtextxy(0, 0, contents.data());
}
//CG���õĴ���
void CG_TxtPlay::CGShowcase(string sets,string contents)
{
	//��ͼƬ����ص�������Ա�
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


//˲�仭��CGͼƬ
void CG_TxtPlay::CGDraw_Immediately(string contents)
{
	IMAGE img;
	loadimage(&img, _T(contents.c_str()), getwidth(), getheight());
	putimage(0, 0, &img);
}

//���仭��CGͼƬ
void CG_TxtPlay::CGDraw_Gradually(string contents)
{
	IMAGE img;
	loadimage(&img, _T(contents.c_str()), getwidth(), getheight());

	//���ó�ʱʱ��Ϊ510����
	DWORD startTime = GetTickCount();
	DWORD timeout = 510;

	int alpha = 5;

	//��510�����ڽ�����ʾCG��������û�����
	while (GetTickCount() - startTime < timeout) {
		putPictureAlpha(0, 0, &img, RGB(0, 0, 0), alpha);
		alpha += 5; //����CG��͸����

		//����û�����
		//����enter��
		if (_kbhit() && _getch() == '\r') {
			putimage(0, 0, &img);
			break;
		}

		//�����⵽���������
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			putimage(0, 0, &img);
			break;
		}

		//��ͣ10����
		Sleep(10);
	}
	putimage(0, 0, &img);//��֤���ջ���һ�Ų�͸����CG
}







//Ѹ����ʾ�ı����е�����
void DialogWord_TxtPlay::Word_draw(const char* content,int choose,COLORREF color)
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 40;						// ��������߶�
	_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	settextcolor(color);                // ����������ɫ
	/*�����ı����*/
	setbkmode(TRANSPARENT);
	if(choose==2)
		drawtext(_T(content), &name_pos, DT_LEFT | DT_WORDBREAK);//ѡ��λ��ΪName
	else if(choose==1)
		drawtext(_T(content), &content_pos, DT_LEFT | DT_WORDBREAK);//ѡ��λ��ΪContent
}

//���ֻ�����ʾ�ı�������
void DialogWord_TxtPlay::Word_drawGradually(const char* content,int choose,COLORREF color)
{
	std::string temp = (std::string)content;
	int i = 0;
	while (i <= temp.length()) {
		Word_draw((temp.substr(0, i)).c_str(),choose,color);
		i++;
		//����û�����
		//����enter��
		if (_kbhit() && _getch() == '\r')
		{
			Word_draw(content,choose,color);
			break;
		}
		//�����⵽���������
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			Word_draw(content,choose,color);
			break;
		}
		//��ͣ30����
		Sleep(30);
	}
	Word_draw(content,choose,color);
}



void DialogBK_TxtPlay::BKShowCase(string sets, string contents)
{
	//��ȡ����sets����ѡ��
	/*ѡ���޸�ͼƬ*/
	if (stoi(sets.substr(2, 2)) == 2)
	{
		//���µ�ͼƬ����
		if(DialogBK_sets!=sets)
		DialogBK_sets = sets;
		if(DialogBK_contents!=contents)
		DialogBK_contents = contents;
		check = 1;
	}
	/*�����޸�����*/
	else
	{
		check = 0;
		stringstream ss(contents);
		//���÷ָ���Ϊ��#��
		char c = '#';
		string name;
		string content;
		getline(ss, name, c);
		getline(ss, content, c);
		/*��ʾ����CG*/
		CG_TxtPlay::getInstacnce()->CGShowcase(CG_sets, CG_contents);
		/*��ʾ����*/
		Tachie_TxtPlay::getInstance()->TachieShowCase(Tachie_sets, Tachie_contents);
		/*ѡ����ٲ����ı���*/
		if (stoi(DialogBK_sets.substr(4, 2)) == 1)
		{
			BK_draw(DialogBK_sets, DialogBK_contents);
		}
		/*ѡ���������ı���*/
		else if(stoi(DialogBK_sets.substr(4, 2)) == 2)
		{
			BK_emerge(DialogBK_sets, DialogBK_contents);
		}

		DialogWord_TxtPlay::getInstance()->Word_draw(name.c_str(), 1,DialogColorChoose(sets));
		if (stoi(sets.substr(4, 2)) == 1)		//ֱ����ʾ����
		{
			DialogWord_TxtPlay::getInstance()->Word_draw(content.c_str(), 2, DialogColorChoose(sets));
		}
		else if (stoi(sets.substr(4, 2)) == 2)	//�𽥴�ӡ����
		{
			DialogWord_TxtPlay::getInstance()->Word_drawGradually(content.c_str(), 2,DialogColorChoose(sets));
		}
	}
}

//ֱ�Ӵ�ӡ�ı��򱳾�
void DialogBK_TxtPlay::BK_draw(string sets, string contents)
{
	IMAGE img;
	loadimage(&img, _T(contents.c_str()), 1600, 360);
	putPictureAlpha(0, 539, &img, RGB(0,0,0), BK_alpha(DialogBK_sets));

}
//�ı��򱳾�����
void DialogBK_TxtPlay::BK_emerge(string sets, string contents)
{
	IMAGE img;
	loadimage(&img, _T(DialogBackGround), 1600, 360);

	//���ó�ʱʱ��Ϊ510����
	DWORD startTime = GetTickCount();
	DWORD timeout = 510;

	int Alpha = 5;

	//��510�����ڽ�����ʾ����ͼ��������û�����
	while ((GetTickCount() - startTime < timeout) && (Alpha <= BK_alpha(DialogBK_sets) / 5)) {
		putPictureAlpha(0, 539, &img, RGB(0, 0, 0), Alpha);
		Alpha += 5; //���ӱ���ͼ��͸����

		//����û�����
		//����enter��
		if (_kbhit() && _getch() == '\r') {
			putPictureAlpha(0, 539, &img, RGB(0, 0, 0), BK_alpha(DialogBK_sets));
			break;
		}

		//�����⵽���������
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			putPictureAlpha(0, 539, &img, RGB(0, 0, 0), BK_alpha(DialogBK_sets));
			break;
		}
		
		//��ͣ10����
		Sleep(10);

	}
	putPictureAlpha(0, 539, &img, RGB(0, 0, 0), BK_alpha(DialogBK_sets));//��֤���ջ��Ƴ�͸����Ϊ�趨ֵ�ı���ͼ
	
}

/*�����ı���ı���ͼƬ��Alphaֵ*/
int DialogBK_TxtPlay::BK_alpha(string sets)
{
	//BK_Alpha = stoi(sets.substr(6, 3));
	return stoi(sets.substr(6, 3));
}

void Tachie_TxtPlay::TachieShowCase(string sets, string contents)
{
	bool flag = 1;
	//��ͼƬ����ص�������Ա�
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
//����Ŀ�ͼ����ɫ
COLORREF Tachie_TxtPlay::TachieColorChoose(string sets)
{
	return RGB(stoi(sets.substr(4, 3)), stoi(sets.substr(7, 3)), stoi(sets.substr(10, 3)));
}
//Ѹ�ټ��س�����
void Tachie_TxtPlay::Tachie_draw(string contents,COLORREF deletecolor)
{
	IMAGE img,new_img;
	loadimage(&img, _T(contents.c_str()));
	// ��ȡͼƬ�Ŀ�Ⱥ͸߶�
	int imgWidth = img.getwidth();
	int imgHeight = img.getheight();

	// �������ű���
	float scaleX = (float)(500) / (float)imgWidth;
	float scaleY = (float)(1500) / (float)imgHeight;
	float scale = min(scaleX, scaleY); // ѡ���С�����ű���

	// �������ź��ͼƬ��С
	int newWidth = (int)(imgWidth * scale);
	int newHeight = (int)(imgHeight * scale);
	loadimage(&new_img, _T(contents.c_str()), newWidth, newHeight);
	putPictureAlpha(100, 179, &new_img, deletecolor, 255);
}
//�������س�����
void Tachie_TxtPlay::Tachie_drawGradually(string contents,COLORREF deletecolor)
{
	IMAGE img,new_img;
	loadimage(&img, _T(contents.c_str()), 500, 720);
	// ��ȡͼƬ�Ŀ�Ⱥ͸߶�
	int imgWidth = img.getwidth();
	int imgHeight = img.getheight();

	// �������ű���
	float scaleX = (float)(500) / (float)imgWidth;
	float scaleY = (float)(1500) / (float)imgHeight;
	float scale = min(scaleX, scaleY); // ѡ���С�����ű���

	// �������ź��ͼƬ��С
	int newWidth = (int)(imgWidth * scale);
	int newHeight = (int)(imgHeight * scale);
	loadimage(&new_img, _T(contents.c_str()), newWidth, newHeight);
	//���ó�ʱʱ��Ϊ510����
	DWORD startTime = GetTickCount();
	DWORD timeout = 510;

	int alpha = 5;

	//��510�����ڽ�����ʾ���棬������û�����
	while (GetTickCount() - startTime < timeout) {
		putPictureAlpha(149, 179, &img, deletecolor, alpha);
		alpha += 5; //�������治͸����

		//����û�����
		//����enter��
		if (_kbhit() && _getch() == '\r') {
			putPictureAlpha(149, 179, &img, deletecolor, 255);
			break;
		}

		//�����⵽���������
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			putPictureAlpha(149, 179, &img, deletecolor, 255);
			break;
		}

		//��ͣ10����
		Sleep(10);
	}
	putPictureAlpha(149, 179, &img, deletecolor, 255);//��֤���ջ���һ�Ų�͸��������
}

COLORREF DialogBK_TxtPlay::DialogColorChoose(string sets)
{
	return RGB(stoi(sets.substr(6, 3)), stoi(sets.substr(9, 3)), stoi(sets.substr(12, 3)));
}