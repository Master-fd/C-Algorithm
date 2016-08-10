#ifndef _DLINK_LIST_H_
#define _DLINK_LIST_H_


typedef void DLinkList;
typedef struct _tag_DLinkListNode DLinkListNode;
/*struct _tag_DLinkListNode
{
	DLinkListNode* next;
	DLinkListNode* pre;
};*/
struct _tag_DLinkListNode
{
	void* next;
	void* pre;
};

DLinkList* DLinkList_Create();         //创建双向单链表 

void DLinkList_Destroy(DLinkList* list);     //销毁单链表 

void DLinkList_Clear(DLinkList* list);      //清空单链表 

int DLinkList_Length(DLinkList* list);       //读取单链表长度 

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);      //插入节点 

DLinkListNode* DLinkList_Get(DLinkList* list, int pos);       //读取节点 

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);        //删除节点 

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node); //删除节点

DLinkListNode* DLinkList_Reset(DLinkList* list);    //复位游标

DLinkListNode* DLinkList_Current(DLinkList* list);  //当前游标 节点

DLinkListNode* DLinkList_Next(DLinkList* list); //后一个游标节点 

DLinkListNode* DLinkList_Pre(DLinkList* list);     //前一个游标 节点


#endif
