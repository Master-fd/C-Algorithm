/******************************************************************************
**文件名: main.c
**功能： 顺序链表实现相关函数的测试 
**作者： 朱飞东 
**QQ： 1003768663
**时间: 2014.9.20
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"


int main(int argc, char *argv[]) 
{
	SeqList* list = SeqList_Create(5);
    
    int i = 0;
    int j = 1;
    int k = 2;
    int x = 3;
    int y = 4;
    int z = 5;
    int index = 0;
    
    SeqList_Insert(list, &i, 0);
    SeqList_Insert(list, &j, 0);
    SeqList_Insert(list, &k, 0);
    SeqList_Insert(list, &x, 0);
    SeqList_Insert(list, &y, 0);
    SeqList_Insert(list, &z, 0);
   
    for(index=0; index<SeqList_Length(list); index++)
    {
        int* p = (int*)SeqList_Get(list, index);
        
        printf("%d\n", *p);
    }
    
    printf("\n");
    
    while( SeqList_Length(list) > 0 )
    {
        int* p = (int*)SeqList_Delete(list, 0);
        
        printf("%d\n", *p);
    }
    
    SeqList_Destroy(list);
	
	return 0;
}
