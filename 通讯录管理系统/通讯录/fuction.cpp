#define  _CRT_SECURE_NO_WARNINGS
/*
 *
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"header.h"


struct ContactRecord							// 定义一个名为record的结构体类型，用来存储学生的信息
{
	char name[20];						// 姓名，最多20个字符
	char phone[12];						// 电话，最多12个字符
	char adress[50];					// 地址，最多50个字符
	char postcode[8];					// 邮编，最多8个字符
	char e_mail[20];			// 电子邮箱，最多20个字符
}student[100];							// 定义一个结构体数组，用来存储多个学生的信息，数组大小为100，即最多存储100个学生的信息


/*
函数名:showDeleteRecordInterface
功能:显示删除界面
完成者:老胡

*/
void showDeleteRecordInterface(struct ContactRecord contacts[], int num_contacts) {

	system("cls");
	printf("\t\t************* 请输入查找方式 ***********\n\n");
	printf("\t\t\t1.姓名查找\n");
	printf("\t\t\t2.电话查找\n");
	printf("\t\t\t3.地址查找\n");
	printf("\t\t\t4.邮编查找\n");
	printf("\t\t\t5.邮箱查找\n");
	printf("\t\t\t6.模糊查找\n");
	printf("\t\t\t7.分组查找\n");
	printf("\t\t\t8.退出\n");
	char s[80];
	int a;
	do {
		printf("Enter you choice(0~8):");
		scanf("%s", s);												// 获取用户输入的字符串，并存储到字符数组s中
		a = atoi(s);
		if (a == 8) return;
	} while (a<1||a>8);
	system("cls");
	printf("\t\t输入删除联系人信息:\n\n");
	char key[80];
	scanf("%s", &key);
	int res=deleteContact(contacts, num_contacts, key, a);
	if (res == 0) {
		printf("\t\t删除成功\n");
		num_contacts--;
	}
	else printf("\t\t删除失败\n");
	char op ;
	printf("\t\t是否继续删除?\n");
	printf("\t\t\ty/n?\n");
	scanf("%c", &op);
	if (op == 'y' || op == 'Y') showDeleteRecordInterface(contacts, num_contacts);
	else return;
}

/*
函数名:showSearchInterface
功能:显示查找界面
完成者:老胡

*/
void showSearchInterface(struct ContactRecord contacts[], int num_contacts) {
	system("cls");
	printf("\t\t************* 请输入查找方式 ***********\n\n");
	printf("\t\t\t1.姓名查找\n");
	printf("\t\t\t2.电话查找\n");
	printf("\t\t\t3.地址查找\n");
	printf("\t\t\t4.邮编查找\n");
	printf("\t\t\t5.邮箱查找\n");
	printf("\t\t\t6.模糊查找\n");
	printf("\t\t\t7.分组查找\n");
	printf("\t\t\t8.退出\n");
	char s[80];
	int a;
	do {
		printf("Enter you choice(0~8):");
		scanf("%s", s);												// 获取用户输入的字符串，并存储到字符数组s中
		a = atoi(s);
	} while (a < 1 || a>8);
	system("cls");
	char key[80];
	printf("\t\t输入查找联系人信息:\n");
	scanf("%s", &key);
	int res = -1;
	switch (a) {
	case 1:
		res = searchContactByName(contacts, num_contacts, key);
	case 2:
		res = searchContactByPhone(contacts, num_contacts, key);
	case 3:
		res = searchContactByAddress(contacts, num_contacts, key);
	case 4:
		res = searchContactByPostcode(contacts, num_contacts, key);
	case 5:
		res = searchContactByEmail(contacts, num_contacts, key);
	case 6:
		res = fuzzySearchContacts(contacts, num_contacts, key);
	case 7:
		res = searchContactsByGroup(contacts, num_contacts, key);
	case 8:
		return;

	}
	if (res == 0) printf("\t\t查找成功\n");
	else printf("\t\t查找失败\n");
	printf("\t\t是否继续进行查找?\ny/n\n");
	char op;
	scanf("%c", &op);
	if (op == 'y' || op == 'Y') showSearchInterface(contacts, num_contacts);
	else return;
}


void encrypt(char* pwd)					//这是一个名为encrypt的函数，用于对传入的字符串进行简单的加密处理
{
	int pwdlen = strlen(pwd);			// 获取字符串的长度，用于循环处理每个字符。
	for (int i = 0; i < pwdlen; i++)	//遍历字符串中的每个字符。
	{
		pwd[i] ^= 15;					// 对于每个字符，使用异或运算对其进行加密处理
	}
}


