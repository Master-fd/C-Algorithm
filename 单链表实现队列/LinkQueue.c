/*****************************************************************************
**文件名：LinkQueue.c
**功能：队列相关函数的实现 
**作者：朱飞东
**QQ：1003768663
*******************************************************************************/ 
#include <malloc.h>
#include "LinkList.h"
#include "LinkQueue.h"

//定义一个现在使用的节点类型 
typedef struct _tag_TLinkQueueNode
{
	LinkQueueNode header;
	void* item;
}TLinkQueueNode;


LinkQueue *LinkQueue_Create(void)          //创建队列
{
	return LinkList_Create(); 	
}
void LinkQueue_Destroy(LinkQueue *queue)		//销毁队列
{
	LinkQueue_Clear(queue);			//需要先清空队列,避免内存泄露 
	LinkList_Destroy(queue);
}
void LinkQueue_Clear(LinkQueue *queue)		//清空队列 
{
	while(LinkQueue_Length(queue))	
	{
		LinkQueue_Retrieve(queue);	//先把全部出列，避免内存泄露 
	}
	
	LinkList_Clear(queue);		//清空,即恢复长度等为初始状态 	
}
/*****************************************************************
**函数名：LinkQueue_Append
**输入参数：item：数据地址(数据地址：不包括指针域),函数内部会分配空间
				里面有指针域 
**输出参数：1，入队成功，0 失败
**功能:往队列里面入队一个数据 
*****************************************************************/
int LinkQueue_Append(LinkQueue *queue, LinkQueueNode *item)			//入队列 
{
	TLinkQueueNode *node = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));		
	//定义一个节点,同时在堆里面分配空间 
	int ret = (item != NULL) && (queue != NULL) && (node != NULL);
	
	if( ret )
	{
		node->item = item;	//节点的数据部分就是入队列数据的地址 
		
		LinkList_Insert(queue, node, LinkList_Length(queue));
	}
	else
	{
		free(node);	//失败，则释放分配的内存空间 
	}
	
	return ret; 
}
/*****************************************************************
**函数名：*LinkQueue_Retrieve
**输入参数：queue:队列名 
**输出参数：输出出队列数据的地址(数据地址：不包括指针域)
**功能:出队列 
*****************************************************************/
LinkQueueNode *LinkQueue_Retrieve(LinkQueue *queue)		//出队列 
{
	TLinkQueueNode *node = (TLinkQueueNode*)LinkList_Delete(queue, 0);
	void *ret = NULL;
	
	if(node != NULL)
	{
		ret = node->item;	//
		
		free(node);	//释放内存 
	}
	
	return ret; 
}
/*****************************************************************
**函数名：*LinkQueue_Header
**输入参数：queue:队列名 
**输出参数：队列第0个数据地址(数据地址：不包括指针域)
**功能:输出队列第0个数据地址 
*****************************************************************/
LinkQueueNode *LinkQueue_Header(LinkQueue *queue)			//获取队列头数据 
{
	TLinkQueueNode *node = (TLinkQueueNode*)LinkList_Get(queue, 0);
	void *ret = NULL;
	
	if(node != NULL)
	{
		ret = node->item;	//
	}
	
	return ret; 
}
int LinkQueue_Length(LinkQueue *queue)		//队列长度 
{
	return LinkList_Length(queue);
}


