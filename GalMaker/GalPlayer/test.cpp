#include"DialogBox.h"
#include"CG.h"
#include"TachieBox.h"


cg* cg::pcg = new cg;
int main() {
	initgraph(1600, 900);
<<<<<<< HEAD
	dialogBox test(0, 759, 1599, 899, "res/img/MAP001.png", RGB(0, 0, 0), 90, 19, 969, 1599, 999, BLACK, "����", 25, 959, 1009, 1599, 899, BLACK, "����", 25);
=======
	dialogBox test(0, 539, 1599, 899, "D:\\test\\��ɫ�Ի���.png", RGB(0, 0, 0), 90, 19, 549, 1599, 579, BLACK, "����", 25, 19, 589, 1599, 899, BLACK, "����", 25);
>>>>>>> 1e900483244df9d217deeebfce636023cacafb1c
	tachieBox ttest(149, 179, 649, 899, 0xfafafa);
	tachieBox tttest(549, 179, 1049, 899, 0xfafafa);
	cg::getInstacne()->setCGPicture("res/img/123456.jpg");
	cg::getInstacne()->CGdrawGradually();

	system("pause");

	cleardevice();
	cg::getInstacne()->setCGPicture("res/img/123456.jpg");
	cg::getInstacne()->CGdrawGradually();
<<<<<<< HEAD
	ttest.drawGradually("res/img/123456.jpg");
	//test.emerge();
	test.draw("GM�","������һ�β�������������");
=======
	ttest.drawGradually("D:\\test\\�������.jpg");
	test.emerge("GM�", "������һ�β�������������");
>>>>>>> 1e900483244df9d217deeebfce636023cacafb1c
			
	system("pause");

	cg::getInstacne()->draw();
	ttest.draw("res/img/123456.jpg");
	tttest.draw("res/img/123456.jpg");
	test.draw("GM�", "Ȼ�����������л����ԡ�����");
	

	system("pause"); // ��ͣ���ȴ��û�����
	closegraph(); // �ر�ͼ�δ���

	return 0;
}