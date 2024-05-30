#include"DialogBox.h"
int main() {
	initgraph(900, 600);
	setfillcolor(RED);
	solidcircle(100, 100, 200);
	Sleep(1000);
	dialogBox test(0, 0, 899, 599, (char*)"res\\img\\MAP001.png",100, 0, 0, 20, 99, WHITE, (char*)"黑体", 16, 30, 30, 500, 100, WHITE, (char*)"黑体", 20);
	test.draw((char*)"李易航：", (char*)"我的钢门比较松弛");
	system("pause"); // 暂停，等待用户按键
	closegraph(); // 关闭图形窗口

	return 0;
}