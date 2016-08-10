/**********************************************************************
**�ļ�����LinkSatck.c 
**���ܣ����õ�����ʵ��ջ���ܵ���غ��� 
**���ߣ���ɶ� 
**QQ��1003768663
**���ڣ�2014.9.24
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "LinkStack.h"


typedef struct _tag_LinkStackNode
{
	LinkListNode header;
	void* item;
}TLinkStackNode;



/*********************************************************************
**��������LinkStack_Create
**���ܣ�����ջ 
**����������� 
**���������ջ�׵�ַ 
*********************************************************************/ 
LinkStack* LinkStack_Create()      //����ջ 
{
	return LinkList_Create();         //���������� 
}
/*********************************************************************
**��������LinkStack_Destroy   
**���ܣ�����ջ 
**���������LinkStack* stack �� ջ�� 
**����������� 
*********************************************************************/ 
void LinkStack_Destroy(LinkStack* stack)      //����ջ 
{
	LinkStack_Clear(stack);       //���ջ 
	LinkList_Destroy(stack);      //���� 
}
/*********************************************************************
**��������LinkStack_Clear   
**���ܣ����ջ 
**���������ջ�� 
**����������� 
*********************************************************************/ 
void LinkStack_Clear(LinkStack* stack)     //���ջ 
{
	while(LinkList_Length(stack) > 0)
	{
		LinkStack_Pop(stack);   //�Ȱ����еĶ����� 
	}
	
	LinkList_Clear(stack);  
}
/*********************************************************************
**��������LinkStack_Length 
**���ܣ���ȡջ���� 
**���������ջ�� 
**�������������ջ���� 
*********************************************************************/ 
int LinkStack_Length(LinkStack* stack)
{
	return LinkList_Length(stack);
}
/*********************************************************************
**��������LinkStack_Push  
**���ܣ�ѹ��ջ
**���������ջ�� 
**��������� 
*********************************************************************/ 
int LinkStack_Push(LinkStack* stack, void* node)     //ѹ��ջ 
{
	TLinkStackNode* data = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));   //�����ڴ�
	int ret = 0;
	
	if((data != NULL) && (node != NULL))
	{
		data->item = node;
		ret = LinkList_Insert(stack, (LinkListNode*)data, LinkList_Length(stack));
	} 
	else
	{
		free(data);       //�ͷ��ڴ�,���������ڴ�й¶ 
	}
	
	return ret;
}
/*********************************************************************
**��������LinkStack_Pop
**���ܣ�����ջ 
**���������ջ�� 
**������������������� 
*********************************************************************/ 
void* LinkStack_Pop(LinkStack* stack)            //����ջ 
{
	TLinkStackNode* node = (TLinkStackNode*)LinkList_Delete(stack, LinkList_Length(stack) - 1);  
	void* ret = NULL;
	
	if(node != NULL)
	{
		ret = node->item;
		free(node);
	}
	
	return ret; 
}
/*********************************************************************
**��������LinkStack_Top
**���ܣ���ȡջ�� 
**���������ջ�� 
**�������������ջ������ 
*********************************************************************/ 
void* LinkStack_Top(LinkStack* stack)   //��ȡջ�� 
{
	TLinkStackNode* node = (TLinkStackNode*)LinkList_Get(stack, LinkList_Length(stack) - 1);  
	void* ret = NULL;
	
	if(node != NULL)
	{
		ret = node->item;
	}
	
	return ret;       //��ȡ�ڵ� 
}


