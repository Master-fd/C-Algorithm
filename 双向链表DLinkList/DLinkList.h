#ifndef _DLINK_LIST_H_
#define _DLINK_LIST_H_


typedef void DLinkList;
typedef struct _tag_DLinkListNode DLinkListNode;
/*struct _tag_DLinkListNode
{
	DLinkListNode* next;
	DLinkListNode* pre;
};*/
struct _tag_DLinkListNode
{
	void* next;
	void* pre;
};

DLinkList* DLinkList_Create();         //����˫������ 

void DLinkList_Destroy(DLinkList* list);     //���ٵ����� 

void DLinkList_Clear(DLinkList* list);      //��յ����� 

int DLinkList_Length(DLinkList* list);       //��ȡ�������� 

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);      //����ڵ� 

DLinkListNode* DLinkList_Get(DLinkList* list, int pos);       //��ȡ�ڵ� 

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);        //ɾ���ڵ� 

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node); //ɾ���ڵ�

DLinkListNode* DLinkList_Reset(DLinkList* list);    //��λ�α�

DLinkListNode* DLinkList_Current(DLinkList* list);  //��ǰ�α� �ڵ�

DLinkListNode* DLinkList_Next(DLinkList* list); //��һ���α�ڵ� 

DLinkListNode* DLinkList_Pre(DLinkList* list);     //ǰһ���α� �ڵ�


#endif
