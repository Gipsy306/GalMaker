#include<DialogBox.h>

int main() {
	initgraph(900, 600);
	DialogBox test(0, 0, 899, 599, "D:\\BaiduNetdiskDownload\\PICTURES\\5.png", 90, 0, 0, 20, 99, WHITE, "黑体"，16，30，30，100，100，WHITE, "黑体", 20);
	test.draw("李易航：", "我的钢门比较松弛");
	system("pause"); // 暂停，等待用户按键
	closegraph(); // 关闭图形窗口

	return 0;
}