
/******************************************************************************
**�ļ���: Seqlist.c
**���ܣ� ˳������ʵ����غ��� 
**���ߣ� ��ɶ� 
**QQ�� 1003768663
**ʱ��: 2014.9.20
******************************************************************************/


#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

typedef unsigned int TSeqListNode;    //����ڵ����� 

typedef struct _tag_SeqList
{
    int capacity;
	int length;
	TSeqListNode* node;	
}TSeqList;


SeqList* SeqList_Create(int capacity)       //����˳������
{
	TSeqList* ret = NULL;
	
	if(capacity>=0)
	{
		ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode)*capacity);
	}
	
	if(ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (TSeqListNode*)(ret + 1);
	}
	
	return ret;
}
void SeqList_Destroy(SeqList* list)      //�������� 
{
	free(list);
}
void SeqList_Clear(SeqList* list)     //������� 
{
	TSeqList* sList = (TSeqList*)list;
	
	if(sList != NULL)
	{
		sList->length = 0;	
	}
}
int SeqList_Length(SeqList* list)     //��ȡ������ 
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->length;	
	}
	
	return ret;
}
int SeqList_Capacity(SeqList* list)     //������������ 
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->capacity;
	}
	
	return ret;	
}
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)     //����ڵ� 
{
	TSeqList* sList = (TSeqList*)list;
	int ret = 0;
	int i = 0;
	
	ret = (sList != NULL) && (0<=pos) && ((sList->length + 1) <= sList->capacity);
	
	if( ret )
	{
		if(pos > sList->length)
		{
			pos = sList->length;	
		}
		
		for(i=sList->length; i>pos; i--)
		{
			sList->node[i] = sList->node[i-1];	
		}
		
		sList->node[pos] =  (TSeqListNode)node;
		sList->length += 1;
	} 
	
	return ret;
}
SeqListNode* SeqList_Get(SeqList* list, int pos)           //��ȡ�ڵ����� 
{
	TSeqList* sList = (TSeqList*)list;
	TSeqListNode* ret = NULL;
	
	if((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		ret = (TSeqListNode*)(sList->node[pos]);
	}
	
	return ret;
}
SeqListNode* SeqList_Delete(SeqList* list, int pos)   //ɾ���ڵ� 
{
	TSeqList* sList = (TSeqList*)list;
	TSeqListNode* ret = SeqList_Get(list, pos);
	int i = 0;
	
	if( ret != NULL )
	{
		for(i=pos+1; i<sList->length; i++)
		{
			sList->node[i-1] = sList->node[i];	
		}
		
		sList->length -= 1;
	} 
	
	return ret;
}








