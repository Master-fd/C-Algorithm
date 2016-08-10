/**********************************************************************
**文件名：LinkSatck.c 
**功能：利用单链表实现栈功能的相关函数 
**作者：朱飞东 
**QQ：1003768663
**日期：2014.9.24
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "LinkStack.h"


typedef struct _tag_LinkStackNode
{
	LinkListNode header;
	void* item;
}TLinkStackNode;



/*********************************************************************
**函数名：LinkStack_Create
**功能：创建栈 
**输入参数：无 
**输出参数：栈首地址 
*********************************************************************/ 
LinkStack* LinkStack_Create()      //创建栈 
{
	return LinkList_Create();         //创建单链表 
}
/*********************************************************************
**函数名：LinkStack_Destroy   
**功能：销毁栈 
**输入参数：LinkStack* stack ： 栈名 
**输出参数：无 
*********************************************************************/ 
void LinkStack_Destroy(LinkStack* stack)      //销毁栈 
{
	LinkStack_Clear(stack);       //清空栈 
	LinkList_Destroy(stack);      //销毁 
}
/*********************************************************************
**函数名：LinkStack_Clear   
**功能：清空栈 
**输入参数：栈名 
**输出参数：无 
*********************************************************************/ 
void LinkStack_Clear(LinkStack* stack)     //清空栈 
{
	while(LinkList_Length(stack) > 0)
	{
		LinkStack_Pop(stack);   //先把所有的都弹出 
	}
	
	LinkList_Clear(stack);  
}
/*********************************************************************
**函数名：LinkStack_Length 
**功能：读取栈长度 
**输入参数：栈名 
**输出参数：返回栈长度 
*********************************************************************/ 
int LinkStack_Length(LinkStack* stack)
{
	return LinkList_Length(stack);
}
/*********************************************************************
**函数名：LinkStack_Push  
**功能：压入栈
**输入参数：栈名 
**输出参数： 
*********************************************************************/ 
int LinkStack_Push(LinkStack* stack, void* node)     //压入栈 
{
	TLinkStackNode* data = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));   //分配内存
	int ret = 0;
	
	if((data != NULL) && (node != NULL))
	{
		data->item = node;
		ret = LinkList_Insert(stack, (LinkListNode*)data, LinkList_Length(stack));
	} 
	else
	{
		free(data);       //释放内存,否则会出现内存泄露 
	}
	
	return ret;
}
/*********************************************************************
**函数名：LinkStack_Pop
**功能：弹出栈 
**输入参数：栈名 
**输出参数：弹出的数据 
*********************************************************************/ 
void* LinkStack_Pop(LinkStack* stack)            //弹出栈 
{
	TLinkStackNode* node = (TLinkStackNode*)LinkList_Delete(stack, LinkList_Length(stack) - 1);  
	void* ret = NULL;
	
	if(node != NULL)
	{
		ret = node->item;
		free(node);
	}
	
	return ret; 
}
/*********************************************************************
**函数名：LinkStack_Top
**功能：读取栈顶 
**输入参数：栈名 
**输出参数：返回栈顶数据 
*********************************************************************/ 
void* LinkStack_Top(LinkStack* stack)   //读取栈顶 
{
	TLinkStackNode* node = (TLinkStackNode*)LinkList_Get(stack, LinkList_Length(stack) - 1);  
	void* ret = NULL;
	
	if(node != NULL)
	{
		ret = node->item;
	}
	
	return ret;       //读取节点 
}


