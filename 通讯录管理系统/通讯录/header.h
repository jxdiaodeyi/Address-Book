#pragma once

extern struct ContactRecord student[100];											// 定义一个名为record的结构体类型，用来存储学生的信息

extern void encrypt(char* pwd);												// 定义一个名为encrypt的函数，用于对传入的字符串进行简单的加密处理

extern int  get_record_count();																										//作用是获取当前通讯录中记录的数量

extern int showLoginInterface();																									//显示登录界面

extern void showMainInterface();																									//显示主界面

extern void showEditRecordInterface(struct ContactRecord contacts[], int num_contacts);												//显示编辑记录界面

extern void showInsertRecordInterface(struct ContactRecord contacts[], int* num_contacts);											//显示插入记录界面

extern void showGroupManagementInterface(struct ContactRecord contacts[], int num_contacts);										//显示分组管理界面

extern void showTagSystemInterface(struct ContactRecord contacts[], int num_contacts);												//显示标签系统管理界面

extern int menu_select();																											//用来显示菜单并获取操作选项

extern int num;																														// 声明一个名为num的整型变量

extern int addContacts();																											//用来添加学生信息

extern void listContacts();																											//用来显示所有学生信息

extern int searchContactByName();																									//用来按姓名查找学生信息

extern int searchContactByPhone();																									//用来按电话号码查找学生信息

extern int searchContactByAddress(struct ContactRecord contacts[], int* num_contacts,char* address);								//按地址查找

extern int searchContactByPostcode(struct ContactRecord contacts[], int* num_contacts, char* postcode);								//按邮编查找

extern int searchContactByEmail(struct ContactRecord contacts[], int* num_contacts, char* email);									//按邮箱查找

extern int sortContactByName();																										//用于通讯录中的学生记录升序排序

extern void readContacts(struct ContactRecord contacts[], int *num_contacts);														//读取联系人信息

extern void writeContacts(struct ContactRecord contacts[], int* num_contacts);													//写入联系人信息

void showDeleteRecordInterface(struct ContactRecord contacts[], int num_contacts);												    //打印删除界面

int deleteContact(struct ContactRecord contacts[], int num_contacts, char* key, int delete_type);									//删除联系人信息

int searchContactByName(struct ContactRecord contacts[], int num_contacts, char* name);												//姓名查找

int searchContactByPhone(struct ContactRecord contacts[], int num_contacts, char* phone);											//电话查找

int searchContactByAddress(struct ContactRecord contacts[], int num_contacts, char* address);										//地址查找

int searchContactByPostcode(struct ContactRecord contacts[], int num_contacts, char* postcode);										//邮编查找

int searchContactByEmail(struct ContactRecord contacts[], int num_contacts, char* email);											//邮箱查找

int fuzzySearchContacts(struct ContactRecord contacts[], int num_contacts, char* keyword);											//模糊查找

int searchContactsByGroup(struct ContactRecord contacts[], int num_contacts, char* group);											//分组查找

void showSearchInterface(struct ContactRecord contacts[], int num_contacts);														//打印查找界面

bool authenticateUser(const char* filename, const char* username, const char* password);											//验证账号和密码

int multiConditionSearch(struct ContactRecord contacts[], int* num_contacts, char* name, char* phone, char* address, char* email);  //多条件搜索联系人

int addGroup(struct ContactRecord contacts[], int* num_contacts, char* group);														//添加分组

int deleteGroup(struct ContactRecord contacts[], int* num_contacts, char* group);													//删除分组

int deleteTagFromContact(struct ContactRecord contacts[], int* num_contacts, char* contactName, char* tag);							//删除联系人标签