int  get_record_count()					// 直接返回0，表示当前通讯录中没有任何记录
{
	return 0;
}

int num = 0;															// 声明一个名为num的整型变量


int menu_select()													// 定义一个名为menu_select的函数，用来显示菜单并获取操作选项
{
	char s[80];														// 定义一个字符数组s，用来存储用户输入的字符串
	int a;															// 定义一个整型变量a，用来存储用户输入的数字选项
	system("cls");													// 清屏，清除控制台中之前的内容
	printf("\t\t***********欢迎进入通讯管理界面********\n\n");
	printf("\t\t\t0. 输入记录\n");
	printf("\t\t\t1. 显示记录\n");
	printf("\t\t\t2. 按姓名查找\n");
	printf("\t\t\t3. 按电话号码查找\n");
	printf("\t\t\t4. 插入记录 \n");
	printf("\t\t\t5. 按姓名排序\n");
	printf("\t\t\t6. 删除记录\n");
	printf("\t\t\t7. 保存并退出\n");
	printf("\t\t***********************************************\n\n");
	do {															// 使用do-while循环，确保用户输入的数字选项在0~7之间
		printf("Enter you choice(0~7):");
		scanf("%s", s);												// 获取用户输入的字符串，并存储到字符数组s中
		a = atoi(s);										// 将字符数组s中的字符串转换成整型数值，并存储到变量a中
	} while (a < 0 || a>7);											// 当用户输入的数字选项不在0~7之间，就继续提示用户输入
	return a;														// 返回用户输入的数字选项
}


int addContacts()														// 定义一个名为adduser的函数，用来添加学生信息
{
	printf("\n\t\t\t**************** 请输入用户信息 ****************\n");
	printf("\t\t\t输入姓名:");
	scanf("%s", student[num].name);									// 获取用户输入的姓名，并存储到结构体数组中
	printf("\n\t\t\t输入电话号码:");
	scanf("%s", student[num].phone);								// 获取用户输入的电话号码，并存储到结构体数组中
	printf("\n\t\t\t输入地址:");
	scanf("%s", student[num].adress);								// 获取用户输入的地址，并存储到结构体数组中
	printf("\n\t\t\t输入邮编:");
	scanf("%s", student[num].postcode);								//获取用户输入的邮编，并存储到结构体数组中
	printf("\n\t\t\t输入e-mail:");
	scanf("%s", student[num].e_mail);								// 获取用户输入的电子邮件地址，并存储到结构体数组中
	num++;															// 学生信息数量加1
	printf("\n\t\t\t是否继续添加?(Y/N):");							// 提示用户是否继续添加
	if (_getch() == 'y' || _getch() == 'Y')							// 如果用户输入的是’y’或’Y’，则递归调用adduser函数添加学生信息
		addContacts();
	return(0);														// 返回0,结束函数
}


void listContacts()											// 定义一个名为list的函数，用来显示所有学生信息
{
	int i;
	system("cls");									// 清屏，清除控制台中之前的内容
	if (num != 0)									// 如果有学生信息，则显示所有学生信息
	{
		printf("\t\t\t*************** 以下为通讯录所有信息************\n");
		for (i = 0; i < num; i++)					// 遍历所有学生信息，并逐一显示
		{
			printf("\t\t\t姓名:%s\n", student[i].name);
			printf("\t\t\t电话:%s\n", student[i].phone);
			printf("\t\t\t地址:%s\n", student[i].adress);
			printf("\t\t\t邮编:%s\n", student[i].postcode);
			printf("\t\t\tEmail:%s\n", student[i].e_mail);
			if (i + 1 < num)						// 如果不是最后一个学生信息，提示用户按任意键继续
			{
				system("pause");					// 将控制台暂停，等待用户按任意键继续
			}
		}
		printf("\t\t\t************************************************\n");
	}
	else											// 如果没有学生信息，则提示用户
		printf("\t\t\t通讯录中无任何纪录\n");
	printf("\t\t\t按任意键返回主菜单:\n");
	_getch();										// 等待用户按任意键
	return;											// 返回，结束函数
}


