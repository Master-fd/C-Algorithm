/*****************************************************************************
**文件名：main.c 
**功能：利用单链表实现栈功能 
**作者：朱飞东 
**QQ：1003768663
**日期：2014.9.24
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
 
int* stack = NULL;
int main(int argc, char *argv[])
{
	int v1 = 1;
	int v2 = 2;
	int v3 = 3;
	int v4 = 4;
	int v5 = 5;
	int v6 = 6;
	
	stack = LinkStack_Create();       //创建栈 

	LinkStack_Push(stack, v1);     //压入栈 
	LinkStack_Push(stack, v2);     //压入栈 
	LinkStack_Push(stack, v3);     //压入栈 
	LinkStack_Push(stack, v4);     //压入栈 
	LinkStack_Push(stack, v5);     //压入栈 
	LinkStack_Push(stack, v6);     //压入栈 
	
	printf("Stack pop1 = %d\n", LinkStack_Pop(stack));            //弹出栈 
	printf("Stack pop2 = %d\n", LinkStack_Pop(stack));
	printf("Stack pop3 = %d\n", LinkStack_Pop(stack));
	printf("Stack pop4 = %d\n", LinkStack_Pop(stack));
	
	printf("Stack length = %d\n", LinkStack_Length(stack));      //读取栈长度 	

	printf("Stack top = %d\n", LinkStack_Top(stack));  //读取栈顶 	
	
	LinkStack_Destroy(stack);       //销毁栈 

	return 0;
}
