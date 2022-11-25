//Search.cpp
#include"功能函数.h"
void Search()
{
	char item;
	char choice;
	char subject;
	int ID;
	string name;
	double score[4] = { 0 };
	int rank[4] = { 0 };
	string filename;
	studentData student;
	cout << "请输入进行查询操作的文件名类型。1、默认文件“c:\\studentsFile.dat” 2、自命名 Q/q:退出\n";
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
	if (!fdat)
	{
		cout << "该文件不存在，已退出。\n";
	}
	else
	{
		cout << "请输入查询的项目。1、学号 2、姓名 3、名次 Q/q:退出\n";
		cin >> item;
		switch (item)
		{
		case'1':
			cout << "请输入要查询的学号。\n";
			cin >> ID;
			do
			{
				fdat.read((char*)&student, sizeof(studentData));
			} while (!endMark(student) && student.ID != ID);
			if (student.ID == ID)
			{
				outputstudent(student);
			}
			else
			{
				cout << "记录不存在,已退出。" << endl;
			}
			fdat.close();
			break;
		case'2':
			cout << "请输入要查询的姓名。\n";
			cin >> name;
			do
			{
				fdat.read((char*)&student, sizeof(studentData));
			} while (!endMark(student) && student.name != name);
			if (student.name == name)
			{
				outputstudent(student);
			}
			else
			{
				cout << "记录不存在,已退出。" << endl;
			}
			fdat.close();
			break;
		case'3':
			cout << "请输入要查询的科目。1、数学名次 2、英语名次 3、OPP名次 4、总名次\n";
			cin >> subject;
			switch (subject)
			{
			case'1':
				cout << "请输入名次。\n";
				cin >> rank[0];
				do
				{
					fdat.read((char*)&student, sizeof(studentData));
				} while (!endMark(student) && student.rank[0] != rank[0]);
				if (student.rank[0] == rank[0])
				{
					outputstudent(student);
				}
				else
				{
					cout << "记录不存在,已退出。" << endl;
				}
				fdat.close();
				break;
			case'2':
				cout << "请输入名次。\n";
				cin >> rank[1];
				do
				{
					fdat.read((char*)&student, sizeof(studentData));
				} while (!endMark(student) && student.rank[1] != rank[1]);
				if (student.rank[1] == rank[1])
				{
					outputstudent(student);
				}
				else
				{
					cout << "记录不存在,已退出。" << endl;
				}
				fdat.close();
				break;
			case'3':
				cout << "请输入名次,已退出。\n";
				cin >> rank[2];
				do
				{
					fdat.read((char*)&student, sizeof(studentData));
				} while (!endMark(student) && student.rank[2] != rank[2]);
				if (student.rank[2] == rank[2])
				{
					outputstudent(student);
				}
				else
				{
					cout << "记录不存在。" << endl;
				}
				fdat.close();
				break;
				cout << "请输入名次。\n";
				cin >> rank[0];
				do
				{
					fdat.read((char*)&student, sizeof(studentData));
				} while (!endMark(student) && student.rank[0] != rank[0]);
				if (student.rank[0] == rank[0])
				{
					outputstudent(student);
				}
				else
				{
					cout << "记录不存在,已退出。" << endl;
				}
				fdat.close();
				break;
			case'4':
				cout << "请输入名次。\n";
				cin >> rank[3];
				do
				{
					fdat.read((char*)&student, sizeof(studentData));
				} while (!endMark(student) && student.rank[3] != rank[3]);
				if (student.rank[3] == rank[3])
				{
					outputstudent(student);
				}
				else
				{
					cout << "记录不存在,已退出。" << endl;
				}
				fdat.close();
				break;
			default:
				cout << "输入有误，已退出。\n";
				return;
			}
			break;
		default:
			cout << "输入有误，已退出。\n";
			return;
		}
	}
}