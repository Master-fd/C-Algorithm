/******************************************************************************
**文件名：main.c
**功能：顺序表实现队列 
**作者：朱飞东 
**QQ：1003768663
******************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"
#include "SeqQueue.h"

int *queue = NULL;


int main(int argc, char *argv[])
{
	int v1 = 1;
	int v2 = 2;
	int v3 = 3;
	int v4 = 4;
	int v5 = 5;
	
	
	queue = (int*)SeqQueue_Create(100);           //创建队列

	SeqQueue_Append(queue, &v1);			//入队列 
	SeqQueue_Append(queue, &v2);			//入队列
	SeqQueue_Append(queue, &v3);			//入队列
	SeqQueue_Append(queue, &v4);			//入队列
	SeqQueue_Append(queue, &v5);			//入队列
	

	printf("The Queue:%d\n",*(int*)SeqQueue_Retrieve(queue));		//出队列 
	printf("The Queue:%d\n",*(int*)SeqQueue_Retrieve(queue));		//出队列 
	printf("The Queue:%d\n",*(int*)SeqQueue_Retrieve(queue));		//出队列 
	
	printf("The Queue Header:%d\n",*(int*)SeqQueue_Header(queue));			//获取队列头数据 

	printf("The Queue Length:%d\n",SeqQueue_Length(queue));			//队列长度 

	printf("The Queue Capacity:%d\n",SeqQueue_Capacity(queue));			//获取队列容量 

	SeqQueue_Destroy(queue);		//销毁队列
	
	
	return 0;
}
