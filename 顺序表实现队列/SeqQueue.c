/*****************************************************************************
**文件名：SeqQueue.c
**功能：顺序表实现队列的相关函数 
**作者：朱飞东 
**QQ：1003768663
*****************************************************************************/
#include "SeqList.h"
#include "SeqQueue.h"


SeqQueue *SeqQueue_Create(int capacity)        //创建队列
{
	return SeqList_Create(capacity);
}
void SeqQueue_Destroy(SeqQueue *queue)	//销毁队列
{
	SeqList_Destroy(queue);
}
void SeqQueue_Clear(SeqQueue *queue)		//清空队列 
{
	SeqList_Clear(queue);
}
int SeqQueue_Append(SeqQueue *queue, SeqQueueNode *node)			//入队列 
{
	SeqList_Insert(queue, node, SeqList_Length(queue));
}
void *SeqQueue_Retrieve(SeqQueue *queue)		//出队列 
{
	SeqList_Delete(queue, 0);
}
void *SeqQueue_Header(SeqQueue *queue)			//获取队列头数据 
{
	SeqList_Get(queue, 0);
}
int SeqQueue_Length(SeqQueue *queue)			//队列长度 
{
	SeqList_Length(queue);
}
int SeqQueue_Capacity(SeqQueue *queue)			//获取队列容量 
{
	SeqList_Capacity(queue);
}
 
 
