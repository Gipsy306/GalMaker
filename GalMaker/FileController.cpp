#include "FileController.h"

//�ļ��д�������
//��ȡָ��Ŀ¼�µ��ض��ļ�
void Folder::getAllFiles(string path, vector<string>& files, string fileType)
{     //�ļ����  
	long hFile = 0;
	struct _finddata_t  fileInfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + fileType).c_str(), &fileInfo)) != -1)
	{
		do
		{
			files.push_back(p.assign(path).append("\\").append(fileInfo.name));
		} while (_findnext(hFile, &fileInfo) == 0);
		_findclose(hFile);//�رվ��  
	}
}
//����ѡ���Ŀ���ļ��У�����ȡ�ļ�
void Folder::OpenFolder(string choice)
{
	//��ȡ��Ӧ��ѡ��
	cin >> choice;


}


//��ȡ�ļ��ĺ���������������
void FileControl::getFile()
{

}

void WordControl::getFile()
{

	cin >> WordIn;
}

