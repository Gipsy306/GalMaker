//��ͷ�ļ�����ʵ�ֽ������ָ��ת��Ϊ���Ա� "showcase.h" ͷ�ļ��µ���ʶ�𲢴���� ".txt" �ļ���
#pragma once
#ifndef TXTMAKER_H
#define TXTMAKER_H

//��ȡ "FileController" ��
#include"FileController.h"
// ��ȡ "UI" ��
#include"UI.h"
//��ȡ�ı������
#include"GalPlayer/DialogBox.h"

//���ļ����йز���д���Ӧ��".txt"�ļ���
class FiletoTxt
{
private:
	static FiletoTxt* pFiletoTxt;
public:
	static FiletoTxt* getInstance()
	{
		return pFiletoTxt;
	}
	int ContentsAdd(const string& save_name,ExMessage mouse);
	void FileIn(string type, const string& save_name,ExMessage mouse);
};

//������TexttoTxt,�̳���FiletoTxt����Ҫʵ�֡��籾txt�����ı����ֵı�д
class TexttoTxt :public FiletoTxt
{
private:
	static TexttoTxt* pTexttoTxt;
public:
	static TexttoTxt* getInstance()
	{
		return pTexttoTxt;
	}
	
	//�����ı����õĺ���
	string TextSets(ExMessage mouse);
	/*�����ı���ɫ�ĺ���*/
	string TextColor(ExMessage mouse);
};

//������CGtoTxt,�̳���FiletoTxt����Ҫʵ�֡��籾txt����CG���ֵı�д
class CGtoTxt :public FiletoTxt
{
private:
	static CGtoTxt* pCGtoTxt;
public:
	static CGtoTxt* getInstacne()
	{
		return pCGtoTxt;
	}
	//����CG���õĺ���
	string CGSets(ExMessage mouse);
	/*����CG������ʽ�ĺ���*/
	string CGSpeed(ExMessage mouse);
};

//������DialogtoTxt,�̳���FiletoTxt����Ҫʵ�֡��籾txt�����ı��򲿷ֵı�д
class DialogtoTxt :public FiletoTxt
{
private:
	static DialogtoTxt* pDialogtoTxt;

public:
	static DialogtoTxt* getInstacne()
	{
		return pDialogtoTxt;
	}
	//�����ı������õĺ���
	string DialogSets(ExMessage mouse);
	/*�����Ƿ�ı䱳����ͼƬ��ʽ*/
	string DialogBK(ExMessage mouse);
	/*�����ı����ı��Ĵ�ӡ��ʽ*/
	string DialogSpeed(ExMessage mouse);
	/*�����ı����ı�����ɫ*/
	string DialogColor(ExMessage mouse);
	/*�����ı��򱳾�ͼƬ�Ĵ�ӡ��ʽ*/
	string DialogBKSpeed(ExMessage mouse);
	/*�����ı��򱳾�ͼƬ��Alphaֵ*/
	string DialogBKAlpha(ExMessage mouse);
};

//������DialogtoTxt,�̳���FiletoTxt����Ҫʵ�֡��籾txt�����ı��򲿷ֵı�д
class TachietoTxt :public FiletoTxt
{
private:
	static TachietoTxt* pTachietoTxt;
public:
	static TachietoTxt* getInstance()
	{
		return pTachietoTxt;
	}
	//�����������õĺ���
	string TachieSets(ExMessage mouse);
	/*�������沥����ʽ�ĺ���*/
	string TachieSpeed(ExMessage mouse);
};

/*�Զ�����ɫ�����뺯��*/
string SelfSetColor();
string SelfDeleteColor();
string ColorCheck(char*);
#endif // !TXTMAKER_H

