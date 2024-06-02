//该头文件用于实现将输入的指令转化为可以被 "showcase.h" 头文件下的类识别并处理的 ".txt" 文件。
#pragma once
#ifndef TXTMAKER_H
#define TXTMAKER_H

//调取 "FileController" 类
#include"FileController.h"
// 调取 "UI" 类
#include"UI.h"
//将文件的有关操作写入对应的".txt"文件中
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

//单例类TexttoTxt,继承于FiletoTxt，主要实现“剧本txt”中文本部分的编写
class TexttoTxt :public FiletoTxt
{
private:
	static TexttoTxt* pTexttoTxt;
public:
	static TexttoTxt* getInstance()
	{
		return pTexttoTxt;
	}
	
	//设置文本配置的函数
	string TextSets(ExMessage mouse);
	/*设置文本颜色的函数*/
	string TextColor(ExMessage mouse);
};

//单例类CGtoTxt,继承于FiletoTxt，主要实现“剧本txt”中CG部分的编写
class CGtoTxt :public FiletoTxt
{
private:
	static CGtoTxt* pCGtoTxt;
public:
	static CGtoTxt* getInstacne()
	{
		return pCGtoTxt;
	}
	//设置CG配置的函数
	string CGSets(ExMessage mouse);
	/*设置CG播放形式的函数*/
	string CGSpeed(ExMessage mouse);
};

string CharToStr(char*);

#endif // !TXTMAKER_H

