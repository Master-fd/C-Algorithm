/****************************************************************************
**�ļ�����DSQueue.c
**���ܣ������Ż���˳��ѭ�����е���غ���ʵ�� 
**���ߣ���ɶ�
**����:2014.10.6
**QQ��1003768663
****************************************************************************/ 
#include <malloc.h>
#include "DSQueue.h"





DSQueue* DSQueue_Create(int capacity)		//�������� 
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
void DSQueue_Destroy(DSQueue* queue)		//���ٶ��� 
{
	free(queue);
}
void DSQueue_Clear(DSQueue* queue)		//��ն��� 
{
	TDSQueue *ret = (TDSQueue*)queue;
	
	if(ret != NULL)
	{
		ret->length = 0;
		ret->front = 0;
		ret->rear = 0;
	}
}
int DSQueue_Append(DSQueue* queue, void* item)			//����� 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	int ret = (squeue != NULL) && (squeue->length < squeue->capacity);
	
	if(ret)
	{
		squeue->node[squeue->rear] = (TDSQueueNode)item;	//�����ݵ�ַ����� 
		squeue->rear = (squeue->rear++) % (squeue->capacity);  //ʼ��ָ����һ������λ�� 
		squeue->length ++;		//�����Լ�  
	}
		
	return ret;
}
void* DSQueue_Retrieve(DSQueue* queue)			//������ 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	TDSQueueNode *ret = NULL;
	
	if(squeue != NULL)
	{
		ret = (TDSQueueNode*)squeue->node[squeue->front];
		squeue->front = (squeue->front++) % (squeue->capacity);  //ʼ��ָ����һ������λ�� 
		squeue->length --;		//�����Լ� 
	}
	
	return ret;
}
void* DSQueue_Header(DSQueue* queue)		//��ȡ����ͷ 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	TDSQueueNode *ret = NULL;
	
	if(squeue != NULL)
	{
		ret = (TDSQueueNode*)squeue->node[squeue->front];
	}
	
	return ret;
}
int DSQueue_Length(DSQueue* queue)		//��ȡ���г��� 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	int ret = 0;
	
	if(squeue != NULL)
	{
		ret = squeue->length;
	}
	
	return ret;
}
int DSQueue_Capacity(DSQueue* queue)		//��ȡ�������� 
{
	TDSQueue *squeue = (TDSQueue*)queue;
	int ret = 0;
	
	if(squeue != NULL)
	{
		ret = squeue->capacity;
	}
	
	return ret;
}




