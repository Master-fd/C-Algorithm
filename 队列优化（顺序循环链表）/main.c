/****************************************************************************
**文件名：main.c
**功能：单链表实现循环队列 
**作者：朱飞东
**日期：2014.10.6
**QQ：1003768663
****************************************************************************/

 
#include <stdio.h>
#include <stdlib.h>
#include "DSQueue.h"


int main(int argc, char *argv[])
{
	
	DSQueue* queue = DSQueue_Create(6);
    int a[10] = {0};
    int i = 0;
    
    for(i=0; i<10; i++)
    {
        a[i] = i + 1;
        
        DSQueue_Append(queue, a + i);
    }
    
    printf("Header: %d\n", *(int*)DSQueue_Header(queue));
    printf("Length: %d\n", DSQueue_Length(queue));
    printf("Capacity: %d\n", DSQueue_Capacity(queue));
    
    while( DSQueue_Length(queue) > 0 )
    {
        printf("Retrieve: %d\n", *(int*)DSQueue_Retrieve(queue));
    }
    
    printf("\n");
    
    for(i=0; i<10; i++)
    {
        a[i] = i + 1;
        
        DSQueue_Append(queue, a + i);

        printf("Retrieve: %d\n", *(int*)DSQueue_Retrieve(queue));
    }
    
    DSQueue_Destroy(queue);
	
		
	return 0;
}



