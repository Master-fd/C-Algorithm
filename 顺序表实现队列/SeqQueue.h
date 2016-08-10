#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_


typedef void SeqQueue;
typedef void SeqQueueNode;


SeqQueue *SeqQueue_Create(int capacity);           //创建队列

void SeqQueue_Destroy(SeqQueue *queue);		//销毁队列

void SeqQueue_Clear(SeqQueue *queue);		//清空队列 

int SeqQueue_Append(SeqQueue *queue, SeqQueueNode *node);			//入队列 

void *SeqQueue_Retrieve(SeqQueue *queue);		//出队列 

void *SeqQueue_Header(SeqQueue *queue);			//获取队列头数据 

int SeqQueue_Length(SeqQueue *queue);			//队列长度 

int SeqQueue_Capacity(SeqQueue *queue);			//获取队列容量 


#endif

