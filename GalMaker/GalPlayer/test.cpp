#include"DialogBox.h"
#include"CG.h"

int main() {
	initgraph(900, 600);
	/*setfillcolor(RED);
	solidcircle(100, 100, 200);
	dialogBox test(0, 0, 899, 599, "D:\\BaiduNetdiskDownload\\PICTURES\\5.png", RGB(255, 255, 255),100, 0, 0, 20, 99, WHITE, "����", 16, 30, 30, 500, 100, WHITE, "����", 20);
	test.draw("���׺���", "�ҵĸ��űȽ��ɳ�");*/
	
	cg test("D:\\BaiduNetdiskDownload\\PICTURES\\5.png");
	test.drawGradually();

	system("pause"); // ��ͣ���ȴ��û�����
	closegraph(); // �ر�ͼ�δ���

	return 0;
}