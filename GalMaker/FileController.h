//������Ϊ�ļ��Ĺ�����
//���ж�ȡres�ļ����е��ļ�����ȡres�ļ����е��ļ�������ʱ�����еĹ���
#pragma once
#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H
#include<iostream>
#include<fstream>
#include<direct.h>
#include<string>
#include<io.h>
#include<Windows.h>
using namespace std;

//�ļ��й������
//���ｫ����д������ʽ�ĵ���
class Folder
{
private:
	const char* FolderName;
	static Folder* pFolder;
public:
	/*�����Ѿ�������ɵ����ʵ��*/
	static Folder* getInstance()
	{
		return pFolder;
	}
	/*���ļ���*/
};
//�����ʼ��������ȫ�ֱ���
Folder* Folder::pFolder = new Folder;

//�ļ�����Ļ���
class FileControl
{
private:
public:
	FileControl(){}
	void getFile();
};
//�ļ��������������ı��Ĵ���
class WordControl :public FileControl
{
private:
	string WordIn;
public:
	void getFile();
};

class ImgControl:public FileControl
{
private:

};
#endif // !FILECONTROLLER_H
