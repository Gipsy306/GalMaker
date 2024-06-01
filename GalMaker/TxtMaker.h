//��ͷ�ļ�����ʵ�ֽ������ָ��ת��Ϊ���Ա� "showcase.h" ͷ�ļ��µ���ʶ�𲢴���� ".txt" �ļ���
#pragma once
#ifndef TXTMAKER_H
#define TXTMAKER_H

//��ȡ "FileController" ��
#include"FileController.h"
// ��ȡ "UI" ��
#include"UI.h"
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
	void ContentsAdd(const string& save_name,ExMessage mouse);
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

string CharToStr(char*);

#endif // !TXTMAKER_H

