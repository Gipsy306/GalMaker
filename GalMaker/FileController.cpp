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

//�ļ��д�������
//��ȡָ��Ŀ¼�µ��ض��ļ�
void Folder::getFiles(string path, vector<string>& files)
{
	//�ļ����
	intptr_t hFile = 0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮
			//�������,�����б�
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

