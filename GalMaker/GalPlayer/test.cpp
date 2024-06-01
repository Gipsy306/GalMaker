#include"DialogBox.h"
#include"CG.h"
<<<<<<< HEAD


cg* cg::pcg = new cg;


int main114514() {
	initgraph(900, 600);
	/*setfillcolor(RED);
	solidcircle(100, 100, 200);
	dialogBox test(0, 0, 899, 599, "D:\\BaiduNetdiskDownload\\PICTURES\\5.png", RGB(255, 255, 255),100, 0, 0, 20, 99, WHITE, "黑体", 16, 30, 30, 500, 100, WHITE, "黑体", 20);
	test.draw("李易航：", "我的钢门比较松弛");*/


	cg::getInstacne()->setCGPicture("res/img/MAP001.png");
	while (1)
	{
		cg::getInstacne()->CGdrawGradually();
		Sleep(2000);
		cleardevice();
	}
	cg::getInstacne()->CGdrawGradually();

=======
#include"TachieBox.h"


cg* cg::pcg = new cg;
int main() {
	initgraph(1600, 900);
	dialogBox test(0, 959, 1599, 899, "D:\\test\\CG测试.jpg", RGB(0, 0, 0), 90, 19, 969, 1599, 999, BLACK, "黑体", 25, 959, 1009, 1599, 899, BLACK, "黑体", 25);
	tachieBox ttest(149, 179, 649, 899, 0xfafafa);
	tachieBox tttest(549, 179, 1049, 899, 0xfafafa);
	cg::getInstacne()->setCGPicture("D:\\test\\CG测试.jpg");
	cg::getInstacne()->CGdrawGradually();

	//system("pause");

	cleardevice();
	cg::getInstacne()->setCGPicture("D:\\test\\BG测试.jpg");
	cg::getInstacne()->CGdrawGradually();
	ttest.drawGradually("D:\\test\\立绘测试.jpg");
	test.emerge();
	test.draw("GM娘：","这里是一段测试用例。喵。");
			
	//system("pause");

	cg::getInstacne()->draw();
	ttest.draw("D:\\test\\立绘切换测试.jpg");
	tttest.draw("D:\\test\\立绘测试.jpg");
	test.draw("GM娘：", "然后这是立绘切换测试。喵。");
	

>>>>>>> 3fb151c29ea63c9c1f0228c82637c2733a5526cc
	system("pause"); // 暂停，等待用户按键
	closegraph(); // 关闭图形窗口

	return 0;
}