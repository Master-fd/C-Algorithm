/*****************************************************************************
**文件名：DLinkList.c
**功能：双向单链表测试各功能代码 
**作者：朱飞东
**QQ:1003768663
**时间：2014.9.21
*****************************************************************************/
 
#include <malloc.h>
#include "DLinkList.h"


typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider; 
	int length;	
}TDLinkList;  

DLinkList* DLinkList_Create()         //创建双向单链表 
{
	TDLinkList* ret = NULL;
	
	ret = (TDLinkList*)malloc(sizeof(TDLinkList));
	
	if(ret != NULL)
	{
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
		ret->length = 0;
	}
	
	return ret;
}
void DLinkList_Destroy(DLinkList* list)    //销毁单链表 
{
	free(list);
}
void DLinkList_Clear(DLinkList* list)     //清空单链表 
{
	TDLinkList* sList = (TDLinkList*)list;
	
	if(sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->header.pre = NULL;
		sList->slider = NULL;
	}
}
int DLinkList_Length(DLinkList* list)       //读取单链表长度 
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->length;
	}
	
	return ret;	
}
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)      //插入节点 
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = 0;
	int i = 0;
	
	ret = (sList != NULL) && (0 <= pos) && (node != NULL);
	
	if( ret )
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;
		
		for(i=0; (i<pos)&&(current->next!=NULL); i++)     //寻找对应位置 
		{
			current = current->next;
		}
		
		next = current->next;
		current->next = node;
		node->next = next;		// 插入 
		
		if(next != NULL)
		{
			next->pre = node;	
		}
		
		if(0 == sList->length)  //长度为0.则需要前驱为NULL 
		{
			node->pre = NULL;
		}
		else
		{
			if(current == (DLinkListNode*)sList)       //插入的是第0位置,则需要前驱为NULL 
			{
				node->pre = NULL;
			}
			else
			{
				node->pre = current;
			}
		}
		
		sList->length += 1;
	}
	
	return ret;
}
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)       //读取节点 
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	
	if((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		DLinkListNode* current = (DLinkListNode*)sList;

		for(i=0; i<pos; i++)
		{
			current = current->next;	
		}
		
		ret = current->next;		
	}
	
	return ret;
}
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)       //删除节点 
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	
	if((sList != NULL) && ( 0<= pos) && (pos < sList->length))
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;
		
		for(i=0; i<pos; i++)
		{
			current = current->next;	
		}
		
		ret = current->next;
        next = ret->next;
        current->next = next;     //删除 
        
        if(next != NULL)
        {
            next->pre = current;
            
            if(current == (DLinkListNode*)sList)
            {
                next->pre = NULL;
            }
        }
       	if(sList->slider == ret)  //删除的节点刚好和游标相同,则移动游标 
        {
            sList->slider = next;
        }	
		sList->length -= 1;	
	}
	
	return ret;
}
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)   //删除节点 
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	
	if(sList != NULL)
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		
		for(i=0; i<sList->length; i++)
		{
			if(current->next == node)
			{
				ret = current->next;
				break;	
			}	
			current = current->next;
		}
		
		if(ret != NULL)
		{
			DLinkList_Delete(sList, i);
		}
	}
	
	return ret;
}
DLinkListNode* DLinkList_Reset(DLinkList* list)    //复位游标 
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	
	if(sList != NULL)
	{
		sList->slider = sList->header.next;
		ret = sList->slider;	
	}
	
	return ret;
}
DLinkListNode* DLinkList_Current(DLinkList* list)  //当前游标节点 
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	
	if(sList != NULL)
	{
		ret = sList->slider;	
	}
	
	return ret;
}
DLinkListNode* DLinkList_Next(DLinkList* list) //后一个游标 节点
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	
	if((sList != NULL) && (sList->slider != NULL))
	{
		ret = sList->slider;	
		sList->slider = ret->next; 
	}
	
	return ret;	
}
DLinkListNode* DLinkList_Pre(DLinkList* list)      //前一个游标节点 
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	
	if((sList != NULL) && (sList->slider != NULL))
	{
		ret = sList->slider;	
		sList->slider = ret->pre;
	}
	
	return ret;	
}

