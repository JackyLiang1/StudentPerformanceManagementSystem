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
int endMark(studentData student);
void showMenu();
void CreateDat();
void CreateTxt();
void Append();
void Rank();
void Search();
void Delete();
void Revise();
void Copy(string filename);
void outputstudent(studentData student);
void renewRank(string filename);
void storeDat(string filename);

