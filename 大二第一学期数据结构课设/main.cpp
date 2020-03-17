#include "Test_Manager.h"

void main()
{
	SqList L;	InitList(L);
	Test_Stu stu_1, stu_2;
	stu_1.age = 33;			stu_1.gender = "男";		stu_1.ID = "123456789987654321";
	stu_1.name = "夏洛";	stu_1.subject = "数学";		stu_1.number = "191201";
	stu_2.age = 29;			stu_2.gender = "女";		stu_2.ID = "987654321123456789";
	stu_2.name = "马冬梅";	stu_2.subject = "语文";		stu_2.number = "191202";
	InsertList(L, stu_1);			InsertList(L, stu_2);		//往其中添加的示例信息
	while(1)
		MainMenu(L); 
}