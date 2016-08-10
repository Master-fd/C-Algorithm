/******************************************************************************
**�ļ�����main.c
**���ܣ�˳���ʵ�ֶ��� 
**���ߣ���ɶ� 
**QQ��1003768663
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
	
	
	queue = (int*)SeqQueue_Create(100);           //��������

	SeqQueue_Append(queue, &v1);			//����� 
	SeqQueue_Append(queue, &v2);			//�����
	SeqQueue_Append(queue, &v3);			//�����
	SeqQueue_Append(queue, &v4);			//�����
	SeqQueue_Append(queue, &v5);			//�����
	

	printf("The Queue:%d\n",*(int*)SeqQueue_Retrieve(queue));		//������ 
	printf("The Queue:%d\n",*(int*)SeqQueue_Retrieve(queue));		//������ 
	printf("The Queue:%d\n",*(int*)SeqQueue_Retrieve(queue));		//������ 
	
	printf("The Queue Header:%d\n",*(int*)SeqQueue_Header(queue));			//��ȡ����ͷ���� 

	printf("The Queue Length:%d\n",SeqQueue_Length(queue));			//���г��� 

	printf("The Queue Capacity:%d\n",SeqQueue_Capacity(queue));			//��ȡ�������� 

	SeqQueue_Destroy(queue);		//���ٶ���
	
	
	return 0;
}
