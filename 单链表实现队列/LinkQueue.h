#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_


typedef void LinkQueue;
typedef struct _tag_LinkQueueNode LinkQueueNode;
struct _tag_LinkQueueNode
{
	LinkQueueNode *next;
};


LinkQueue *LinkQueue_Create(void);           //��������

void LinkQueue_Destroy(LinkQueue *queue);		//���ٶ���

void LinkQueue_Clear(LinkQueue *queue);		//��ն��� 

int LinkQueue_Append(LinkQueue *queue, LinkQueueNode *node);			//����� 

LinkQueueNode *LinkQueue_Retrieve(LinkQueue *queue);		//������ 

LinkQueueNode *LinkQueue_Header(LinkQueue *queue);			//��ȡ����ͷ���� 

int LinkQueue_Length(LinkQueue *queue);			//���г��� 



#endif

