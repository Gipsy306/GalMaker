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
#include<vector>

#include"UI.h"

using namespace std;

//�ļ��й������
//���ｫ����д������ʽ�ĵ���
class Folder
{
private:
	static Folder* pFolder;
	string* FolderPath;
public:
	/*�����Ѿ�������ɵ����ʵ��*/
	static Folder* getInstance()
	{
		return pFolder;
	}
	/*��ȡָ��Ŀ¼�µ��ض��ļ�*/
	void GetFiles(string path,ExMessage mouse);
	void getFiles(string path, vector<string>& files);
	
	/*��Ŀ���ļ���*/
	void OpenFolder(string choice);

};


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
