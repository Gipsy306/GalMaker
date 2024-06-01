#include"DialogBox.h"
#include"CG.h"
<<<<<<< HEAD
=======

cg* cg::pcg = new cg;
>>>>>>> 32fd40f237196192c5c54088ab1e06d5dcb33405

int main() {
	initgraph(900, 600);
	/*setfillcolor(RED);
	solidcircle(100, 100, 200);
	dialogBox test(0, 0, 899, 599, "D:\\BaiduNetdiskDownload\\PICTURES\\5.png", RGB(255, 255, 255),100, 0, 0, 20, 99, WHITE, "黑体", 16, 30, 30, 500, 100, WHITE, "黑体", 20);
	test.draw("李易航：", "我的钢门比较松弛");*/
<<<<<<< HEAD
	
	cg test("D:\\BaiduNetdiskDownload\\PICTURES\\5.png");
	test.drawGradually();

=======
	cg::getInstacne()->setCGPicture("res/img/MAP001.png");
	while (1)
	{
		cg::getInstacne()->CGdrawGradually();
		Sleep(2000);
		cleardevice();
	}
	cg::getInstacne()->CGdrawGradually();
>>>>>>> 32fd40f237196192c5c54088ab1e06d5dcb33405
	system("pause"); // 暂停，等待用户按键
	closegraph(); // 关闭图形窗口

	return 0;
}