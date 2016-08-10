/*****************************************************************************
**函数名：LinkList.c
**功能：单链表实现函数 
**作者：朱飞东 
**QQ：1003768663
**日期：2014.9.21
******************************************************************************/ 
#include <malloc.h>
#include "LinkList.h"


typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()         //创建单链表 
{
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->length = 0;
	}
	return ret;
}
void LinkList_Destroy(LinkList* list)     //销毁单链表 
{
	free(list);
}
void LinkList_Clear(LinkList* list)      //清空单链表 
{
	TLinkList* sList = (TLinkList*)list;
	
	if(sList != NULL)
	{
		sList->header.next = NULL;
		sList->length = 0;	
	}
}
int LinkList_Length(LinkList* list)      //读取单链表长度 
{
	TLinkList* sList = (TLinkList*)list;
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->length;	
	}
	
	return ret;
}
/*****************************************************************
**函数名：LinkList_Insert
**输入参数：node：节点名(节点包括：数据,指针域),pos：位置
**输出参数：1，插入成功，0 失败
**功能:往链表里面插入一个节点
*****************************************************************/
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)      //插入节点 
{
	TLinkList* sList = (TLinkList*)list;
	int ret = 0;
	int i = 0;
	
	ret = (sList != NULL) && (0 <= pos) && (node != NULL);
	
	if( ret )
	{
		LinkListNode* current = (LinkListNode*)sList;
		
		for(i=0; (i<pos)&&(current->next!=NULL); i++)
		{
			current = current->next;	
		}
		
		node->next = current->next;
		current->next = node;
		
		sList->length += 1;
	}
	
	return ret;
}
/*****************************************************************
**函数名：*LinkList_Get
**输入参数：pos：位置
**输出参数：输出节点地址(节点包括：数据,指针域)
**功能:链表里面读取一个节点
*****************************************************************/
LinkListNode* LinkList_Get(LinkList* list, int pos)       //读取节点 
{
	TLinkList* sList = (TLinkList*)list;
	LinkListNode* ret =NULL;
	int i = 0;
	
	if((sList != NULL) && (0<=pos) && (pos<sList->length))
	{
		LinkListNode* current = (LinkListNode*)sList;
		
		for(i=0; i<pos; i++)
		{
			current = current->next;	
		}
		
		ret = current->next;
	}
	
	return ret;
}
/*****************************************************************
**函数名：*LinkList_Delete
**输入参数：pos：位置
**输出参数：输出被删除节点的地址(节点包括：数据,指针域)
**功能:链表里面删除一个节点
*****************************************************************/
LinkListNode* LinkList_Delete(LinkList* list, int pos)       //删除节点
{
	TLinkList* sList = (TLinkList*)list;
	LinkListNode* ret =NULL;
	int i = 0;
	
	if((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		LinkListNode* current = (LinkListNode*)sList;
		
		for(i=0; i<pos; i++)
		{
			current = current->next;	
		}
		
		ret = current->next;
		current->next = ret->next;
		
		sList->length -= 1;
	}
	
	return ret;
}


