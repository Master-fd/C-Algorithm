/*****************************************************************************
**文件名：main.c
**功能：单链表实现队列的函数测试 
**作者：朱飞东
**QQ：1003768663
*******************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "LinkQueue.h"


int main(int argc, char *argv[]) 
{
	
	LinkQueue* queue = LinkQueue_Create();
    int a[10] = {0};
    int i = 0;
    
    for(i=0; i<10; i++)
    {
        a[i] = i + 1;
        
        LinkQueue_Append(queue, a + i);
    }
    
    printf("Header: %d\n", *(int*)LinkQueue_Header(queue));
    printf("Length: %d\n", LinkQueue_Length(queue));
    
    while( LinkQueue_Length(queue) > 0 )
    {
        printf("Retrieve: %d\n", *(int*)LinkQueue_Retrieve(queue));
    }
    
    LinkQueue_Destroy(queue);
	
	return 0;
}
