//����Ի�����
#pragma once
#ifndef DIALOGBOX_H
#define DIALOGBOX_H
#include"TextBox.h"
#include"PutPictuerAlpha.h"
#include<graphics.h>
#include<conio.h>
using namespace std;

class dialogBox
{
private:
	int box_x, box_y;//�Ի������Ͻ�λ��
	int box__x,box__y;//�Ի������½�λ��
	const char* dialogBoxBackground;//�Ի��򱳾�ͼƬ�ļ�λ��
	COLORREF transparentColor;//����ͼƬ��Ҫ����Ϊ͸������ɫ
	int alpha;//����ͼƬ͸���ȣ���ΧΪ0~255��255��ʾ��͸��
	TextBox nameBox, sentenceBox;//�������ͶԻ�������
public:
	dialogBox(int box_x, int box_y, int box__x, int box__y,\
		const char* dialogBoxBackground, COLORREF transparentColor,int alpha,\
		int nameBox_x, int nameBox_y, int nameBox__x, int nameBox__y, \
		COLORREF NAMECOLOR, const char* NAMETYPEFACE, int nameNHeight,
		int sentenceBox_x, int sentenceBox_y, int sentenceBox__x, int sentenceBox__y,\
		COLORREF SENTENCECOLOR, const char* SENENCETYPEFACE, int sentenceNHeight);//���캯��
	void draw(const char* name, const char* sentence);//��ʾһ��Ի�
	void emerge(const char* name, const char* sentence);
};

#endif // !DIALOGBOX_H
