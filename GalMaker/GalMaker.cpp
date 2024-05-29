// GalMaker.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<DialogBox.h>
#include <iostream>
#include<graphics.h>
using namespace std;
#include"UI.h"
#include "FileController.h"
#include"TxtMaker.h"
#include"TxtPlayer.h"

static ExMessage mouse;
//类外初始化，创建全局变量
Folder* Folder::pFolder = new Folder;
UI_File* UI_File::pUI_File = new UI_File;
UI_Basic* UI_Basic::pUI_Basic = new UI_Basic;
UI_Link* UI_Link::pUI_Link = new UI_Link;
FiletoTxt* FiletoTxt::pFiletoTxt = new FiletoTxt;
TexttoTxt* TexttoTxt::pTexttoTxt = new TexttoTxt;
TxtPlay* TxtPlay::pTxtPlay = new TxtPlay;
Text_TxtPlay* Text_TxtPlay::pText_TxtPlay = new Text_TxtPlay;



int main()

{
<<<<<<< HEAD
	/*对话框测试*/
	//initgraph(900, 600);
	//DialogBox test(0, 0, 899, 599, "D:\\BaiduNetdiskDownload\\PICTURES\\5.png", 90, 0, 0, 20, 99, WHITE, "黑体"，16，30，30，100，100，WHITE, "黑体", 20);
	//test.draw("李易航：", "我的钢门比较松弛");
	//system("pause"); // 暂停，等待用户按键
	//closegraph(); // 关闭图形窗口

	//return 0;


	/*initgraph(900, 600);
	cout << "Hello Git Bash!\n"<<endl;
	cout << "Hello olden!\n" << endl;
	cout << "Hello 123!" << endl; 
	cout << "Hello  456!" << endl;*/
=======
>>>>>>> 3b71b0bf552b38880613dc1b415c00b24aa45f7f
	/*按钮的测试部分*/
	/*initgraph(900, 600);
	ChooseBox TestBox_1[3] = { ChooseBox(10,10,50,20,"Are"),ChooseBox(110,10,50,20,"You"),ChooseBox(210,10,50,20,"OK") };
	ChooseBox TestBox_2[2] = { ChooseBox(10,110,50,20,"确认"),ChooseBox(110,110,50,20,"取消") };
	int a[3] = { 0,1,2 };
	switch (UI_Link::getInstance()->Link_ChooseBox(TestBox_1, a, 3, mouse))
	{
	case (0):cleardevice(); break;
	case (1):circle(200, 200, 100); break;
	case (2):circle(100, 100, 50); break;
	default:break;
	}*/
	/*文件处理的测试部分*/
	/*string path;
	cin >> path;
<<<<<<< HEAD
	Folder::getInstance()->GetFiles(path);*/
	/*getchar();*/
}
=======
	Folder::getInstance()->GetFiles(path);
	getchar();*/
>>>>>>> 3b71b0bf552b38880613dc1b415c00b24aa45f7f

	/*文件转化的演示*/
	/*Step 1: */
	/*initgraph(900, 600);
	while (true)
	{
		FiletoTxt::getInstance()->FileIn(TexttoTxt::getInstance()->TextSets(mouse), "test.txt");
	}*/
	/*Step 2: */
	initgraph(900, 600);
	TxtPlay::getInstacne()->TxtShowCase("test.txt", mouse);
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
