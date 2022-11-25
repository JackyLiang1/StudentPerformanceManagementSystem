//CreateTxt.cpp
#include"功能函数.h"
void CreateTxt()
{
	char choice;
	studentData student;
	string fdatname;
	string ftxtname;
	cout << "请选择转化的文件命名类型。1：“c:\\studentsFile.dat”（默认文件名）  2：自命名  Q/q:退出\n";
	cin >> choice;
	fstream fdat;
	fstream ftxt;
	switch (choice)
	{
	case '1':
		fdatname = "c:\\studentsFile.dat";
		break;
	case '2':
	{
		cout << "请输入要显示的文件。\n";
		cin >> fdatname;
		break;
	}
	default:
		cout << "已退出。\n";
		return;
	}
	fdat.open(fdatname, ios::in | ios::binary);
	//检测存在
	if (!fdat)
	{
		cout << "检测到文件不存在，已退出。\n";
		fdat.close();
		return;
	}
	//创建文本文件
	cout << "请输入新建文本文件命名方式。1、默认文件名(“c:\\studentsFile.txt”) 2、自命名 Q：退出\n";
	cin >> choice;
	switch (choice)
	{
	case '1':
		ftxtname = "c:\\studentsFile.txt";
		break;
	case'2':
		cout << "请输入新命名的文本文件名。\n";
		cin >> ftxtname;
		cout << endl;
		break;
	default:
		cout << "已退出。\n";
		return;
	}
	ftxt.open(ftxtname, ios::in);
	if (ftxt)
	{
		cout << "检测到原文本文件已存在，若写，将覆盖原有数据，要进行文本转换吗？(Y/N)\n";
		char answer;
		cin >> answer;
		if (answer != 'Y' && answer != 'y')
		{
			cout << "已退出。\n";
			ftxt.close();
			return;
		}
	}
	ftxt.close();
	//建立文本
	ftxt.open(ftxtname, ios::out);
	fdat.seekg(0, ios::beg);
	ftxt << "\n\t\t\t\t学生成绩记录文件\n\n"
		<< "学号\t" << "姓名\t"
		<< "数学\t" << "英语\t" << "OPP\t" << "总分\t"
		<< "数学名次\t" << "英语名次\t" << "OPP名次\t" << "总排名\n";
	while (1)
	{
		fdat.read((char*)&student, sizeof(studentData));
		if (!endMark(student))
		{
			ftxt << student.ID << '\t' << student.name << '\t';
			for (int i = 0; i < 4; i++)ftxt << student.score[i] << '\t';
			for (int i = 0; i < 3; i++)ftxt << student.rank[i] << '\t';
			ftxt << student.rank[3] << '\n';
		}
		else break;
	}
	ftxt.close();
	fdat.close();
	cout << "文本建立成功！\n";
}