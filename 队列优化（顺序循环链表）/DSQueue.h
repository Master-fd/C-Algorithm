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

DSQueue* DSQueue_Create(int capacity);		//�������� 

void DSQueue_Destroy(DSQueue* queue);		//���ٶ��� 

void DSQueue_Clear(DSQueue* queue);		//��ն��� 

int DSQueue_Append(DSQueue* queue, void* item);			//����� 

void* DSQueue_Retrieve(DSQueue* queue);			//������ 

void* DSQueue_Header(DSQueue* queue);		//��ȡ����ͷ 

int DSQueue_Length(DSQueue* queue);		//��ȡ���г��� 

int DSQueue_Capacity(DSQueue* queue);		//��ȡ��������


#endif


