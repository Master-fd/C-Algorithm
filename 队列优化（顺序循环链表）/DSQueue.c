/****************************************************************************
**文件名：DSQueue.c
**功能：队列优化，顺序循环队列的相关函数实现 
**作者：朱飞东
**日期:2014.10.6
**QQ：1003768663
****************************************************************************/ 
#include <malloc.h>
#include "DSQueue.h"





DSQueue* DSQueue_Create(int capacity)		//创建队列 
{
	TDSQueue *ret = NULL;
	
	if(capacity > 0)
	{
		ret = (TDSQueue*)malloc(sizeof(TDSQueue) + sizeof(TDSQueueNode)*capacity);
	}

	if(ret != NULL)
	{
		ret->capacity = capacity;
		ret->front = 0;
		ret->rear = 0;
		ret->length = 0;		
		ret->node = (TDSQueueNode*)(ret + 1);
	}
	
	return ret;
}
void DSQueue_Destroy(DSQueue* queue)		//销毁队列 
{
	free(queue);
}
void DSQueue_Clear(DSQueue* queue)		//清空队列 
{
	TDSQueue *ret = (TDSQueue*)queue;
	
	if(ret != NULL)
	{
		ret->length = 0;
		ret->front = 0;
		ret->rear = 0;
	}
}
int DSQueue_Append(DSQueue* queue, void* item)			//入队列 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	int ret = (squeue != NULL) && (squeue->length < squeue->capacity);
	
	if(ret)
	{
		squeue->node[squeue->rear] = (TDSQueueNode)item;	//把数据地址入队列 
		squeue->rear = (squeue->rear++) % (squeue->capacity);  //始终指向下一个队列位置 
		squeue->length ++;		//长度自加  
	}
		
	return ret;
}
void* DSQueue_Retrieve(DSQueue* queue)			//出队列 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	TDSQueueNode *ret = NULL;
	
	if(squeue != NULL)
	{
		ret = (TDSQueueNode*)squeue->node[squeue->front];
		squeue->front = (squeue->front++) % (squeue->capacity);  //始终指向下一个队列位置 
		squeue->length --;		//长度自减 
	}
	
	return ret;
}
void* DSQueue_Header(DSQueue* queue)		//获取队列头 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	TDSQueueNode *ret = NULL;
	
	if(squeue != NULL)
	{
		ret = (TDSQueueNode*)squeue->node[squeue->front];
	}
	
	return ret;
}
int DSQueue_Length(DSQueue* queue)		//获取队列长度 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	int ret = 0;
	
	if(squeue != NULL)
	{
		ret = squeue->length;
	}
	
	return ret;
}
int DSQueue_Capacity(DSQueue* queue)		//获取队列容量 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	int ret = 0;
	
	if(squeue != NULL)
	{
		ret = squeue->capacity;
	}
	
	return ret;
}




