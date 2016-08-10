#ifndef _DLQUEUE_H_
#define _DLQUEUE_H_



typedef void DLQueue;
typedef struct _tag_DLQueueNode TDLQueueNode;	 
struct _tag_DLQueueNode					//定义个节点类型
{
	TDLQueueNode *next;
	void *item;	
};
typedef struct _tag_DLQueue		//定义一个队列类型 
{
	TDLQueueNode *front;
	TDLQueueNode *rear;
	int length;
}TDLQueue;

DLQueue* DLQueue_Create(void);		//创建队列 

void DLQueue_Destroy(DLQueue* queue);		//销毁队列 

void DLQueue_Clear(DLQueue* queue);		//清空队列 

int DLQueue_Append(DLQueue* queue, void* item);			//如队列 

void* DLQueue_Retrieve(DLQueue* queue);			//出队列 

void* DLQueue_Header(DLQueue* queue);		//获取队列头 

int DLQueue_Length(DLQueue* queue);		//获取队列长度 


#endif


