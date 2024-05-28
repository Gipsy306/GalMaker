//ͼ�λ�������������������ڴ������Ҫ��ͼ�λ�������
//�����趨���ಢû��ʲôʵ�ʵĺ��壬ֻ������Ϊ�˱��ڹ������Ӧ�ĺ���������ͬ�������ء�
//��ˣ��������õ��඼�����ˡ��������ĵ�������
//����������һЩѡ��ġ����ݽӿڡ�
#pragma once
#ifndef UI_H
#define UI_H
#include<string>
#include<iostream>
#include<graphics.h>
using namespace std;
constexpr auto DEFAULT = 1;
/*������ģ�鹹������*/
class UI_Basic
{
private:
	static UI_Basic* pUI_Basic;
public:
	static UI_Basic* getInstance()
	{
		return pUI_Basic;
	}
	/*�����Ĺ���������*/
};



/*ѡ���Ĺ���*/
class ChooseBox
{
private:
public:
/*ѡ�����������*/
	/*ѡ����λ��ȷ�������Ͻ����꣩*/
	int box_x;
	int box_y;
	/*ѡ���Ĵ�Сȷ��*/
	int length;
	int width;
	/*ѡ����ϵı�ǩ*/
	const char* box_title;
	/*ѡ���ĸ�ʽ*/
	int box_type;
/*ѡ���Ĺ��캯��*/
	ChooseBox(int xx,int yy,int ll,int ww,const char* title,int type):box_x(xx),box_y(yy),length(ll),width(ww),box_title(title),box_type(type){}
	ChooseBox(int xx, int yy, int ll, int ww, const char* title) :box_x(xx), box_y(yy), length(ll), width(ww), box_title(title),box_type(DEFAULT) {}

/*ѡ���ĺ���*/
	int BoxPrint(ExMessage mouse);
	/*���ƿ��������̬�ĺ���*/
	void BoxDraw(COLORREF);
};




//�ļ������йص�
class UI_File
{
private:
	static UI_File* pUI_File;
public:
	static UI_File* getInstance()
	{
		return pUI_File;
	}

};

/*�����йصĺ���*/
class UI_Link
{
private:
	static UI_Link* pUI_Link;
public:
	static UI_Link* getInstance()
	{
		return pUI_Link;
	}
	/*����ѡ���ĺ���*/
		/*����ѡ���ĺ����������ֵΪһ��ѡ����ָ�� *choosebox �Ͷ�Ӧ������ָ�� *num �Լ���Ӧ��ѡ�������� i */
	int Link_ChooseBox(ChooseBox* choosebox, int* num, int i, ExMessage mouse);
};


#endif // !UI_H
