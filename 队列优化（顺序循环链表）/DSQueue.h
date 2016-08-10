#ifndef _DSQUEUE_H_
#define _DSQUEUE_H_

typedef void DSQueue;

typedef unsigned int TDSQueueNode;
typedef struct _tag_DSQueue
{
	int capacity;
	int length;
	int front;
	int rear;
	TDSQueueNode* node; 		
}TDSQueue;

DSQueue* DSQueue_Create(int capacity);		//创建队列 

void DSQueue_Destroy(DSQueue* queue);		//销毁队列 

void DSQueue_Clear(DSQueue* queue);		//清空队列 

int DSQueue_Append(DSQueue* queue, void* item);			//如队列 

void* DSQueue_Retrieve(DSQueue* queue);			//出队列 

void* DSQueue_Header(DSQueue* queue);		//获取队列头 

int DSQueue_Length(DSQueue* queue);		//获取队列长度 

int DSQueue_Capacity(DSQueue* queue);		//获取队列容量


#endif


