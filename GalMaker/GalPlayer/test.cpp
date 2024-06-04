#include"DialogBox.h"
#include"CG.h"
#include"TachieBox.h"


cg* cg::pcg = new cg;
int main114514() {
	initgraph(1600, 900);
	dialogBox test(0, 539, 1599, 899, "D:\\test\\纯色对话框.png", RGB(0, 0, 0), 90, 19, 549, 1599, 579, BLACK, "黑体", 25, 19, 589, 1599, 899, BLACK, "黑体", 25);
	tachieBox ttest(149, 179, 649, 899, 0xfafafa);
	tachieBox tttest(949, 179, 1449, 899, 0xfafafa);
	cg::getInstacne()->setCGPicture("res/img/123456.jpg");
	cg::getInstacne()->CGdrawGradually();

	system("pause");

	cleardevice();
	cg::getInstacne()->setCGPicture("res/img/123456.jpg");
	cg::getInstacne()->CGdrawGradually();
	ttest.drawGradually("D:\\test\\立绘测试.jpg");
	test.emerge("GM娘：", "这里是一段测试用例。喵。");
	system("pause");

	cg::getInstacne()->draw();
	ttest.draw("res/img/123456.jpg");
	tttest.draw("res/img/123456.jpg");
	test.draw("GM娘：", "然后这是立绘切换测试。喵。");
	

	system("pause"); // 暂停，等待用户按键
	closegraph(); // 关闭图形窗口

	return 0;
}