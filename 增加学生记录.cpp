//Append.cpp
#include"���ܺ���.h"
void Append()
{
	int num = 0;
	studentData student;
	fstream fdat;
	fstream instuf;
	fstream outstuf;
	string filename;
	string othername;
	cout << "��ѡ������ѧ����¼���ļ���1��Ĭ���ļ�(��c:\\studentsFile.dat��) 2���������ļ� Q:�˳�\n";
	char choice;
	cin >> choice;
	switch (choice)
	{
	case '1':
		fdat.open("c:\\studentsFile.dat", ios::in | ios::binary);
		filename = "c:\\studentsFile.dat";
		break;
	case'2':
		cout << "�������������ļ�����\n";
		cin >> filename;
		fdat.open(filename, ios::in | ios::binary);
		break;
	default:
		cout << "�������Ӽ�¼�����˳���\n";
		return;
	}
	if (fdat)
	{
		fdat.close();
		cout << "���ļ��Ѵ��ڣ���ѡ��1������ԭ��¼ 2����ԭ��¼����׷�� 3����ԭ�м�¼��Ϣ���浽һ��ָ���ļ���Ȼ�����½�����¼ Q/q:�˳�\n";
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
			//��ԭ�м�¼��Ϣ���浽һ��ָ���ļ�
			cout << "��Ϊת���ļ�������\n";
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
			cout << "ԭ��¼�ѳɹ�������һ���ļ���\n";
			break;
		default:
			cout << "���˳���\n";
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
	//����δ����ļ�¼
	cout << "������ѧ����¼�����ӷ�ʽ��1���ֶ����� 2���������ѧ����¼�ļ��е���ѧ����¼ Q:�˳�\n";
	cin >> choice;
	outstuf.open(temfile, ios::out | ios::binary);
	outstuf.seekp(0, ios::beg);
	switch (choice)
	{
	case'1':
		cout << "������ѧ��������\n";
		cin >> num;
		cout << "���ֶ��ֱ�����ѧ�ţ���������ѧ��Ӣ�OPP��\n";
		for (int i = 0; i < num; i++)
		{
			cin >> student.ID >> student.name;
			cin >> student.score[0] >> student.score[1] >> student.score[2];
			student.score[3] = student.score[0] + student.score[1] + student.score[2];
			cout << "?\n";
			outstuf.write((char*)&student, sizeof(studentData));
		}
		outstuf.write((char*)&mark, sizeof(studentData));//ĩβ���
		outstuf.close();
		cout << "�Ƿ�Ҫ�������ݣ�Y/N\n";
		cin >> choice;
		if (choice != 'Y' && choice != 'y')
		{
			cout << "�������棬���˳�\n";
			return;
		}
		//д�����������¼
		storeDat(filename);
		break;
	case'2':
		while (1)
		{
			cout << "������׷�ӵ��ļ�����\n";
			cin >> othername;
			instuf.open(othername, ios::in | ios::binary);
			if (!instuf)
			{
				cout << "���ļ������ڡ�\n";
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
			cout << "��ѡ���Ƿ����׷���ļ���Y/N\n";
			cin >> choice;
			if (choice != 'Y' && choice != 'y')
			{
				cout << "׷����ɣ�\n";
				outstuf.write((char*)&mark, sizeof(studentData));
				outstuf.close();
				break;
			}
		}
		cout << "�Ƿ񱣴��ļ���Y/N\n";
		cin >> choice;
		if (choice != 'Y' && choice != 'y')
		{
			cout << "�������棬���˳���\n";
		}
		else
		{
			storeDat(filename);
		}
		break;
	default:
		cout << "���˳���\n";
		return;
	}
	outstuf.close();
}