int searchContactByName()											// 定义一个名为searchbyname的函数，用来按姓名查找学生信息
{
	int mark = 0;											// 定义一个整型变量mark，用来标记是否查找到了符合条件的学生信息
	int i;													// 定义一个整型变量i，用来遍历所有学生信息
	printf("\t\t\t***************** 按姓名查找 *******************\n");
	char name[20];											// 定义一个字符数组name，用来存储用户输入的姓名
	printf("\t\t\t请输入姓名:");
	scanf("%s", name);										// 获取用户输入的姓名
	for (i = 0; i < num; i++)								// 遍历所有学生信息，查找符合条件的学生信息
	{
		if (strcmp(student[i].name, name) == 0)				// 如果找到了符合条件的学生信息，则输出信息并增加mark的值
		{
			printf("\t\t\t************* 以下是您查找的用户信息 ***********\n");
			printf("\t\t\t姓名: %s\n", student[i].name);
			printf("\t\t\t电话: %s\n", student[i].phone);
			printf("\t\t\t地址: %s\n", student[i].adress);
			printf("\t\t\te-mail:%s\n", student[i].e_mail);
			printf("\t\t\t************************************************\n");
			mark++;											//学生信息+1
			if ((i + 1) < num)								// 如果找到的学生信息不是最后一条，则询问用户是否继续查找
			{
				printf("\t\t\t是否继续查找相同名字的用户信息:(y/n)");
				if (_getch() == 'y' || _getch() == 'Y')
				{
					continue;								// 如果用户继续查找，则继续循环查找
				}
				else
					return(0);								// 如果用户不继续查找，则返回0，结束函数
			}
			else											// 如果找到的是最后一条学生信息，则提示用户按任意键返回主菜单
			{
				printf("\t\t\t按任意键返回主菜单");
				_getch();
				return(0);									// 返回0，结束函数
			}
		}
	}
	if (mark == 0)											// 如果没有找到符合条件的学生信息，则提示用户
	{
		printf("\t\t\t没有相同姓名的用户纪录\n");
		printf("\t\t\t按任意键返回主菜单\n");
		_getch();
		return(0);											// 返回0，结束函数
	}
	return 0;												// 如果有符合条件的学生信息，则返回0，结束函数
}


int searchContactByPhone()											//定义一个名为searchbyphone的函数，用来按电话号码查找学生信息
{
	int mark = 0;											// 定义一个整型变量mark，用来标记是否查找到了符合条件的学生信息
	int i;													// 定义一个整型变量i，用来遍历所有学生信息
	printf("\t\t\t****************** 按电话查找 ******************\n");
	char phone[10];											// 定义一个字符数组phone，用来存储用户输入的电话号码
	printf("\t\t\t请输入电话号码:");
	scanf("%s", phone);										// 获取用户输入的电话号码
	for (i = 0; i < num; i++)								// 遍历所有学生信息，查找符合条件的学生信息
	{
		if (strcmp(student[i].phone, phone) == 0)			// 如果找到了符合条件的学生信息，则输出信息并增加mark的值
		{
			printf("\t\t\t************** 以下是您查找的用户信息 **********\n");
			printf("\t\t\t姓名: %s\n", student[i].name);
			printf("\t\t\t电话: %s\n", student[i].phone);
			printf("\t\t\t地址: %s\n", student[i].adress);
			printf("\t\t\te-mail:%s\n", student[i].e_mail);
			printf("\t\t\t************************************************\n");
			printf("\t\t\t按任意键返回主菜单\n");
			mark++;											//学生信息+1
			_getch();										// 等待用户按任意键
			return(0);										// 返回0，结束函数
		}
	}
	if (mark == 0)											// 如果没有找到符合条件的学生信息，则提示用户
	{
		printf("\t\t\t没有改用户的信息\n");
		printf("\t\t\t按任意键返回主菜单\n");
		_getch();											// 等待用户按任意键
		return(0);											// 返回0，结束函数
	}
	return(0);												// 返回0，结束函数
}


