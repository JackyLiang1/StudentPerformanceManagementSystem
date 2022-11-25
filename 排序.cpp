//Rank.cpp
#include"功能函数.h"
void Rank()
{
	studentData student1;
	studentData student2;
	studentData tem1;
	char item;
	int subject;
	char choice;
	string ID;
	string name;
	int rank[4] = { 0 };
	string filename;
	cout << "请输入进行排序操作的文件名类型。1、默认文件“c:\\studentsFile.dat” 2、自命名 Q/q:退出\n";
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
	cout << "请选择排序的项目。1、学号 2、姓名 3、名次 Q/q:退出\n";
	cin >> item;
	switch (item)
	{
	case'1':
		cout << "1、升序 2、降序 Q/q:退出。\n";
		cin >> choice;
		if (choice == '1')
		{
			fstream fdat(filename, ios::in | ios::out | ios::binary);
			fdat.seekg(0, ios::beg);
			fdat.read((char*)&student1, sizeof(studentData));
			for (int locate1 = 0; !endMark(student1); locate1++)
			{
				tem1 = student1;
				int p = 0;
				int locate2 = 0;
				fdat.read((char*)&student2, sizeof(studentData));
				for (; !endMark(student2); p++)
				{
					if (tem1.ID > student2.ID)
					{
						locate2 = p + 1;
						tem1 = student2;
					}
					fdat.read((char*)&student2, sizeof(studentData));
				}
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&tem1, sizeof(studentData));
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1 + locate2; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&student1, sizeof(studentData));
				fdat.seekg(0, ios::beg);
				for (int k = 0; k < locate1 + 1; k++)
				{
					fdat.seekg(long(sizeof(studentData)), ios::cur);
				}
				fdat.read((char*)&student1, sizeof(studentData));
			}
			fdat.close();
			cout << "排序成功！\n";
		}
		else if (choice == '2')
		{
			fstream fdat(filename, ios::in | ios::out | ios::binary);
			fdat.seekg(0, ios::beg);
			fdat.read((char*)&student1, sizeof(studentData));
			for (int locate1 = 0; !endMark(student1); locate1++)
			{
				tem1 = student1;
				int p = 0;
				int locate2 = 0;
				fdat.read((char*)&student2, sizeof(studentData));
				for (; !endMark(student2); p++)
				{
					if (tem1.ID < student2.ID)
					{
						locate2 = p + 1;
						tem1 = student2;
					}
					fdat.read((char*)&student2, sizeof(studentData));
				}
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&tem1, sizeof(studentData));
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1 + locate2; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&student1, sizeof(studentData));
				fdat.seekg(0, ios::beg);
				for (int k = 0; k < locate1 + 1; k++)
				{
					fdat.seekg(long(sizeof(studentData)), ios::cur);
				}
				fdat.read((char*)&student1, sizeof(studentData));
			}
			fdat.close();
			cout << "排序成功！\n";
		}
		else
		{
			cout << "已退出。\n";
			return;
		}
		break;
	case'2':
		cout << "1、升序 2、降序 Q/q:退出。\n";
		cin >> choice;
		if (choice == '1')
		{
			fstream fdat(filename, ios::in | ios::out | ios::binary);
			fdat.seekg(0, ios::beg);
			fdat.read((char*)&student1, sizeof(studentData));
			for (int locate1 = 0; !endMark(student1); locate1++)
			{
				tem1 = student1;
				int p = 0;
				int locate2 = 0;
				fdat.read((char*)&student2, sizeof(studentData));
				for (; !endMark(student2); p++)
				{
					if (tem1.name > student2.name)
					{
						locate2 = p + 1;
						tem1 = student2;
					}
					fdat.read((char*)&student2, sizeof(studentData));
				}
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&tem1, sizeof(studentData));

				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1 + locate2; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&student1, sizeof(studentData));
				fdat.seekg(0, ios::beg);
				for (int k = 0; k < locate1 + 1; k++)
				{
					fdat.seekg(long(sizeof(studentData)), ios::cur);
				}
				fdat.read((char*)&student1, sizeof(studentData));
			}
			fdat.close();
			cout << "排序成功！\n";
		}
		else if (choice == '2')
		{
			fstream fdat(filename, ios::in | ios::out | ios::binary);
			fdat.seekg(0, ios::beg);
			fdat.read((char*)&student1, sizeof(studentData));
			for (int locate1 = 0; !endMark(student1); locate1++)
			{
				tem1 = student1;
				int p = 0;
				int locate2 = 0;
				fdat.read((char*)&student2, sizeof(studentData));
				for (; !endMark(student2); p++)
				{
					if (tem1.name < student2.name)
					{
						locate2 = p + 1;
						tem1 = student2;
					}
					fdat.read((char*)&student2, sizeof(studentData));
				}
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&tem1, sizeof(studentData));

				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1 + locate2; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&student1, sizeof(studentData));
				fdat.seekg(0, ios::beg);
				for (int k = 0; k < locate1 + 1; k++)
				{
					fdat.seekg(long(sizeof(studentData)), ios::cur);
				}
				fdat.read((char*)&student1, sizeof(studentData));
			}
			fdat.close();
			cout << "排序成功！\n";
		}
		else
		{
			cout << "已退出。\n";
			return;
		}
		break;
	case'3':
		cout << "请选择排序的科目名次。1、数学 2、英语 3、OPP 4、总名次 Q/q:退出\n";
		cin >> subject;
		if (subject < 1 || subject> 4)
		{
			cout << "输入有误，已退出。\n";
			return;
		}
		subject--;
		cout << "1、升序 2、降序 Q/q:退出。\n";
		cin >> choice;
		if (choice == '1')
		{
			fstream fdat(filename, ios::in | ios::out | ios::binary);
			fdat.seekg(0, ios::beg);
			fdat.read((char*)&student1, sizeof(studentData));
			for (int locate1 = 0; !endMark(student1); locate1++)
			{
				tem1 = student1;
				int p = 0;
				int locate2 = 0;
				fdat.read((char*)&student2, sizeof(studentData));
				for (; !endMark(student2); p++)
				{
					if (tem1.rank[subject] > student2.rank[subject])
					{
						locate2 = p + 1;
						tem1 = student2;
					}
					fdat.read((char*)&student2, sizeof(studentData));
				}
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&tem1, sizeof(studentData));
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1 + locate2; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&student1, sizeof(studentData));

				fdat.seekg(0, ios::beg);
				for (int k = 0; k < locate1 + 1; k++)
				{
					fdat.seekg(long(sizeof(studentData)), ios::cur);
				}
				fdat.read((char*)&student1, sizeof(studentData));
			}
			fdat.close();
			cout << "排序成功！\n";
		}
		else if (choice == '2')
		{
			fstream fdat(filename, ios::in | ios::out | ios::binary);
			fdat.seekg(0, ios::beg);
			fdat.read((char*)&student1, sizeof(studentData));
			for (int locate1 = 0; !endMark(student1); locate1++)
			{
				tem1 = student1;
				int p = 0;
				int locate2 = 0;
				fdat.read((char*)&student2, sizeof(studentData));
				for (; !endMark(student2); p++)
				{
					if (tem1.rank[subject] < student2.rank[subject])
					{
						locate2 = p + 1;
						tem1 = student2;
					}
					fdat.read((char*)&student2, sizeof(studentData));
				}
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&tem1, sizeof(studentData));
				fdat.seekp(0, ios::beg);
				for (int k = 0; k < locate1 + locate2; k++)
				{
					fdat.seekp(long(sizeof(studentData)), ios::cur);
				}
				fdat.write((char*)&student1, sizeof(studentData));
				fdat.seekg(0, ios::beg);
				for (int k = 0; k < locate1 + 1; k++)
				{
					fdat.seekg(long(sizeof(studentData)), ios::cur);
				}
				fdat.read((char*)&student1, sizeof(studentData));
			}
			fdat.close();
			cout << "排序成功！\n";
		}
		else
		{
			cout << "已退出。\n";
			return;
		}
		break;
	default:
		cout << "输入有误，已退出。\n";
		return;
	}
}