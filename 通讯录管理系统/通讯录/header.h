#pragma once

extern struct ContactRecord student[100];											// ����һ����Ϊrecord�Ľṹ�����ͣ������洢ѧ������Ϣ

extern void encrypt(char* pwd);												// ����һ����Ϊencrypt�ĺ��������ڶԴ�����ַ������м򵥵ļ��ܴ���

extern int  get_record_count();																										//�����ǻ�ȡ��ǰͨѶ¼�м�¼������

extern int showLoginInterface();																									//��ʾ��¼����

extern void showMainInterface();																									//��ʾ������

extern void showEditRecordInterface(struct ContactRecord contacts[], int num_contacts);												//��ʾ�༭��¼����

extern void showInsertRecordInterface(struct ContactRecord contacts[], int* num_contacts);											//��ʾ�����¼����

extern void showGroupManagementInterface(struct ContactRecord contacts[], int num_contacts);										//��ʾ����������

extern void showTagSystemInterface(struct ContactRecord contacts[], int num_contacts);												//��ʾ��ǩϵͳ�������

extern int menu_select();																											//������ʾ�˵�����ȡ����ѡ��

extern int num;																														// ����һ����Ϊnum�����ͱ���

extern int addContacts();																											//�������ѧ����Ϣ

extern void listContacts();																											//������ʾ����ѧ����Ϣ

extern int searchContactByName();																									//��������������ѧ����Ϣ

extern int searchContactByPhone();																									//�������绰�������ѧ����Ϣ

extern int searchContactByAddress(struct ContactRecord contacts[], int* num_contacts,char* address);								//����ַ����

extern int searchContactByPostcode(struct ContactRecord contacts[], int* num_contacts, char* postcode);								//���ʱ����

extern int searchContactByEmail(struct ContactRecord contacts[], int* num_contacts, char* email);									//���������

extern int sortContactByName();																										//����ͨѶ¼�е�ѧ����¼��������

extern void readContacts(struct ContactRecord contacts[], int *num_contacts);														//��ȡ��ϵ����Ϣ

extern void writeContacts(struct ContactRecord contacts[], int* num_contacts);													//д����ϵ����Ϣ

void showDeleteRecordInterface(struct ContactRecord contacts[], int num_contacts);												    //��ӡɾ������

int deleteContact(struct ContactRecord contacts[], int num_contacts, char* key, int delete_type);									//ɾ����ϵ����Ϣ

int searchContactByName(struct ContactRecord contacts[], int num_contacts, char* name);												//��������

int searchContactByPhone(struct ContactRecord contacts[], int num_contacts, char* phone);											//�绰����

int searchContactByAddress(struct ContactRecord contacts[], int num_contacts, char* address);										//��ַ����

int searchContactByPostcode(struct ContactRecord contacts[], int num_contacts, char* postcode);										//�ʱ����

int searchContactByEmail(struct ContactRecord contacts[], int num_contacts, char* email);											//�������

int fuzzySearchContacts(struct ContactRecord contacts[], int num_contacts, char* keyword);											//ģ������

int searchContactsByGroup(struct ContactRecord contacts[], int num_contacts, char* group);											//�������

void showSearchInterface(struct ContactRecord contacts[], int num_contacts);														//��ӡ���ҽ���

bool authenticateUser(const char* filename, const char* username, const char* password);											//��֤�˺ź�����

int multiConditionSearch(struct ContactRecord contacts[], int* num_contacts, char* name, char* phone, char* address, char* email);  //������������ϵ��

int addGroup(struct ContactRecord contacts[], int* num_contacts, char* group);														//��ӷ���

int deleteGroup(struct ContactRecord contacts[], int* num_contacts, char* group);													//ɾ������

int deleteTagFromContact(struct ContactRecord contacts[], int* num_contacts, char* contactName, char* tag);							//ɾ����ϵ�˱�ǩ

