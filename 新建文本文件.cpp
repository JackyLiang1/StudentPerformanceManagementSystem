//CreateTxt.cpp
#include"���ܺ���.h"
void CreateTxt()
{
	char choice;
	studentData student;
	string fdatname;
	string ftxtname;
	cout << "��ѡ��ת�����ļ��������͡�1����c:\\studentsFile.dat����Ĭ���ļ�����  2��������  Q/q:�˳�\n";
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
		cout << "������Ҫ��ʾ���ļ���\n";
		cin >> fdatname;
		break;
	}
	default:
		cout << "���˳���\n";
		return;
	}
	fdat.open(fdatname, ios::in | ios::binary);
	//������
	if (!fdat)
	{
		cout << "��⵽�ļ������ڣ����˳���\n";
		fdat.close();
		return;
	}
	//�����ı��ļ�
	cout << "�������½��ı��ļ�������ʽ��1��Ĭ���ļ���(��c:\\studentsFile.txt��) 2�������� Q���˳�\n";
	cin >> choice;
	switch (choice)
	{
	case '1':
		ftxtname = "c:\\studentsFile.txt";
		break;
	case'2':
		cout << "���������������ı��ļ�����\n";
		cin >> ftxtname;
		cout << endl;
		break;
	default:
		cout << "���˳���\n";
		return;
	}
	ftxt.open(ftxtname, ios::in);
	if (ftxt)
	{
		cout << "��⵽ԭ�ı��ļ��Ѵ��ڣ���д��������ԭ�����ݣ�Ҫ�����ı�ת����(Y/N)\n";
		char answer;
		cin >> answer;
		if (answer != 'Y' && answer != 'y')
		{
			cout << "���˳���\n";
			ftxt.close();
			return;
		}
	}
	ftxt.close();
	//�����ı�
	ftxt.open(ftxtname, ios::out);
	fdat.seekg(0, ios::beg);
	ftxt << "\n\t\t\t\tѧ���ɼ���¼�ļ�\n\n"
		<< "ѧ��\t" << "����\t"
		<< "��ѧ\t" << "Ӣ��\t" << "OPP\t" << "�ܷ�\t"
		<< "��ѧ����\t" << "Ӣ������\t" << "OPP����\t" << "������\n";
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
	cout << "�ı������ɹ���\n";
}