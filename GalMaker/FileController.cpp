#include "FileController.h"



string Folder::GetFiles(string path,ExMessage mouse)
{
	vector<string> files;
	getFiles(path, files);
	int size = files.size();
	int nullSize = 0;
	ChooseBox* filesChoose;
	filesChoose = new ChooseBox[size];
	for (int i = 0; i < size; i++)
	{
		filesChoose[i].box_title = files[i].c_str();
		filesChoose[i].box_x = 0;
		filesChoose[i].box_y = 20 * i;
		filesChoose[i].length = 500;
		filesChoose[i].width = 20;
	}
	int* type;
	type = new int[size];
	for (int i = 0; i < size; i++)
	{
		type[i] = i;
	}
	initgraph(1200, 900);
	int link = UI_Link::getInstance()->Link_ChooseBox(filesChoose, type, size, mouse);
<<<<<<< HEAD
	
=======
	for (int i = 0; i < size; i++)
	{
<<<<<<< HEAD
		if (link == i)
		{
			delete[] filesChoose;
			delete[] type;
			return files[i];
		}
		else{}
=======
>>>>>>> 23442b55e6858aa247d7c48fe107fdb4e54ff14b

>>>>>>> 731f7c4d65156685edb0c53cc2be1d64d5dc4738
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

