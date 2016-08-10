#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_


typedef void SeqQueue;
typedef void SeqQueueNode;


SeqQueue *SeqQueue_Create(int capacity);           //��������

void SeqQueue_Destroy(SeqQueue *queue);		//���ٶ���

void SeqQueue_Clear(SeqQueue *queue);		//��ն��� 

int SeqQueue_Append(SeqQueue *queue, SeqQueueNode *node);			//����� 

void *SeqQueue_Retrieve(SeqQueue *queue);		//������ 

void *SeqQueue_Header(SeqQueue *queue);			//��ȡ����ͷ���� 

int SeqQueue_Length(SeqQueue *queue);			//���г��� 

int SeqQueue_Capacity(SeqQueue *queue);			//��ȡ�������� 


#endif

