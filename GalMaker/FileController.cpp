#include "FileController.h"

string Folder::GetFiles(string path, ExMessage mouse)
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

	for (int i = 0; i < size; i++)
	{

		if (link == i)
		{
			delete[] filesChoose;
			delete[] type;
			return files[i];
		}
		else {}
	}

}

string Folder::GetTxtFiles(string path, ExMessage mouse)
{
	vector<string> files;
	getFiles(path, files);
	vector<string> Txtfiles;
	int size = files.size();
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (files[i].back() == 't')
		{
			Txtfiles.push_back(files[i]);
			j++;
		}
	}
	ChooseBox* filesChoose;
	filesChoose = new ChooseBox[size];
	for (int i = 0; i < j; i++)
	{
		filesChoose[i].box_title = Txtfiles[i].c_str();
		filesChoose[i].box_x = 0;
		filesChoose[i].box_y = 20 * i;
		filesChoose[i].length = 500;
		filesChoose[i].width = 20;
	}
	int* type;
	type = new int[j];
	for (int i = 0; i < j; i++)
	{
		type[i] = i;
	}
	initgraph(1200, 900);
	int link = UI_Link::getInstance()->Link_ChooseBox(filesChoose, type, j, mouse);

	for (int i = 0; i < j; i++)
	{

		if (link == i)
		{
			delete[] filesChoose;
			delete[] type;
			return Txtfiles[i];
		}
		else {}
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

//�����µ�GalGame�ļ�
string Folder::CreateProject()
{
	char path_temp[20];
	InputBox(path_temp, 20, "��������Ҫ����������Ŀ������");
	string path_Temp = CharToStr((char*)"projects/") + CharToStr(path_temp);
	//������Ŀ�ļ�����Ҫ��һϵ���ļ���
	CreateDirectory(path_Temp.c_str(), NULL);
	CreateDirectory((path_Temp + CharToStr((char*)"/img")).c_str(), NULL);
	CreateDirectory((path_Temp + CharToStr((char*)"/dialog")).c_str(), NULL);
	CreateDirectory((path_Temp + CharToStr((char*)"/Tachie")).c_str(), NULL);
	CreateDirectory((path_Temp + CharToStr((char*)"/mp3")).c_str(), NULL);
	ofstream out((path_Temp + CharToStr((char*)"/script.txt")).c_str());
	out.close();
	return(path_Temp + CharToStr((char*)"/script.txt"));
}

string Folder::OpenProject(ExMessage mouse)
{
	string path_temp = GetTxtFiles("projects", mouse);
	cleardevice();
	return path_temp;
}


//��ȡ�ļ��ĺ���������������
void FileControl::getFile()
{

}

void WordControl::getFile()
{

	cin >> WordIn;
}

string CharToStr(char* contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}