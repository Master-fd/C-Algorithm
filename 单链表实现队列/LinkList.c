/*****************************************************************************
**��������LinkList.c
**���ܣ�������ʵ�ֺ��� 
**���ߣ���ɶ� 
**QQ��1003768663
**���ڣ�2014.9.21
******************************************************************************/ 
#include <malloc.h>
#include "LinkList.h"


typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()         //���������� 
{
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->length = 0;
	}
	return ret;
}
void LinkList_Destroy(LinkList* list)     //���ٵ����� 
{
	free(list);
}
void LinkList_Clear(LinkList* list)      //��յ����� 
{
	TLinkList* sList = (TLinkList*)list;
	
	if(sList != NULL)
	{
		sList->header.next = NULL;
		sList->length = 0;	
	}
}
int LinkList_Length(LinkList* list)      //��ȡ�������� 
{
	TLinkList* sList = (TLinkList*)list;
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->length;	
	}
	
	return ret;
}
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)      //����ڵ� 
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
LinkListNode* LinkList_Get(LinkList* list, int pos)       //��ȡ�ڵ� 
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
LinkListNode* LinkList_Delete(LinkList* list, int pos)       //ɾ���ڵ�
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


