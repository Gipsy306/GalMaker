#include"DialogBox.h"
#include"CG.h"
#include"TachieBox.h"


cg* cg::pcg = new cg;
int main() {
	initgraph(1600, 900);
	dialogBox test(0, 959, 1599, 899, "D:\\test\\CG����.jpg", RGB(0, 0, 0), 90, 19, 969, 1599, 999, BLACK, "����", 25, 959, 1009, 1599, 899, BLACK, "����", 25);
	tachieBox ttest(149, 179, 649, 899, 0xfafafa);
	tachieBox tttest(549, 179, 1049, 899, 0xfafafa);
	cg::getInstacne()->setCGPicture("D:\\test\\CG����.jpg");
	cg::getInstacne()->CGdrawGradually();

	//system("pause");

	cleardevice();
	cg::getInstacne()->setCGPicture("D:\\test\\BG����.jpg");
	cg::getInstacne()->CGdrawGradually();
	ttest.drawGradually("D:\\test\\�������.jpg");
	test.emerge();
	test.draw("GM�","������һ�β�������������");
			
	//system("pause");

	cg::getInstacne()->draw();
	ttest.draw("D:\\test\\�����л�����.jpg");
	tttest.draw("D:\\test\\�������.jpg");
	test.draw("GM�", "Ȼ�����������л����ԡ�����");
	

	system("pause"); // ��ͣ���ȴ��û�����
	closegraph(); // �ر�ͼ�δ���

	return 0;
}