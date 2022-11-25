//Revise.cpp
#include"功能函数.h"
void Revise()
{
	const studentData deletemark = { 0,"!\0", {-3,-1,-1,-1}, {-1,-1,-1,-1} };
	studentData student;
	char item;
	char subject;
	char choice;
	int ID;
	string name;
	int rank[4] = { 0 };
	string filename;
	cout << "请输入进行修改操作的文件名类型。1、默认文件“c:\\studentsFile.dat” 2、自命名 Q/q:退出\n";
	cin >> choice;
	if (choice == '1')filename = "c:\\studentsFile.dat";
	else if (choice == '2')
	{
		cout << "请输入文件名。\n";
		cin >> filename;
	}
	else
	{
		cout << "已退出。\n";
		return;
	}
	fstream fdat(filename, ios::in | ios::binary);
	fdat.seekg(0, ios::beg);
	fstream fdat_tem(temfile, ios::out | ios::binary);
	fdat_tem.seekp(0, ios::beg);
	if (!fdat)
	{
		cout << "该文件不存在，已退出。\n";
		return;
	}
	//空表？
	fdat.read((char*)&student, sizeof(studentData));
	if (endMark(student))
	{
		cout << "这是一个空表。已退出。\n";
		fdat.close();
		fdat_tem.close();
		return;
	}
	fdat.seekg(0, ios::beg);
	cout << "请输入修改操作的检索项目。1、学号 2、姓名 3、名次 Q/q:退出\n";
	cin >> item;
	switch (item)
	{
	case'1':
		cout << "请输入学号。\n";
		cin >> ID;
		do
		{
			fdat.read((char*)&student, sizeof(studentData));
			fdat_tem.write((char*)&student, sizeof(studentData));
		} while (!endMark(student) && ID != student.ID);
		if (ID == student.ID)
		{
			outputstudent(student);
			fdat_tem.seekp(-long(sizeof(studentData)), ios::cur);
			fdat_tem.write((char*)&deletemark, sizeof(studentData));
		}
		else
		{
			cout << "未找到，已退出。\n";
			fdat.close();
			return;
		}
		break;
	case'2':
		cout << "请输入姓名。\n";
		cin >> name;
		do
		{
			fdat.read((char*)&student, sizeof(studentData));
			fdat_tem.write((char*)&student, sizeof(studentData));
		} while (!endMark(student) && name != student.name);
		if (name == student.name)
		{
			outputstudent(student);
			fdat_tem.seekp(-long(sizeof(studentData)), ios::cur);
			fdat_tem.write((char*)&deletemark, sizeof(studentData));
		}
		else
		{
			cout << "未找到，已退出。\n";
			fdat.close();
			return;
		}
		break;
	case'3':
		cout << "请选择科目名次。1、数学 2、英语 3、OPP 4、总排名 Q:退出\n";
		cin >> subject;
		switch (subject)
		{
		case'1':
			cout << "请输入数学名次。\n";
			cin >> rank[0];
			do
			{
				fdat.read((char*)&student, sizeof(studentData));
				fdat_tem.write((char*)&student, sizeof(studentData));
			} while (!endMark(student) && rank[0] != student.rank[0]);
			if (rank[0] == student.rank[0])
			{
				outputstudent(student);
				fdat_tem.seekp(-long(sizeof(studentData)), ios::cur);
				fdat_tem.write((char*)&deletemark, sizeof(studentData));
			}
			else
			{
				cout << "未找到，已退出。\n";
				fdat.close();
				return;
			}
			break;
		case'2':
			cout << "请输入英语名次。\n";
			cin >> rank[1];
			do
			{
				fdat.read((char*)&student, sizeof(studentData));
				fdat_tem.write((char*)&student, sizeof(studentData));
			} while (!endMark(student) && rank[1] != student.rank[1]);
			if (rank[1] == student.rank[1])
			{
				outputstudent(student);
				fdat_tem.seekp(-long(sizeof(studentData)), ios::cur);
				fdat_tem.write((char*)&deletemark, sizeof(studentData));
			}
			else
			{
				cout << "未找到，已退出。\n";
				fdat.close();
				return;
			}
			break;
		case'3':
			cout << "请输入OPP名次。\n";
			cin >> rank[2];
			do
			{
				fdat.read((char*)&student, sizeof(studentData));
				fdat_tem.write((char*)&student, sizeof(studentData));
			} while (!endMark(student) && rank[2] != student.rank[2]);
			if (rank[2] == student.rank[2])
			{
				outputstudent(student);
				fdat_tem.seekp(-long(sizeof(studentData)), ios::cur);
				fdat_tem.write((char*)&deletemark, sizeof(studentData));
			}
			else
			{
				cout << "未找到，已退出。\n";
				fdat.close();
				return;
			}
			break;
		case'4':
			cout << "请输入总名次。\n";
			cin >> rank[3];
			do
			{
				fdat.read((char*)&student, sizeof(studentData));
				fdat_tem.write((char*)&student, sizeof(studentData));
			} while (!endMark(student) && rank[3] != student.rank[3]);
			if (rank[3] == student.rank[3])
			{
				outputstudent(student);
				fdat_tem.seekp(-long(sizeof(studentData)), ios::cur);
				fdat_tem.write((char*)&deletemark, sizeof(studentData));
			}
			else
			{
				cout << "未找到，已退出。\n";
				fdat.close();
				return;
			}
			break;
		default:
			cout << "输入有误，已退出。\n";
			fdat.close();
			return;
		}
		break;
	default:
		cout << "输入有误，已退出。\n";
		fdat.close();
		return;
	}
	do
	{
		fdat.read((char*)&student, sizeof(studentData));
		fdat_tem.write((char*)&student, sizeof(studentData));
	} while (!endMark(student));
	fdat.close();
	fdat_tem.close();
	cout << "请确认是否对记录进行修改？Y/N\n";
	cin >> choice;
	if (choice != 'Y' && choice != 'y')
	{
		cout << "放弃删除，已退出。\n";
		return;
	}
	else
	{
		fdat.open(filename, ios::out | ios::binary);
		fdat.seekp(0, ios::beg);
		fdat_tem.open(temfile, ios::in | ios::binary);
		fdat_tem.seekg(0, ios::beg);
		fdat_tem.read((char*)&student, sizeof(studentData));
		while (student.score[0] != -3)
		{
			fdat.write((char*)&student, sizeof(studentData));
			fdat_tem.read((char*)&student, sizeof(studentData));
		}
		cout << "请依次输入新的学号、姓名、数学成绩、英语成绩、OPP成绩。\n";
		cin >> student.ID >> student.name;
		cin >> student.score[0] >> student.score[1] >> student.score[2];
		student.score[3] = student.score[0] + student.score[1] + student.score[2];
		fdat.write((char*)&student, sizeof(studentData));
		do
		{
			fdat_tem.read((char*)&student, sizeof(studentData));
			fdat.write((char*)&student, sizeof(studentData));
		} while (!endMark(student));
		fdat.close();
		fdat_tem.close();
		renewRank(filename);
		cout << "修改成功！\n";
		return;
	}
}