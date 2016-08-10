/*****************************************************************************
**�ļ�����DLinkList.c
**���ܣ�˫��������Ը����ܴ��� 
**���ߣ���ɶ�
**QQ:1003768663
**ʱ�䣺2014.9.21
*****************************************************************************/
 
#include <malloc.h>
#include "DLinkList.h"


typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider; 
	int length;	
}TDLinkList;  

DLinkList* DLinkList_Create()         //����˫������ 
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
void DLinkList_Destroy(DLinkList* list)    //���ٵ����� 
{
	free(list);
}
void DLinkList_Clear(DLinkList* list)     //��յ����� 
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
int DLinkList_Length(DLinkList* list)       //��ȡ�������� 
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->length;
	}
	
	return ret;	
}
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)      //����ڵ� 
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = 0;
	int i = 0;
	
	ret = (sList != NULL) && (0 <= pos) && (node != NULL);
	
	if( ret )
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;
		
		for(i=0; (i<pos)&&(current->next!=NULL); i++)     //Ѱ�Ҷ�Ӧλ�� 
		{
			current = current->next;
		}
		
		next = current->next;
		current->next = node;
		node->next = next;		// ���� 
		
		if(next != NULL)
		{
			next->pre = node;	
		}
		
		if(0 == sList->length)  //����Ϊ0.����Ҫǰ��ΪNULL 
		{
			node->pre = NULL;
		}
		else
		{
			if(current == (DLinkListNode*)sList)       //������ǵ�0λ��,����Ҫǰ��ΪNULL 
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
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)       //��ȡ�ڵ� 
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
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)       //ɾ���ڵ� 
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
        current->next = next;     //ɾ�� 
        
        if(next != NULL)
        {
            next->pre = current;
            
            if(current == (DLinkListNode*)sList)
            {
                next->pre = NULL;
            }
        }
       	if(sList->slider == ret)  //ɾ���Ľڵ�պú��α���ͬ,���ƶ��α� 
        {
            sList->slider = next;
        }	
		sList->length -= 1;	
	}
	
	return ret;
}
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)   //ɾ���ڵ� 
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
DLinkListNode* DLinkList_Reset(DLinkList* list)    //��λ�α� 
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
DLinkListNode* DLinkList_Current(DLinkList* list)  //��ǰ�α�ڵ� 
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	
	if(sList != NULL)
	{
		ret = sList->slider;	
	}
	
	return ret;
}
DLinkListNode* DLinkList_Next(DLinkList* list) //��һ���α� �ڵ�
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
DLinkListNode* DLinkList_Pre(DLinkList* list)      //ǰһ���α�ڵ� 
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

