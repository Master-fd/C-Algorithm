/****************************************************************************
**文件名：DLQueue.c
**功能：类似单链表实现队列，对队列进行优化，性能更好 
		(主要优化了出列,实现O(1))
**作者：朱飞东
**QQ：1003768663
*****************************************************************************/
 
#include <malloc.h>
#include "DLQueue.h"





DLQueue* DLQueue_Create(void)		//创建队列 
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
void DLQueue_Destroy(DLQueue* queue)		//销毁队列 
{
	DLQueue_Clear(queue);
	free(queue);
}
void DLQueue_Clear(DLQueue* queue)		//清空队列 
{
	while(DLQueue_Length(queue) > 0)
	{
		DLQueue_Retrieve(queue);	
	}
}
int DLQueue_Append(DLQueue* queue, void* item)			//人队列 
{
	TDLQueue *TQueue = (TDLQueue*)queue;
	TDLQueueNode *node = (TDLQueueNode*)malloc(sizeof(TDLQueueNode));
	int ret = 0;
	
	if((TQueue != NULL) && (item != NULL) && (node != NULL))
	{
		node->item = item;		//节点数据域就是输入数据的地址
		
		if(DLQueue_Length(TQueue) > 0)
		{
			TQueue->rear->next = node;		//当前的最后一个next指向node 
			TQueue->rear = node; 		//当前最后一个为node 
			node->next = NULL;	
		}
		else
		{		//第0个入队 
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
void* DLQueue_Retrieve(DLQueue* queue)			//出队列 
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
void* DLQueue_Header(DLQueue* queue)		//获取队列头 
{
	TDLQueue* TQueue = (TDLQueue*)queue;
    void* ret = NULL;
    
    if((TQueue != NULL) && (TQueue->length > 0))
    {
        ret = TQueue->front->item;
    }
    
    return ret;
}
int DLQueue_Length(DLQueue* queue)		//获取队列长度 
{
	TDLQueue *ret = (TDLQueue*)queue;
	int len = 0;
	
	if(ret != NULL)
	{
		len = ret->length;
	}

	return len;
}

