#include "Test_Manager.h"

Status InitList(SqList& L)						/* 顺序表初始化 */
{
	L.elem = new Test_Stu[Maxsize + 1];	/* 给顺序表分配大小为MaxSize+1
										   的空间,下标为0的元素作为哨兵 */
	L.length = 0;						//初始化时顺序表当前长度为0
	return OK;
}

bool EmptyList(SqList& L)							/* 判断顺序表是否为空 */
{
	if (L.length == 0)
		return true;					//若为空则返回true
	return false;
}

istream& operator>>(istream& cin, Test_Stu& stu)
{
	cout << "姓名：";			cin >> stu.name;
	cout << "性别：";			cin >> stu.gender;
	cout << "年龄：";			cin >> stu.age;
	cout << "身份证号：";		cin >> stu.ID;
	cout << "考试科目：";		cin >> stu.subject;
	return cin;
}

ostream& operator<<(ostream& cout, Test_Stu& stu)
{
	cout << "\t————————————————————————————————————————————————————\n";
	cout << "\t" << stu.number << "\t\t" << stu.name << "\t\t" << stu.gender << "\t\t"
		<< stu.age << "\t\t" << stu.ID << "\t\t" << stu.subject << "\n";
	return cout;
}

Status InsertList(SqList& L)					      	/* 考生报名，自动为考生生成考号 */
{
	if (L.length == Maxsize + 1)
	{
		cout << "\t报名人数已满！";
		return ERROR;
	}
	cout << "\t请输入考生信息：" << endl;
	Test_Stu stu;		cin >> stu;
	string str;
	str = std::to_string((long double)L.length + 1);		//to_string()函数将long double型转化为字符串
	stu.number = "19120" + str;
	L.elem[L.length + 1] = stu;
	L.length++;
	cout << "\t报名成功！"<<endl;
	cout << "您的考号为“" << L.elem[L.length].number << "”，请牢记您的考号！"<<endl;
	return OK;
}

void InsertList(SqList& L, Test_Stu stu)
{
	L.elem[L.length + 1] = stu;
	L.length++;
}

Status Search_number(SqList& L)							/* 根据身份证号查找 */
{
	cout << "请输入要查找考生的考生号：";
	string key;		cin >> key;			//输入身份证号
	L.elem[0].number = key;				//把要查找元素的值赋给哨兵
	int num;
	for (num = L.length; L.elem[num].number != key; num--);
										//从后往前依次寻找
	if (num == 0)
	{
		cout << "\t————————————————————————————————————————————————————\n";
		cout << "\t" << "考号\t\t姓名\t\t性别\t\t年龄\t\t身份证号\t\t\t考试科目\n";
		cout << "\t————————————————————————————————————————————————————\n";
		cout << "\t很抱歉，未找到该考生信息！" << endl;
		return ERROR;
	}
	else {
		cout << "\t您要查找的考生生信息如下：" << endl;
		cout << "\t————————————————————————————————————————————————————\n";
		cout << "\t" << "考号\t\t姓名\t\t性别\t\t年龄\t\t身份证号\t\t\t考试科目\n";
		cout << L.elem[num];
		cout << "\t————————————————————————————————————————————————————\n";
	}
	return OK;
}

Status Verify(SqList& L)							/* 验证考生是否报名 */
{
	cout << "请输入考生姓名：";
	string key;		cin >> key;			//输入姓名
	L.elem[0].name = key;				//把要查找元素的值赋给哨兵
	int num;
	for (num = L.length; L.elem[num].name != key; num--);
										//从后往前依次寻找
	if (num == 0)
		cout << "\t很抱歉，未找到您的信息！" << endl;
	else
		cout << "\t您已报名！" << endl;
	return OK;
}

Status Sort_age(SqList& L)								/* 根据年龄排序 */
{
	Test_Stu Stu[Maxsize];	int j;
	for (int i = 0; i <= L.length; i++)
		Stu[i] = L.elem[i];
	for (int i = 2; i <= L.length; i++)
		if (Stu[i].age < Stu[i - 1].age)
		{
			Stu[0] = Stu[i];
			Stu[i] = Stu[i - 1];
			for (j = i - 2; Stu[0].age < Stu[j].age; j--)
				Stu[j + 1] = Stu[j];
			Stu[j + 1] = Stu[0];
		}
	cout << "\t————————————————————————————————————————————————————\n";
	cout << "\t" << "考号\t\t姓名\t\t性别\t\t年龄\t\t身份证号\t\t\t考试科目\n";
	for (int i = 1; i <= L.length; i++)						//输出排好序的元素
		cout << Stu[i];
	cout << "\t————————————————————————————————————————————————————\n";
	return OK;
}

