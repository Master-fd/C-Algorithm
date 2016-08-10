/*****************************************************************************
**�ļ�����LinkQueue.c
**���ܣ�������غ�����ʵ�� 
**���ߣ���ɶ�
**QQ��1003768663
*******************************************************************************/ 
#include <malloc.h>
#include "LinkList.h"
#include "LinkQueue.h"

//����һ������ʹ�õĽڵ����� 
typedef struct _tag_TLinkQueueNode
{
	LinkQueueNode header;
	void* item;
}TLinkQueueNode;


LinkQueue *LinkQueue_Create(void)          //��������
{
	return LinkList_Create(); 	
}
void LinkQueue_Destroy(LinkQueue *queue)		//���ٶ���
{
	LinkQueue_Clear(queue);			//��Ҫ����ն���,�����ڴ�й¶ 
	LinkList_Destroy(queue);
}
void LinkQueue_Clear(LinkQueue *queue)		//��ն��� 
{
	while(LinkQueue_Length(queue))	
	{
		LinkQueue_Retrieve(queue);	//�Ȱ�ȫ�����У������ڴ�й¶ 
	}
	
	LinkList_Clear(queue);		//���,���ָ����ȵ�Ϊ��ʼ״̬ 	
}
/*****************************************************************
**��������LinkQueue_Append
**���������item�����ݵ�ַ(���ݵ�ַ��������ָ����),�����ڲ������ռ�
				������ָ���� 
**���������1����ӳɹ���0 ʧ��
**����:�������������һ������ 
*****************************************************************/
int LinkQueue_Append(LinkQueue *queue, LinkQueueNode *item)			//����� 
{
	TLinkQueueNode *node = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));		
	//����һ���ڵ�,ͬʱ�ڶ��������ռ� 
	int ret = (item != NULL) && (queue != NULL) && (node != NULL);
	
	if( ret )
	{
		node->item = item;	//�ڵ�����ݲ��־�����������ݵĵ�ַ 
		
		LinkList_Insert(queue, node, LinkList_Length(queue));
	}
	else
	{
		free(node);	//ʧ�ܣ����ͷŷ�����ڴ�ռ� 
	}
	
	return ret; 
}
/*****************************************************************
**��������*LinkQueue_Retrieve
**���������queue:������ 
**���������������������ݵĵ�ַ(���ݵ�ַ��������ָ����)
**����:������ 
*****************************************************************/
LinkQueueNode *LinkQueue_Retrieve(LinkQueue *queue)		//������ 
{
	TLinkQueueNode *node = (TLinkQueueNode*)LinkList_Delete(queue, 0);
	void *ret = NULL;
	
	if(node != NULL)
	{
		ret = node->item;	//
		
		free(node);	//�ͷ��ڴ� 
	}
	
	return ret; 
}
/*****************************************************************
**��������*LinkQueue_Header
**���������queue:������ 
**������������е�0�����ݵ�ַ(���ݵ�ַ��������ָ����)
**����:������е�0�����ݵ�ַ 
*****************************************************************/
LinkQueueNode *LinkQueue_Header(LinkQueue *queue)			//��ȡ����ͷ���� 
{
	TLinkQueueNode *node = (TLinkQueueNode*)LinkList_Get(queue, 0);
	void *ret = NULL;
	
	if(node != NULL)
	{
		ret = node->item;	//
	}
	
	return ret; 
}
int LinkQueue_Length(LinkQueue *queue)		//���г��� 
{
	return LinkList_Length(queue);
}


