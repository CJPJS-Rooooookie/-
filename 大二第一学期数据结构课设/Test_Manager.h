#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define Status int
#define OK 1
#define ERROR 0
#define Maxsize 1000		//设置顺序表中的最大考生数为1000人

typedef struct 
{
	string name, gender, ID, number, subject;		//姓名、性别、身份证号、考号、考试科目
	int age;										//年龄
}Test_Stu;			/* 考生类的定义 */

typedef struct {
	Test_Stu* elem;
	int length;				//顺序表当前长度
}SqList;

Status InitList(SqList&);							//顺序表初始化
bool EmptyList(SqList&);							//判断顺序表是否为空
istream& operator>>(istream& cin, Test_Stu& L);		//重载流插入运算符
ostream& operator<<(ostream& cout, Test_Stu& L);	//重载流提取运算符
Status InsertList(SqList& L);						//往顺序表中插入成员

void InsertList(SqList& L, Test_Stu);				//用于往其中插入示例信息
Status Verify(SqList& L);							//验证考生是否报名

Status Search_number(SqList& L);					//根据身份证号查找
Status Sort_age(SqList& L);							//根据年龄排序
Status Delete(SqList& L);							//删除成员
Status Edit(SqList& L);								//编辑成员信息
Status SaveFile(SqList& L);							//将所有信息保存到文件中
void ReadFile(SqList& L);							//从文件中读取信息
//void Statistic(SqList& L);						//统计各科报名人数
Status Display(SqList& L);							//输出全部信息
void MainMenu(SqList& L);							//显示主界面的菜单
void ManagerMenu(SqList& L);						//适合管理者操作的第二级菜单