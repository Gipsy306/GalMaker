//�����������
#pragma once
#ifndef TACHIEBOX_H
#define TACHIEBOX_H
#include<graphics.h>
#include"PutPictuerAlpha.h"

class tachieBox {
private:
	int box_x, box_y;//��������Ͻ�λ��
	int box__x, box__y;//�������½�λ��
public:
	tachieBox(int box_x, box_y, box__x, box__y);//���캯��
	void draw(const char* character);//ֱ�ӻ��Ƴ����棬��Ҫ���ڸı�ͬһ��ɫ��ͬ���������
	void drawGradually(const char* character);//������ʾ������
};

#endif // !TACHIEBOX_H
