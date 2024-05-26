#include "FileController.h"

//读取文件的函数，及其派生：
void FileControl::getFile()
{

}

void WordControl::getFile()
{
	Folder::getInstance();
	cin >> WordIn;
}
