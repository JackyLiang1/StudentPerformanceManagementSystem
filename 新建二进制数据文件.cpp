//CreateDat.cpp
#include"功能函数.h"
void CreateDat()
{
	fstream fdat;
	string filename;
	cout << "请选择新建学生文件命名方式。1、默认文件名(“c:\\studentsFile.dat”) 2、自命名 Q:退出\n";
	char choice;
	cin >> choice;
	switch (choice)
	{
	case '1':
		fdat.open("c:\\studentsFile.dat", ios::in);
		filename = "c:\\studentsFile.dat";
		break;
	case'2':
		cout << "请输入自定义文件名。\n";
		cin >> filename;
		cout << endl;
		fdat.open(filename, ios::in);
		break;
	default:
		cout << "已退出。\n";
		return;
	}
	if (fdat)
	{
		cout << "文件已存在，新建同名文件将覆盖原来文件的内容，是否需要新建文件？Y/N\n";
		cin >> choice;
		if (choice != 'Y' && choice != 'y')
		{
			cout << "创建文件失败，已退出。\n";
			return;
		}
	}
	fdat.close();
	fdat.open(filename, ios::out | ios::binary);
	fdat.seekp(0, ios::beg);
	fdat.write((char*)&mark, sizeof(studentData));
	fdat.close();
	cout << "创建成功！\n";
}