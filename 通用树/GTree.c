/**************************************************************************
**�ļ�����GTree.c
**���ܣ�ͨ�����ṹ��ع��ܺ���ʵ�� 
**���ߣ���ɶ�
**QQ�� 1003768663
**���ڣ�2014.10.8
**��ע��ֻ��������Ĳ���ڵ�ʹ����ͱ�������������δ���
**************************************************************************/ 
/**ԭ��ͨ�����ṹ������һ����֯�������ڵ㣬ÿ�����ڵ����
��ָ�룺һ�����ڵ���һ����ָ�룬ָ����һ�����ڵ� 
����ָ�룺 һ�����ڵ��ж�����ӣ����Ժ���ָ����һ������ÿ������ڵ�ָ����һ�����ڵ� 
���ݣ� �����ڸ����ڵ������
��֯����������򣺱���ÿһ�����ڵ�ĵ�ַ
****************************************************************************/ 



#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"
#include "GTree.h"


typedef struct _tag_GTreeNode GTreeNode;		//���ڵ� 
struct _tag_GTreeNode
{
	GTreeData* data;			//�����򣬱����������ݵ�ַ 
	GTreeNode* parent;			//���游�ڵ�ĵ�ַ 
	LinkList* child;			//��������,���溢�ӵĵ�ַ 
};
typedef struct _tag_TLNode TLNode; 		//��֯����ڵ� 
struct _tag_TLNode 
{
	LinkListNode* header;
	GTreeNode* node;			//�������Ǳ������ڵ�ĵ�ַ 
};


GTree* GTree_Create(void)		//������ 
{
	return LinkList_Create();		//�൱�ڴ���һ����֯���� 
}
void GTree_Destroy(GTree* tree)	//������ 
{
	GTree_Clear(tree);
	LinkList_Destroy(tree);
}
void GTree_Clear(GTree* tree)	//����� 
{
	
}
/****************************************************************************
**��������GTree_Insert 
**���ܣ��������ڵ� 
** ԭ���������ڵ㣬λ����Ҫ����֯����ǰ������ 
****************************************************************************/ 
int GTree_Insert(GTree* tree, GTreeData* data, int pPos)		//�������ڵ�
{
	LinkList* list = (LinkList*)tree;		//��֯����
	int ret = (list != NULL) && (data != NULL) && (pPos < LinkList_Length(list));	//�жϺϷ��� 
	 
	if(ret)
	{
		TLNode* trNode = (TLNode*)malloc(sizeof(TLNode));		//�����ַ��������֯������
		TLNode* cldNode = (TLNode*)malloc(sizeof(TLNode)); 		//�����ַ�����ڸ��ڵ�ĺ�������
		TLNode* pNode = (TLNode*)LinkList_Get(list, pPos);		//����֯�����ȡ���ڵ�
		GTreeNode* cNode = (GTreeNode*)malloc(sizeof(GTreeNode));	//Ϊ���ڵ�����ռ�  	
		
		ret = (trNode != NULL) && (cldNode != NULL) && (cNode);
		
		if(ret)
		{
			cNode->data = data;
			cNode->parent = NULL;					//���ڵ���ʱΪ��	
			cNode->child = LinkList_Create();		//�������� 
			
			trNode->node = cNode;		//��֯���������򱣴����ڵ��ַ 
			cldNode->node = cNode;		//���ڵ�ĺ������������ڵ� 
			
			LinkList_Insert(list, (LinkListNode*)trNode, LinkList_Length(list));	//����֯����������� 
			
			if(pNode != NULL)	//���Ǹ��ڵ㣬���ڵ���û�и��ڵ��
			{
				cNode->parent = pNode->node;	//��������ڵ㸸ָ���򱣴游�ڵ��ַ
				
				LinkList_Insert(pNode->node->child, (LinkListNode*)cldNode, LinkList_Length(pNode->node->child));	//����֯����������� 	
			} 
		}
		else
		{
			free(trNode);
			free(cldNode);
			free(cNode);	
		}	
	}
	
	return ret; 
}
/********************************************************************************************
**��������recursive_display
**���ܣ� ���ı������ݹ���� 
**��������� node���ڵ㣬pFunc����ӡ������ format���� ��gap����������  div�������ַ�
*********************************************************************************************/
static void recursive_display(GTreeNode* node, GTree_Printf* pFunc, int format, int gap, char div)
{
	int i = 0;
	
	if(node != NULL)
	{
		for(i=0; i<format; i++)
		{
			printf("%c", div);	//��ӡ����	
		}
		
		pFunc(node->data);	//���ô�ӡ������ӡ 
		
		printf("\n");
		
		for(i=0; i<LinkList_Length(node->child); i++)		//��ӡ���� 
		{
			TLNode* cNode = (TLNode*)LinkList_Get(node->child, i);	//��ȡ���ӽڵ� 
			
			recursive_display(cNode->node, pFunc, format+gap, gap, div);
		}
	}	
}
void GTree_Display(GTree* tree, GTree_Printf* pFunc, int gap, char div)
{
	TLNode* trNode= (TLNode*)LinkList_Get(tree, 0);
	
	if( (trNode != NULL) && (pFunc != NULL) )
    {
		recursive_display(trNode->node, pFunc, 0, gap, div);
	}
}

