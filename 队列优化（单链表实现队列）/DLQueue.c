/****************************************************************************
**�ļ�����DLQueue.c
**���ܣ����Ƶ�����ʵ�ֶ��У��Զ��н����Ż������ܸ��� 
		(��Ҫ�Ż��˳���,ʵ��O(1))
**���ߣ���ɶ�
**QQ��1003768663
*****************************************************************************/
 
#include <malloc.h>
#include "DLQueue.h"





DLQueue* DLQueue_Create(void)		//�������� 
{
	TDLQueue *ret = (TDLQueue*)malloc(sizeof(TDLQueue));
	
	if(ret != NULL)
	{
		ret->front = NULL;
		ret->rear =NULL;
		ret->length = 0;
	}
	
	return ret; 
}
void DLQueue_Destroy(DLQueue* queue)		//���ٶ��� 
{
	DLQueue_Clear(queue);
	free(queue);
}
void DLQueue_Clear(DLQueue* queue)		//��ն��� 
{
	while(DLQueue_Length(queue) > 0)
	{
		DLQueue_Retrieve(queue);	
	}
}
int DLQueue_Append(DLQueue* queue, void* item)			//�˶��� 
{
	TDLQueue *TQueue = (TDLQueue*)queue;
	TDLQueueNode *node = (TDLQueueNode*)malloc(sizeof(TDLQueueNode));
	int ret = 0;
	
	if((TQueue != NULL) && (item != NULL) && (node != NULL))
	{
		node->item = item;		//�ڵ�����������������ݵĵ�ַ
		
		if(DLQueue_Length(TQueue) > 0)
		{
			TQueue->rear->next = node;		//��ǰ�����һ��nextָ��node 
			TQueue->rear = node; 		//��ǰ���һ��Ϊnode 
			node->next = NULL;	
		}
		else
		{		//��0����� 
			TQueue->front = node;
			TQueue->rear = node; 
			node->next = NULL;
		} 
		
		TQueue->length ++;
	}
	else
	{
		free(node);
	}
	
	return ret;
}
void* DLQueue_Retrieve(DLQueue* queue)			//������ 
{
	TDLQueue* TQueue = (TDLQueue*)queue;
    TDLQueueNode* node = NULL;
    void* ret = NULL;
    
    if((TQueue != NULL) && (TQueue->length > 0))
    {
        node = TQueue->front;
        
        TQueue->front = node->next;
        
        ret = node->item;
        
        free(node);
        
        TQueue->length--;
        
        if( TQueue->length == 0 )
        {
            TQueue->front = NULL;
            TQueue->rear = NULL;
        }
    }
    
    return ret;
}
void* DLQueue_Header(DLQueue* queue)		//��ȡ����ͷ 
{
	TDLQueue* TQueue = (TDLQueue*)queue;
    void* ret = NULL;
    
    if((TQueue != NULL) && (TQueue->length > 0))
    {
        ret = TQueue->front->item;
    }
    
    return ret;
}
int DLQueue_Length(DLQueue* queue)		//��ȡ���г��� 
{
	TDLQueue *ret = (TDLQueue*)queue;
	int len = 0;
	
	if(ret != NULL)
	{
		len = ret->length;
	}

	return len;
}