Status Delete(SqList& L)									/* 删除指定信息 */
{
	if(EmptyList(L) == true)	
	{		cout << "\t暂无数据，无法删除！" << endl;		return ERROR;		}
	cout << "请输入要删除的人员考生号：";
	string key;		cin >> key;
	L.elem[0].number = key;				//把要查找元素的值赋给哨兵
	int num;
	for (num = L.length; L.elem[num].number != key; num--);
											//从后往前依次寻找
	if (num == 0)
		cout << "\t未找到该考生信息！请检查您是否输入正确"<<endl;
	else {
		cout << "\t·————————————————————————————·" << endl;
		cout << "\t┃          该人员信息如下，是否要确认删除该人员信息？     ┃" << endl;
		cout << "\t┃                   确认请按Y，取消请按N                  ┃" << endl;
		cout << "\t┃                                                         ┃" << endl;
		cout << "\t┃          ┍       ┑                    ┍       ┑         ┃" << endl;
		cout << "\t┃            是（Y）                      否（N）         ┃" << endl;
		cout << "\t┃          ┕       ┙                    ┕       ┙         ┃ " << endl;
		cout << "\t·————————————————————————————·" << endl;
		cout << "\t————————————————————————————————————————————————————\n";
		cout << "\t" << "考号\t\t姓名\t\t性别\t\t年龄\t\t身份证号\t\t\t考试科目\n";
		cout << L.elem[num];
		cout << "\t————————————————————————————————————————————————————\n";
		char ch;	cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')			//判断用户输入是否合法
		{
			cout << "您的输入有误，请重新输入！";
			cin >> ch;
		}
		switch (ch)
		{
		case'y':
		case'Y':
			for (int i = num; i < L.length + 1; i++)
				L.elem[i] = L.elem[i + 1];
			L.length--;							//删除完成后长度减1
			cout << "\t删除成功！" << endl;
			break;
		case'n':
		case'N':cout << "\t已退出！" << endl;	break;
		}
	}
	return OK;
}

Status Edit(SqList& L)											/* 编辑指定信息 */
{
	if (EmptyList(L) == true)
	{
		cout << "暂无数据，无法删除！" << endl;		return ERROR;
	}
	cout << "请输入要编辑的人员考生号：";
	string key;		cin >> key;
	L.elem[0].number = key;				//把要查找元素的值赋给哨兵
	int num;
	for (num = L.length; L.elem[num].number != key; num--);
										//从后往前依次寻找
	if (num == 0)
		cout << "未找到该考生信息！请检查您是否输入正确"<<endl;
	else {
		cout << "\t·————————————————————————————·" << endl;
		cout << "\t┃          该人员信息如下，是否要确认修改该人员信息？     ┃" << endl;
		cout << "\t┃                   确认请按Y，取消请按N                  ┃" << endl;
		cout << "\t┃                                                         ┃" << endl;
		cout << "\t┃          ┍       ┑                    ┍       ┑         ┃" << endl;
		cout << "\t┃            是（Y）                      否（N）         ┃" << endl;
		cout << "\t┃          ┕       ┙                    ┕       ┙         ┃ " << endl;
		cout << "\t·————————————————————————————·" << endl;
		cout << "\t————————————————————————————————————————————————————\n";
		cout << "\t" << "考号\t\t姓名\t\t性别\t\t年龄\t\t身份证号\t\t\t考试科目\n";
		cout << L.elem[num];
		cout << "\t————————————————————————————————————————————————————\n";
		char ch;	cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')			//判断用户输入是否合法
		{
			cout << "您的输入有误，请重新输入！";
			cin >> ch;
		}
		switch (ch)
		{
		case'y':
		case'Y':
			cin >> L.elem[num];
			cout << "\t编辑成功！" << endl;
			break;
		case'n':
		case'N':cout << "\t已退出！" << endl;	break;
		}
	}
	return OK;
}

Status SaveFile(SqList& L)
{
	if (EmptyList(L) == true)
	{		cout << "您还未添加数据，无法保存到文件！"<<endl;		return ERROR;		}
	ofstream outfile;							//建立ofstream类的对象outfile
	outfile.open("Manager.txt", ios::app);		//与文件Manager.txt建立关联
	for (int i = 1; i < L.length+1; i++)				//向文件内写入数据
		outfile << "\n" << L.elem[i].number << "\t\t" << L.elem[i].name << "\t\t" << L.elem[i].gender << "\t\t" << L.elem[i].age << "\t\t"
		<< L.elem[i].ID << "\t\t" << L.elem[i].subject << "\n";
	outfile.close();							//取消与文件的关联
	cout << "\t信息保存成功！" << endl;;
	return OK;
}

