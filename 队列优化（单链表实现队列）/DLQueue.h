#ifndef _DLQUEUE_H_
#define _DLQUEUE_H_



typedef void DLQueue;
typedef struct _tag_DLQueueNode TDLQueueNode;	 
struct _tag_DLQueueNode					//������ڵ�����
{
	TDLQueueNode *next;
	void *item;	
};
typedef struct _tag_DLQueue		//����һ���������� 
{
	TDLQueueNode *front;
	TDLQueueNode *rear;
	int length;
}TDLQueue;

DLQueue* DLQueue_Create(void);		//�������� 

void DLQueue_Destroy(DLQueue* queue);		//���ٶ��� 

void DLQueue_Clear(DLQueue* queue);		//��ն��� 

int DLQueue_Append(DLQueue* queue, void* item);			//����� 

void* DLQueue_Retrieve(DLQueue* queue);			//������ 

void* DLQueue_Header(DLQueue* queue);		//��ȡ����ͷ 

int DLQueue_Length(DLQueue* queue);		//��ȡ���г��� 


#endif


