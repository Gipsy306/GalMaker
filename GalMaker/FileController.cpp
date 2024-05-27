#include "FileController.h"

//文件夹处理函数：
//获取指定目录下的特定文件
void Folder::getAllFiles(string path, vector<string>& files, string fileType)
{     //文件句柄  
	long hFile = 0;
	struct _finddata_t  fileInfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + fileType).c_str(), &fileInfo)) != -1)
	{
		do
		{
			files.push_back(p.assign(path).append("\\").append(fileInfo.name));
		} while (_findnext(hFile, &fileInfo) == 0);
		_findclose(hFile);//关闭句柄  
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

