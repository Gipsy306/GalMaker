#include"DialogBox.h"
#include"CG.h"
#include"TachieBox.h"


cg* cg::pcg = new cg;
int main() {
	initgraph(1600, 900);
	dialogBox test(0, 759, 1599, 899, "res/img/MAP001.png", RGB(0, 0, 0), 90, 19, 969, 1599, 999, BLACK, "黑体", 25, 959, 1009, 1599, 899, BLACK, "黑体", 25);
	tachieBox ttest(149, 179, 649, 899, 0xfafafa);
	tachieBox tttest(549, 179, 1049, 899, 0xfafafa);
	cg::getInstacne()->setCGPicture("res/img/123456.jpg");
	cg::getInstacne()->CGdrawGradually();

	//system("pause");

	cleardevice();
	cg::getInstacne()->setCGPicture("res/img/123456.jpg");
	cg::getInstacne()->CGdrawGradually();
	ttest.drawGradually("res/img/123456.jpg");
	//test.emerge();
	test.draw("GM娘：","这里是一段测试用例。喵。");
			
	//system("pause");

	cg::getInstacne()->draw();
	ttest.draw("res/img/123456.jpg");
	tttest.draw("res/img/123456.jpg");
	test.draw("GM娘：", "然后这是立绘切换测试。喵。");
	

	system("pause"); // 暂停，等待用户按键
	closegraph(); // 关闭图形窗口

	return 0;
}