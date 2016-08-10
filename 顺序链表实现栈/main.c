/*******************************************************************
**文件名：main.c
**功能：利用顺序链表实现栈 
**作者：朱飞东 
**QQ：1003768663
**日期：2014.9.24
******************************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"
#include "SeqStack.h" 

int *stack;

int main(int argc, char *argv[]) 
{
	int d1 = 1;
	int d2 = 2;
	int d3 = 3;
	int d4 = 4;
	int d5 = 5;
	int d6 = 6;
	
	stack = SeqStack_Create(20);  
	
	SeqStack_Push(stack, d1);     //压入栈 
	SeqStack_Push(stack, d2);
	SeqStack_Push(stack, d3);
	SeqStack_Push(stack, d4);
	SeqStack_Push(stack, d5);
	SeqStack_Push(stack, d6);
	
	printf("stack pop1 = %d\n", SeqStack_Pop(stack));            //弹出栈 
	printf("stack pop2 = %d\n", SeqStack_Pop(stack)); 
	printf("stack pop3 = %d\n", SeqStack_Pop(stack)); 
	printf("stack pop4 = %d\n", SeqStack_Pop(stack)); 
	
	printf("stack length = %d\n", SeqStack_Length(stack));
	printf("stack capacity = %d\n", SeqStack_Capacity(stack));      //捕获栈容量 



	SeqStack_Destroy(stack);
	
	return 0;
}
