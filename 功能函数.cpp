//Function.cpp
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct studentData
{
	int ID;
	string name;
	double score[4] = { 0 };//0-3代表math、English、C++和总成绩
	int rank[4] = { 0 };
};
const studentData mark = { 0,"!\0", {-1,-1,-1,-1}, {-1,-1,-1,-1} };
const string temfile = "c:\\tem_file.dat";
int endMark(studentData student)
{
	if (student.score[0] == -1)return 1;
	return 0;
}
void Copy(string filename)
{
	studentData student;
	fstream fdat;
	fstream fdat_tem;
	fdat_tem.open(temfile, ios::in | ios::binary);
	fdat.open(filename, ios::out | ios::binary);
	fdat_tem.seekg(0, ios::beg);
	fdat.seekp(0, ios::beg);
	do
	{
		fdat_tem.read((char*)&student, sizeof(studentData));
		fdat.write((char*)&student, sizeof(studentData));
	} while (!endMark(student));
	fdat_tem.close();
	fdat.close();
}
void storeDat(string filename)
{
	//文件合二为一
	studentData tem_stu1;
	studentData tem_stu2;
	fstream fdat(filename, ios::in | ios::out | ios::binary);
	fstream fdat_tem(temfile, ios::in | ios::binary);
	fdat.seekg(0, ios::beg);
	fdat_tem.seekp(0, ios::beg);
	do
	{
		fdat.read((char*)&tem_stu1, sizeof(studentData));
	} while (!endMark(tem_stu1));
	fdat.seekp(-long(sizeof(studentData)), ios::cur);
	do
	{
		fdat_tem.read((char*)&tem_stu1, sizeof(studentData));
		fdat.write((char*)&tem_stu1, sizeof(studentData));
	} while (!endMark(tem_stu1));
	fdat.close();
	fdat_tem.close();
	//更新排名
	renewRank(filename);
	cout << "保存成功！\n";
}
void outputstudent(studentData student)
{
	cout << "学号\t" << "姓名\t"
		<< "数学\t" << "英语\t" << "OPP\t" << "总分\t"
		<< "数排\t" << "英排\t" << "OPP\t" << "总排\n"
		<< student.ID << '\t' << student.name << '\t'
		<< student.score[0] << '\t' << student.score[1] << '\t' << student.score[2] << '\t' << student.score[3] << '\t'
		<< student.rank[0] << '\t' << student.rank[1] << '\t' << student.rank[2] << '\t' << student.rank[3] << '\n';
}
void renewRank(string filename)
{
	studentData tem_stu1;
	studentData tem_stu2;
	fstream fdat;
	fstream fdat_tem;
	fdat.open(filename, ios::in | ios::binary);
	fdat_tem.open(temfile, ios::out | ios::binary);
	fdat.seekg(0, ios::beg);
	fdat_tem.seekp(0, ios::beg);
	//写原文件记录新排名
	int count[4] = { 1,1,1,1 };
	for (int i = 1; ; i++)
	{
		for (int j = 0; j < 4; j++)count[j] = 1;
		for (int j = 0; j < i; j++)
		{
			fdat.read((char*)&tem_stu1, sizeof(studentData));
		}
		if (endMark(tem_stu1))break;
		tem_stu2 = tem_stu1;
		fdat.seekg(0, ios::beg);
		fdat.read((char*)&tem_stu1, sizeof(studentData));
		for (; !endMark(tem_stu1);)
		{
			for (int subject = 0; subject < 4; subject++)
			{
				if (tem_stu2.score[subject] < tem_stu1.score[subject])count[subject]++;
			}
			fdat.read((char*)&tem_stu1, sizeof(studentData));
		}
		for (int subject = 0; subject < 4; subject++)
		{
			tem_stu2.rank[subject] = count[subject];
		}
		fdat.seekg(0, ios::beg);
		fdat_tem.write((char*)&tem_stu2, sizeof(studentData));
	}
	fdat_tem.write((char*)&mark, sizeof(studentData));
	fdat_tem.close();
	fdat.close();
	//将文件复制回去
	Copy(filename);
}