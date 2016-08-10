#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;
typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode
{
	LinkListNode* next;
};

LinkList* LinkList_Create();         //���������� 

void LinkList_Destroy(LinkList* list);     //���ٵ����� 

void LinkList_Clear(LinkList* list);      //��յ����� 

int LinkList_Length(LinkList* list);       //��ȡ�������� 

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);      //����ڵ� 

LinkListNode* LinkList_Get(LinkList* list, int pos);       //��ȡ�ڵ� 

LinkListNode* LinkList_Delete(LinkList* list, int pos);        //ɾ���ڵ� 

#endif

