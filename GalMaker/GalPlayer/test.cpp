#include<DialogBox.h>

int main() {
	initgraph(900, 600);
	DialogBox test(0, 0, 899, 599, "D:\\BaiduNetdiskDownload\\PICTURES\\5.png", 90, 0, 0, 20, 99, WHITE, "����"��16��30��30��100��100��WHITE, "����", 20);
	test.draw("���׺���", "�ҵĸ��űȽ��ɳ�");
	system("pause"); // ��ͣ���ȴ��û�����
	closegraph(); // �ر�ͼ�δ���

	return 0;
}