void deletebyphone()												//定义了一个名为deletebyphone的函数，用于根据用户输入的电话号码删除通讯录中对应的记录。
{
	int i, j;														// 定义循环计数器i、j
	int deletemark = 0;												// 定义删除标记变量deletemark
	char phone[20];													// 定义电话号码变量phone
	printf("\t\t\t请输入要删除用户电话号码:");
	scanf("%s", phone);												//接收用户输入的电话号码


	if (num == 0)													// 若记录数组为空，则输出提示信息并返回
	{
		printf("\t\t\t对不起，文件中无任何纪录\n");
		printf("\t\t\t按任意键返回主菜单\n");
		_getch();
		return;
	}
	for (i = 0; i < num; i++)										// 遍历所有学生信息，找到与用户输入的电话号码相同的学生信息
	{
		if (strcmp(student[i].phone, phone) == 0)					// 输出该学生信息并询问用户是否删除该学生信息
		{
			printf("\t\t\t以下是您要删除的用户纪录:\n");
			printf("\t\t\t姓名: %s\n", student[i].name);
			printf("\t\t\t电话: %s\n", student[i].phone);
			printf("\t\t\t地址: %s\n", student[i].adress);
			printf("\t\t\te-mail:%s\n", student[i].e_mail);
			printf("\t\t\t是否删除?(y/n)");
			if (_getch() == 'y' || _getch() == 'Y')					// 若用户选择删除，则将该学生信息从记录数组中删除
			{
				for (j = i; j < num - 1; j++)						// 遍历所有学生信息，找到与用户输入的电话号码相同的学生信息
					student[j] = student[j + 1];
				num--;												// 学生信息数量减1
				deletemark++;										// 删除标记变量加1
				printf("\t\t\t删除成功");
				printf("\t\t\t是否继续删除?(y/n)");
				if (_getch() == 'y' || _getch() == 'Y')				// 若用户选择继续删除其他学生信息，则递归调用deletebyphone函数
					deletebyphone();
				return;												//删除后返回
			}
			else
				return;												// 否则，直接返回。
		}
		continue;													//continue语句用来控制循环，跳过当前迭代并立即开始新一轮迭代
	}
	if (deletemark == 0)											// 若找不到对应的学生信息，则输出提示信息并返回
	{
		printf("\t\t\t没有该用户的纪录");
		printf("\t\t\t是否继续删除?(y/n)");
		if (_getch() == 'y' || _getch() == 'Y')						// 若用户选择继续删除其他学生信息，则递归调用deletebyphone函数
			deletebyphone();
		return;														//删除后返回
	}
	return;															//返回函数
}








int sortContactByName()															//这是一个名为sortbyname的函数，用于将通讯录中的学生记录按照姓名的字典序进行升序排序。
{
	int i, j;
	struct ContactRecord tmp;
	for (i = 1; i < num; i++)												// 冒泡排序算法，按照姓名升序排序
	{
		if (strcmp(student[i].name, student[i - 1].name) < 0)				// 对于每个i，判断当前学生姓名是否比前一个学生姓名小，即判断是否需要交换其位置
		{
			tmp = student[i];												// 将当前学生信息保存到tmp中
			j = i - 1;														// 设置一个指针j指向前一个学生
			do																// 执行do-while循环，将指针j所指向的学生移到j+1的位置
			{
				student[j + 1] = student[j];								// 将指针j所指向的学生移到j+1的位置
				j--;														// 将j指针向前移动一个位置
			} while ((strcmp(tmp.name, student[j].name) < 0 && j >= 0));	// 直到遇到一个学生姓名比tmp的姓名小或j已经到了第一个学生为止
			student[j + 1] = tmp;											// 将tmp插入到指针j所指向的学生之后的位置，排序完成
		}
	}
	printf("\t\t\t排序成功,是否显示?(y/n)");								// 输出排序结果，并询问用户是否要显示排序后的结果
	if (_getch() == 'y')													// 如果用户选择显示排序结果，则调用 list() 函数，输出通讯录中所有学生的记录
		listContacts();
	return(0);																// 返回0，表示排序完成
}


void readContacts()															//定义了一个函数readfile，用于读取学生通讯录文件，并对每条记录进行解密处理和打印。
{
	FILE* fp = fopen("student_address_book.dat", "rb");					// 打开学生通讯录文件，以二进制格式写入的方式打开，并将文件指针赋值给fp变量。

	if (fp == NULL) {
		printf("Failed to open file.\n");   							// 如果文件打开失败，则输出错误提示信息并返回
		return;
	}

	//	struct record rec;												// 初始化变量
	num = 0;

	while (fread(&student[num], sizeof(struct ContactRecord), 1, fp) == 1)		// 循环读取每条记录
	{
		encrypt(student[num].postcode);
		encrypt(student[num].name);
		encrypt(student[num].adress);
		encrypt(student[num].phone);
		encrypt(student[num].e_mail);									// 对记录进行解密处理
		// 统计记录总数
		printf("姓名: %s\n", student[num].name);						// 打印记录信息
		printf("地址: %s\n", student[num].adress);
		printf("邮编: %s\n", student[num].postcode);
		printf("电话: %s\n", student[num].phone);
		printf("Email: %s\n", student[num].e_mail);
		num++;
		printf("-----------------------------\n");
	}
	fclose(fp);															// 关闭文件
	printf("Total number of records: %d\n", num);						// 打印记录总数
	system("pause");
}