void ReadFile(SqList& L)
{
	ifstream infile;							//建立对象
	infile.open("Manager.txt",ios::in);			//与文件Manager.txt建立关联
	for(;;)
	{
		string number,name,gender,age,ID,subject;
		infile>>number>>name>>gender>>age>>ID>>subject;		//读取文件中的信息
		if(number=="\0"&&name=="\0"&&gender=="\0"&&age=="\0"&&ID=="\0"&&subject=="\0") break;
															//用于判断读取的信息是否为空，若信息为空，则结束循环
		else{
			cout << "\t————————————————————————————————————————————————————\n";
			cout << "\t" << number << "\t\t" << name << "\t\t" << gender << "\t\t"
					<< age << "\t\t" << ID << "\t\t" << subject << "\n";
		}
	}
	cout << "\t————————————————————————————————————————————————————\n";
}

Status Display(SqList& L)										/* 输出全部信息 */
{
	if (L.length == 0)
	{
		cout << "暂无信息！" << endl;		return ERROR;
	}
	cout << "\t————————————————————————————————————————————————————\n";
	cout << "\t" << "考号\t\t姓名\t\t性别\t\t年龄\t\t身份证号\t\t\t考试科目\n";
	for (int i = 1; i <= L.length; i++)
		cout << L.elem[i];
	cout << "\t————————————————————————————————————————————————————\n";
	return OK;
}

void MainMenu(SqList& L)											/* 实现主界面菜单的现实及相应操作 */
{
		cout << "\t·* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *·" << endl;
		cout << "\t*                     ┏                   ┓                   *" << endl;
		cout << "\t*                       简陋的考生报名系统                    *" << endl;
		cout << "\t*                     ┗                   ┛                   *" << endl;
		cout << "\t*                        1.开始报名                           *" << endl;
		cout << "\t*                        2.查询是否报名                       *" << endl;
		cout << "\t*                        3.管理已报名信息                     *" << endl;
		cout << "\t*                        0.关闭窗口                           *" << endl;
		cout << "\t*                                                             *" << endl;
		cout << "\t*      请选择进行的操作（0到3）：                             *" << endl;
		cout << "\t*                                                             *" << endl;
		cout << "\t·* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *·" << endl;
		int choose;		cin >> choose;
		while (choose < 0 || choose > 3)	//判断用户输入是否合法
		{
			cout << "您的输入有误，请重新输入！";
			cin >> choose;
		}
		switch (choose)
		{
		case 1:InsertList(L);	break;									//报名
		case 2:Verify(L);		break;
		case 3:ManagerMenu(L);	break;		//访问子菜单
		case 0:cout << "\t感谢您的使用^-^" << endl;		exit(0);
		}
		system("pause");
		system("cls");	
}

void ManagerMenu(SqList& L)											/* 管理者菜单 */
{
	string password;
	cout << "\t请输入管理密码：";			cin >> password;
	if (password == "pass")
	{
		cout << "\t密码正确！" << endl;
		system("pause");		system("cls");
		while (1)
		{
			cout << "\t·… … … … … … … … … … … … … … … … … … … …·" << endl;
			cout << "\t：                     ┏                   ┓                  ：" << endl;
			cout << "\t：                           管理菜单                         ：" << endl;
			cout << "\t：                     ┗                   ┛                  ：" << endl;
			cout << "\t：                                                            ：" << endl;
			cout << "\t：                     1.查看已报名考生信息                   ：" << endl;
			cout << "\t：                     2.删除指定人员信息                     ：" << endl;
			cout << "\t：                     3.根据考号查找人员信息                 ：" << endl;
			cout << "\t：                     4.编辑指定人员信息                     ：" << endl;
			cout << "\t：                     5.保存人员信息到文件                   ：" << endl;
			cout << "\t：                     6.读取文件内的信息                     ：" << endl;
			cout << "\t：                     7.按年龄排序查看所有人员信息           ：" << endl;
			//cout << "\t：                     8.统计各科报名人数                     ：" << endl;
			cout << "\t：                     0.返回上级菜单                         ：" << endl;
			cout << "\t：      请选择进行的操作（0到7）：                            ：" << endl;
			cout << "\t：                                                            ：" << endl;
			cout << "\t·… … … … … … … … … … … … … … … … … … … …·" << endl;
			int choose;		cin >> choose;
			string password;
			while (choose < 0 || choose > 7)	//判断用户输入是否合法
			{
				cout << "您的输入有误，请重新输入！";
				cin >> choose;
			}
			switch (choose)
			{
			case 1:Display(L);		break;
			case 2:Delete(L);		break;
			case 3:Search_number(L);	break;
			case 4:Edit(L);			break;
			case 5:SaveFile(L);		break;
			case 6:ReadFile(L);		break;
			case 7:Sort_age(L);		break;
				//case 8:Statistic(L);	break;
			case 0:break;
			}
			if (choose == 0)	break;			//返回上一级菜单
			system("pause");
			system("cls");
		}
	}
	else
		cout << "\t密码错误，拒绝您的访问！" << endl;
}
