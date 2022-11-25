//Append.cpp
#include"功能函数.h"
void Append()
{
	int num = 0;
	studentData student;
	fstream fdat;
	fstream instuf;
	fstream outstuf;
	string filename;
	string othername;
	cout << "请选择增加学生记录的文件。1、默认文件(“c:\\studentsFile.dat”) 2、自命名文件 Q:退出\n";
	char choice;
	cin >> choice;
	switch (choice)
	{
	case '1':
		fdat.open("c:\\studentsFile.dat", ios::in | ios::binary);
		filename = "c:\\studentsFile.dat";
		break;
	case'2':
		cout << "请输入自命名文件名。\n";
		cin >> filename;
		fdat.open(filename, ios::in | ios::binary);
		break;
	default:
		cout << "放弃增加记录，已退出。\n";
		return;
	}
	if (fdat)
	{
		fdat.close();
		cout << "该文件已存在，请选择：1：覆盖原记录 2：在原记录后面追加 3：将原有记录信息保存到一个指定文件，然后重新建立记录 Q/q:退出\n";
		cin >> choice;
		switch (choice)
		{
		case'1':
			fdat.open(filename, ios::out | ios::binary);
			fdat.seekp(0, ios::beg);
			fdat.write((char*)&mark, sizeof(studentData));
			fdat.close();
			break;
		case'2':
			break;
		case'3':
			//将原有记录信息保存到一个指定文件
			cout << "请为转存文件命名。\n";
			cin >> othername;
			instuf.open(filename, ios::in | ios::binary);
			outstuf.open(othername, ios::out | ios::binary);
			instuf.seekg(0, ios::beg);
			outstuf.seekp(0, ios::beg);
			do
			{
				instuf.read((char*)&student, sizeof(studentData));
				outstuf.write((char*)&student, sizeof(studentData));
			} while (!endMark(student));
			instuf.close();
			outstuf.close();
			fdat.open(filename, ios::out | ios::binary);
			fdat.seekp(0, ios::beg);
			fdat.write((char*)&mark, sizeof(studentData));
			fdat.close();
			cout << "原记录已成功存入另一个文件。\n";
			break;
		default:
			cout << "已退出。\n";
			return;
		}
	}
	else
	{
		fdat.close();
		fdat.open(filename, ios::out | ios::binary);
		fdat.seekp(0, ios::beg);
		fdat.write((char*)&mark, sizeof(studentData));
		fdat.close();
	}
	//输入未保存的记录
	cout << "请输入学生记录的增加方式。1、手动输入 2、从另外的学生记录文件中导入学生记录 Q:退出\n";
	cin >> choice;
	outstuf.open(temfile, ios::out | ios::binary);
	outstuf.seekp(0, ios::beg);
	switch (choice)
	{
	case'1':
		cout << "请输入学生人数。\n";
		cin >> num;
		cout << "请手动分别输入学号，姓名，数学，英语，OPP。\n";
		for (int i = 0; i < num; i++)
		{
			cin >> student.ID >> student.name;
			cin >> student.score[0] >> student.score[1] >> student.score[2];
			student.score[3] = student.score[0] + student.score[1] + student.score[2];
			cout << "?\n";
			outstuf.write((char*)&student, sizeof(studentData));
		}
		outstuf.write((char*)&mark, sizeof(studentData));//末尾标记
		outstuf.close();
		cout << "是否要保存数据？Y/N\n";
		cin >> choice;
		if (choice != 'Y' && choice != 'y')
		{
			cout << "放弃保存，已退出\n";
			return;
		}
		//写排名并保存记录
		storeDat(filename);
		break;
	case'2':
		while (1)
		{
			cout << "请输入追加的文件名。\n";
			cin >> othername;
			instuf.open(othername, ios::in | ios::binary);
			if (!instuf)
			{
				cout << "该文件不存在。\n";
			}
			else
			{
				instuf.seekg(0, ios::beg);
				instuf.read((char*)&student, sizeof(studentData));
				for (; !endMark(student); num++)
				{
					outstuf.write((char*)&student, sizeof(studentData));
					instuf.read((char*)&student, sizeof(studentData));
				}
			}
			instuf.close();
			cout << "请选择是否继续追加文件？Y/N\n";
			cin >> choice;
			if (choice != 'Y' && choice != 'y')
			{
				cout << "追加完成！\n";
				outstuf.write((char*)&mark, sizeof(studentData));
				outstuf.close();
				break;
			}
		}
		cout << "是否保存文件？Y/N\n";
		cin >> choice;
		if (choice != 'Y' && choice != 'y')
		{
			cout << "放弃保存，已退出。\n";
		}
		else
		{
			storeDat(filename);
		}
		break;
	default:
		cout << "已退出。\n";
		return;
	}
	outstuf.close();
}