#include"DialogBox.h"
int main() {
	initgraph(900, 600);
	setfillcolor(RED);
	solidcircle(100, 100, 200);
	dialogBox test(0, 0, 899, 599, (char*)"D:\\BaiduNetdiskDownload\\PICTURES\\5.png", RGB(255, 255, 255),100, 0, 0, 20, 99, WHITE, (char*)"����", 16, 30, 30, 500, 100, WHITE, (char*)"����", 20);
	test.draw((char*)"���׺���", (char*)"�ҵĸ��űȽ��ɳ�");
	
	system("pause"); // ��ͣ���ȴ��û�����
	closegraph(); // �ر�ͼ�δ���

	return 0;
}