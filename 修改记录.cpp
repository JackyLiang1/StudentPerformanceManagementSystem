//Revise.cpp
#include"���ܺ���.h"
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
	cout << "����������޸Ĳ������ļ������͡�1��Ĭ���ļ���c:\\studentsFile.dat�� 2�������� Q/q:�˳�\n";
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
	fstream fdat_tem(temfile, ios::out | ios::binary);
	fdat_tem.seekp(0, ios::beg);
	if (!fdat)
	{
		cout << "���ļ������ڣ����˳���\n";
		return;
	}
	//�ձ�
	fdat.read((char*)&student, sizeof(studentData));
	if (endMark(student))
	{
		cout << "����һ���ձ����˳���\n";
		fdat.close();
		fdat_tem.close();
		return;
	}
	fdat.seekg(0, ios::beg);
	cout << "�������޸Ĳ����ļ�����Ŀ��1��ѧ�� 2������ 3������ Q/q:�˳�\n";
	cin >> item;
	switch (item)
	{
	case'1':
		cout << "������ѧ�š�\n";
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
			cout << "δ�ҵ������˳���\n";
			fdat.close();
			return;
		}
		break;
	case'2':
		cout << "������������\n";
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
			cout << "δ�ҵ������˳���\n";
			fdat.close();
			return;
		}
		break;
	case'3':
		cout << "��ѡ���Ŀ���Ρ�1����ѧ 2��Ӣ�� 3��OPP 4�������� Q:�˳�\n";
		cin >> subject;
		switch (subject)
		{
		case'1':
			cout << "��������ѧ���Ρ�\n";
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
				cout << "δ�ҵ������˳���\n";
				fdat.close();
				return;
			}
			break;
		case'2':
			cout << "������Ӣ�����Ρ�\n";
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
				cout << "δ�ҵ������˳���\n";
				fdat.close();
				return;
			}
			break;
		case'3':
			cout << "������OPP���Ρ�\n";
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
				cout << "δ�ҵ������˳���\n";
				fdat.close();
				return;
			}
			break;
		case'4':
			cout << "�����������Ρ�\n";
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
				cout << "δ�ҵ������˳���\n";
				fdat.close();
				return;
			}
			break;
		default:
			cout << "�����������˳���\n";
			fdat.close();
			return;
		}
		break;
	default:
		cout << "�����������˳���\n";
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
	cout << "��ȷ���Ƿ�Լ�¼�����޸ģ�Y/N\n";
	cin >> choice;
	if (choice != 'Y' && choice != 'y')
	{
		cout << "����ɾ�������˳���\n";
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
		cout << "�����������µ�ѧ�š���������ѧ�ɼ���Ӣ��ɼ���OPP�ɼ���\n";
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
		cout << "�޸ĳɹ���\n";
		return;
	}
}