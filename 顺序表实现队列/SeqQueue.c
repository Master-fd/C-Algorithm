/*****************************************************************************
**�ļ�����SeqQueue.c
**���ܣ�˳���ʵ�ֶ��е���غ��� 
**���ߣ���ɶ� 
**QQ��1003768663
*****************************************************************************/
#include "SeqList.h"
#include "SeqQueue.h"


SeqQueue *SeqQueue_Create(int capacity)        //��������
{
	return SeqList_Create(capacity);
}
void SeqQueue_Destroy(SeqQueue *queue)	//���ٶ���
{
	SeqList_Destroy(queue);
}
void SeqQueue_Clear(SeqQueue *queue)		//��ն��� 
{
	SeqList_Clear(queue);
}
int SeqQueue_Append(SeqQueue *queue, SeqQueueNode *node)			//����� 
{
	SeqList_Insert(queue, node, SeqList_Length(queue));
}
void *SeqQueue_Retrieve(SeqQueue *queue)		//������ 
{
	SeqList_Delete(queue, 0);
}
void *SeqQueue_Header(SeqQueue *queue)			//��ȡ����ͷ���� 
{
	SeqList_Get(queue, 0);
}
int SeqQueue_Length(SeqQueue *queue)			//���г��� 
{
	SeqList_Length(queue);
}
int SeqQueue_Capacity(SeqQueue *queue)			//��ȡ�������� 
{
	SeqList_Capacity(queue);
}
 
 
