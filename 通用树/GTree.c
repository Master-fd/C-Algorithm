/**************************************************************************
**文件名：GTree.c
**功能：通用树结构相关功能函数实现 
**作者：朱飞东
**QQ： 1003768663
**日期：2014.10.8
**备注：只完成了树的插入节点和创建和遍历，其他的尚未完成
**************************************************************************/ 
/**原理：通用树结构，含有一个组织链表，树节点，每个树节点包含
父指针：一个树节点有一个父指针，指向上一个树节点 
孩子指针： 一个树节点有多个孩子，所以孩子指针是一个链表，每个链表节点指向下一个树节点 
数据： 保存在该树节点的数据
组织链表的数据域：保存每一个树节点的地址
****************************************************************************/ 



#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"
#include "GTree.h"


typedef struct _tag_GTreeNode GTreeNode;		//树节点 
struct _tag_GTreeNode
{
	GTreeData* data;			//数据域，保存树的数据地址 
	GTreeNode* parent;			//保存父节点的地址 
	LinkList* child;			//孩子链表,保存孩子的地址 
};
typedef struct _tag_TLNode TLNode; 		//组织链表节点 
struct _tag_TLNode 
{
	LinkListNode* header;
	GTreeNode* node;			//数据域即是保存树节点的地址 
};


GTree* GTree_Create(void)		//创建树 
{
	return LinkList_Create();		//相当于创建一个组织链表 
}
void GTree_Destroy(GTree* tree)	//销毁树 
{
	GTree_Clear(tree);
	LinkList_Destroy(tree);
}
void GTree_Clear(GTree* tree)	//清空树 
{
	
}
/****************************************************************************
**函数名：GTree_Insert 
**功能：增加树节点 
** 原理：插入树节点，位置需要在组织链表当前长度内 
****************************************************************************/ 
int GTree_Insert(GTree* tree, GTreeData* data, int pPos)		//插入树节点
{
	LinkList* list = (LinkList*)tree;		//组织链表
	int ret = (list != NULL) && (data != NULL) && (pPos < LinkList_Length(list));	//判断合法性 
	 
	if(ret)
	{
		TLNode* trNode = (TLNode*)malloc(sizeof(TLNode));		//这个地址保存在组织链表里
		TLNode* cldNode = (TLNode*)malloc(sizeof(TLNode)); 		//这个地址保存在父节点的孩子链表
		TLNode* pNode = (TLNode*)LinkList_Get(list, pPos);		//从组织链表获取父节点
		GTreeNode* cNode = (GTreeNode*)malloc(sizeof(GTreeNode));	//为树节点申请空间  	
		
		ret = (trNode != NULL) && (cldNode != NULL) && (cNode);
		
		if(ret)
		{
			cNode->data = data;
			cNode->parent = NULL;					//父节点暂时为空	
			cNode->child = LinkList_Create();		//孩子链表 
			
			trNode->node = cNode;		//组织链表数据域保存树节点地址 
			cldNode->node = cNode;		//父节点的孩子链表保存树节点 
			
			LinkList_Insert(list, (LinkListNode*)trNode, LinkList_Length(list));	//在组织链表里面插入 
			
			if(pNode != NULL)	//不是根节点，根节点是没有父节点的
			{
				cNode->parent = pNode->node;	//插入的树节点父指针域保存父节点地址
				
				LinkList_Insert(pNode->node->child, (LinkListNode*)cldNode, LinkList_Length(pNode->node->child));	//在组织链表里面插入 	
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
**函数名：recursive_display
**功能： 树的遍历，递归调用 
**输入参数： node树节点，pFunc：打印函数， format缩进 ，gap：缩进格数  div：缩进字符
*********************************************************************************************/
static void recursive_display(GTreeNode* node, GTree_Printf* pFunc, int format, int gap, char div)
{
	int i = 0;
	
	if(node != NULL)
	{
		for(i=0; i<format; i++)
		{
			printf("%c", div);	//打印缩进	
		}
		
		pFunc(node->data);	//调用打印函数打印 
		
		printf("\n");
		
		for(i=0; i<LinkList_Length(node->child); i++)		//打印孩子 
		{
			TLNode* cNode = (TLNode*)LinkList_Get(node->child, i);	//获取孩子节点 
			
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

