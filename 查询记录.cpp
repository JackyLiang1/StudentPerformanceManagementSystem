//Search.cpp
#include"���ܺ���.h"
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
	cout << "��������в�ѯ�������ļ������͡�1��Ĭ���ļ���c:\\studentsFile.dat�� 2�������� Q/q:�˳�\n";
	cin >> choice;
	if (choice == '1')filename = "c:\\studentsFile.dat";
	else if (choice == '2')
	{
		cout << "�������ļ�����\n";
		cin >> filename;
	}
	else
	{
		cout << "���˳���\n";
		return;
	}
	fstream fdat(filename, ios::in | ios::binary);
	fdat.seekg(0, ios::beg);
	if (!fdat)
	{
		cout << "���ļ������ڣ����˳���\n";
	}
	else
	{
		cout << "�������ѯ����Ŀ��1��ѧ�� 2������ 3������ Q/q:�˳�\n";
		cin >> item;
		switch (item)
		{
		case'1':
			cout << "������Ҫ��ѯ��ѧ�š�\n";
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
				cout << "��¼������,���˳���" << endl;
			}
			fdat.close();
			break;
		case'2':
			cout << "������Ҫ��ѯ��������\n";
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
				cout << "��¼������,���˳���" << endl;
			}
			fdat.close();
			break;
		case'3':
			cout << "������Ҫ��ѯ�Ŀ�Ŀ��1����ѧ���� 2��Ӣ������ 3��OPP���� 4��������\n";
			cin >> subject;
			switch (subject)
			{
			case'1':
				cout << "���������Ρ�\n";
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
					cout << "��¼������,���˳���" << endl;
				}
				fdat.close();
				break;
			case'2':
				cout << "���������Ρ�\n";
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
					cout << "��¼������,���˳���" << endl;
				}
				fdat.close();
				break;
			case'3':
				cout << "����������,���˳���\n";
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
					cout << "��¼�����ڡ�" << endl;
				}
				fdat.close();
				break;
				cout << "���������Ρ�\n";
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
					cout << "��¼������,���˳���" << endl;
				}
				fdat.close();
				break;
			case'4':
				cout << "���������Ρ�\n";
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
					cout << "��¼������,���˳���" << endl;
				}
				fdat.close();
				break;
			default:
				cout << "�����������˳���\n";
				return;
			}
			break;
		default:
			cout << "�����������˳���\n";
			return;
		}
	}
}