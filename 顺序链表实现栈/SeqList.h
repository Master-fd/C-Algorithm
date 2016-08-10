#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;


SeqList* SeqList_Create(int capacity);       //创建顺序链表

void SeqList_Destroy(SeqList* list);       //销毁链表 

void SeqList_Clear(SeqList* list);     //清空链表 

int SeqList_Length(SeqList* list);      //读取链表长度 
 
int SeqList_Capacity(SeqList* list);      //捕获链表容量 

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);     //插入节点 

SeqListNode* SeqList_Get(SeqList* list, int pos);            //读取节点数据 

SeqListNode* SeqList_Delete(SeqList* list, int pos);    //删除节点 







#endif

