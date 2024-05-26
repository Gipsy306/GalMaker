//该类作为文件的管理类
//具有读取res文件夹中的文件，调取res文件夹中的文件进入临时容器中的功能
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

//文件夹管理的类
//这里将该类写作饿汉式的单例
class Folder
{
private:
	const char* FolderName;
	static Folder* pFolder;
public:
	/*返回已经创建完成的类的实例*/
	static Folder* getInstance()
	{
		return pFolder;
	}
	/*打开文件夹*/
};
//类外初始化，创建全局变量
Folder* Folder::pFolder = new Folder;

//文件管理的基类
class FileControl
{
private:
public:
	FileControl(){}
	void getFile();
};
//文件管理派生——文本的处理
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
