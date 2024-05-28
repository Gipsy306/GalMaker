#include "FileController.h"

void Folder::GetFiles(string path)
{
	vector<string> files;
	getFiles(path, files);
	char str[30];
	int size = files.size();
	int nullSize = 0;
	for (int i = 0; i < size; i++)
	{
		cout << files[i].c_str() << endl;
	}
}

//文件夹处理函数：
//获取指定目录下的特定文件
void Folder::getFiles(string path, vector<string>& files)
{
	//文件句柄
	intptr_t hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	
}

//根据选择打开目标文件夹，并读取文件
void Folder::OpenFolder(string choice)
{
	//获取对应的选择
	cin >> choice;


}


//读取文件的函数，及其派生：
void FileControl::getFile()
{

}

void WordControl::getFile()
{

	cin >> WordIn;
}

