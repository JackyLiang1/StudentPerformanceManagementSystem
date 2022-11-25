#include"学生成绩管理系统.h"
#include"功能函数.h"
int main()
{
	char choice;
	while (1)
	{
		showMenu();
		cout << "请输入操作对应的序号:\n";
		cin >> choice;
		switch (choice)
		{
		case '0':  CreateDat(); break;
		case '1':  CreateTxt(); break;
		case '2':  Append(); break;
		case '3':  Search(); break;
		case '4':  Delete(); break;
		case '5':  Revise(); break;
		case '6':  Rank(); break;
		case'Q':
		case'q':cout << "退出成功！\n"; return 0;
		default:cout << "输入序号有误！请输入正确的序号。\n";
		}
	}
	return 0;
}












