//����Ի�����
//
#pragma once
#ifndef DIALOGBOX_H
#define DIALOGBOX_H
#include"TextBox.h"
#include<graphics.h>
using namespace std;

class dialogBox
{
private:
	int box_x, box_y;//�Ի������Ͻ�λ��
	int box__x,box__y;//�Ի������½�λ��
	char* dialogBoxBackground;//�Ի��򱳾�ͼƬ�ļ�λ��
	int alpha;//����ͼƬ͸���ȣ���ΧΪ0~255��255��ʾ��͸��
	TextBox nameBox, sentenceBox;//�������ͶԻ�������
public:
	dialogBox(int box_x, int box_y, int box__x, int box__y, char* dialogBoxBackground,int alpha,
		int nameBox_x, int nameBox_y, int nameBox__x, int nameBox__y, COLORREF NAMECOLOR, char* NAMETYPEFACE, int nameNHeight,
		int sentenceBox_x, int sentenceBox_y, int sentenceBox__x, int sentenceBox__y, COLORREF SENTENCECOLOR, char* SENENCETYPEFACE, int sentenceNHeight);//���캯��
	void draw(char* name, char* sentence);
};

#endif // !DIALOGBOX_H
