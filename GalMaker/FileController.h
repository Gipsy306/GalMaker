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
#include<vector>

#include"UI.h"

using namespace std;

//文件夹管理的类
//这里将该类写作饿汉式的单例
class Folder
{
private:
	static Folder* pFolder;
	string* FolderPath;
public:
	/*返回已经创建完成的类的实例*/
	static Folder* getInstance()
	{
		return pFolder;
	}
	/*获取指定目录下的特定文件*/
	string GetFiles(string path,ExMessage mouse);
	string GetTxtFiles(string path, ExMessage mouse);
	void getFiles(string path, vector<string>& files);
	
	/*打开目标文件夹*/
	void OpenFolder(string choice);
	string CreateProject();
	string OpenProject(ExMessage mouse);
};


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

string CharToStr(char* contentChar);
#endif // !FILECONTROLLER_H
