//�������ֿ��������ɶԻ����е��������Լ��Ի�������
#pragma once
#ifndef TEXTBOX_H
#define TEXTBOX_H
#include<graphics.h>
#include<string>
#include<conio.h>
using namespace std;

class TextBox {
private:
	int box_x, box_y;//���ֿ����Ͻ�λ��
	int box__x, box__y;//���ֿ����½�λ��
	COLORREF TEXTCOLOR ;//������ɫ
	const char* TYPEFACE ;//��������
	int nHeight;//���ָ߶�
public:
	TextBox(int box_x, int box_y, int box__x, int box__y, COLORREF TEXTCOLOR, const char* TYPEFACE, int nHeight);//���캯��
	void draw(const char* content);//�����ֿ����Թ���ʱ�趨��������ʽ���û�����������content
	void drawGradually(const char* content);//������ʾ
};

#endif // !TEXTBOX_H

