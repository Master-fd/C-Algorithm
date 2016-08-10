#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_


typedef void LinkQueue;
typedef struct _tag_LinkQueueNode LinkQueueNode;
struct _tag_LinkQueueNode
{
	LinkQueueNode *next;
};


LinkQueue *LinkQueue_Create(void);           //创建队列

void LinkQueue_Destroy(LinkQueue *queue);		//销毁队列

void LinkQueue_Clear(LinkQueue *queue);		//清空队列 

int LinkQueue_Append(LinkQueue *queue, LinkQueueNode *node);			//入队列 

LinkQueueNode *LinkQueue_Retrieve(LinkQueue *queue);		//出队列 

LinkQueueNode *LinkQueue_Header(LinkQueue *queue);			//获取队列头数据 

int LinkQueue_Length(LinkQueue *queue);			//队列长度 



#endif

