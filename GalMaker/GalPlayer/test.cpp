#include"DialogBox.h"
#include"CG.h"
#include"TachieBox.h"


cg* cg::pcg = new cg;
int main() {
	initgraph(1600, 900);
	dialogBox test(0, 539, 1599, 899, "D:\\test\\��ɫ�Ի���.png", RGB(0, 0, 0), 90, 19, 549, 1599, 579, BLACK, "����", 25, 19, 589, 1599, 899, BLACK, "����", 25);
	tachieBox ttest(149, 179, 649, 899, 0xfafafa);
	tachieBox tttest(549, 179, 1049, 899, 0xfafafa);
	cg::getInstacne()->setCGPicture("D:\\test\\CG����.jpg");
	cg::getInstacne()->CGdrawGradually();

	system("pause");

	cleardevice();
	cg::getInstacne()->setCGPicture("D:\\test\\BG����.jpg");
	cg::getInstacne()->CGdrawGradually();
	ttest.drawGradually("D:\\test\\�������.jpg");
	test.emerge("GM�", "������һ�β�������������");
			
	system("pause");

	cg::getInstacne()->draw();
	ttest.draw("D:\\test\\�����л�����.jpg");
	tttest.draw("D:\\test\\�������.jpg");
	test.draw("GM�", "Ȼ�����������л����ԡ�����");
	

	system("pause"); // ��ͣ���ȴ��û�����
	closegraph(); // �ر�ͼ�δ���

	return 0;
}