#include"DialogBox.h"
#include"CG.h"
#include"TachieBox.h"


cg* cg::pcg = new cg;
int main114514() {
	initgraph(1600, 900);
	dialogBox test(0, 539, 1599, 899, "D:\\test\\��ɫ�Ի���.png", RGB(0, 0, 0), 90, 19, 549, 1599, 579, BLACK, "����", 25, 19, 589, 1599, 899, BLACK, "����", 25);
	tachieBox ttest(149, 179, 649, 899, 0xfafafa);
	tachieBox tttest(949, 179, 1449, 899, 0xfafafa);
	cg::getInstacne()->setCGPicture("res/img/123456.jpg");
	cg::getInstacne()->CGdrawGradually();

	system("pause");

	cleardevice();
	cg::getInstacne()->setCGPicture("res/img/123456.jpg");
	cg::getInstacne()->CGdrawGradually();
	ttest.drawGradually("D:\\test\\�������.jpg");
	test.emerge("GM�", "������һ�β�������������");
	system("pause");

	cg::getInstacne()->draw();
	ttest.draw("res/img/123456.jpg");
	tttest.draw("res/img/123456.jpg");
	test.draw("GM�", "Ȼ�����������л����ԡ�����");
	

	system("pause"); // ��ͣ���ȴ��û�����
	closegraph(); // �ر�ͼ�δ���

	return 0;
}