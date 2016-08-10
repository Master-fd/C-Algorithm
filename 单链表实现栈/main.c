/*****************************************************************************
**�ļ�����main.c 
**���ܣ����õ�����ʵ��ջ���� 
**���ߣ���ɶ� 
**QQ��1003768663
**���ڣ�2014.9.24
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
	
	stack = LinkStack_Create();       //����ջ 

	LinkStack_Push(stack, v1);     //ѹ��ջ 
	LinkStack_Push(stack, v2);     //ѹ��ջ 
	LinkStack_Push(stack, v3);     //ѹ��ջ 
	LinkStack_Push(stack, v4);     //ѹ��ջ 
	LinkStack_Push(stack, v5);     //ѹ��ջ 
	LinkStack_Push(stack, v6);     //ѹ��ջ 
	
	printf("Stack pop1 = %d\n", LinkStack_Pop(stack));            //����ջ 
	printf("Stack pop2 = %d\n", LinkStack_Pop(stack));
	printf("Stack pop3 = %d\n", LinkStack_Pop(stack));
	printf("Stack pop4 = %d\n", LinkStack_Pop(stack));
	
	printf("Stack length = %d\n", LinkStack_Length(stack));      //��ȡջ���� 	

	printf("Stack top = %d\n", LinkStack_Top(stack));  //��ȡջ�� 	
	
	LinkStack_Destroy(stack);       //����ջ 

	return 0;
}
