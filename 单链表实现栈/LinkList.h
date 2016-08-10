#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;
typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode
{
	LinkListNode* next;
};

LinkList* LinkList_Create();         //创建单链表 

void LinkList_Destroy(LinkList* list);     //销毁单链表 

void LinkList_Clear(LinkList* list);      //清空单链表 

int LinkList_Length(LinkList* list);       //读取单链表长度 

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);      //插入节点 

LinkListNode* LinkList_Get(LinkList* list, int pos);       //读取节点 

LinkListNode* LinkList_Delete(LinkList* list, int pos);        //删除节点 

#endif

