//CreateDat.cpp
#include"���ܺ���.h"
void CreateDat()
{
	fstream fdat;
	string filename;
	cout << "��ѡ���½�ѧ���ļ�������ʽ��1��Ĭ���ļ���(��c:\\studentsFile.dat��) 2�������� Q:�˳�\n";
	char choice;
	cin >> choice;
	switch (choice)
	{
	case '1':
		fdat.open("c:\\studentsFile.dat", ios::in);
		filename = "c:\\studentsFile.dat";
		break;
	case'2':
		cout << "�������Զ����ļ�����\n";
		cin >> filename;
		cout << endl;
		fdat.open(filename, ios::in);
		break;
	default:
		cout << "���˳���\n";
		return;
	}
	if (fdat)
	{
		cout << "�ļ��Ѵ��ڣ��½�ͬ���ļ�������ԭ���ļ������ݣ��Ƿ���Ҫ�½��ļ���Y/N\n";
		cin >> choice;
		if (choice != 'Y' && choice != 'y')
		{
			cout << "�����ļ�ʧ�ܣ����˳���\n";
			return;
		}
	}
	fdat.close();
	fdat.open(filename, ios::out | ios::binary);
	fdat.seekp(0, ios::beg);
	fdat.write((char*)&mark, sizeof(studentData));
	fdat.close();
	cout << "�����ɹ���\n";
}