/***************************************************************************
**�ļ�����main.c
**���ܣ�ѡ������Ĳ��������� 
**���ߣ���ɶ� 
**QQ��1003768663
**���ڣ�2014.10.7
***************************************************************************/
 

#include <stdio.h>
#include <stdlib.h>
#include "SelectSort.h"



int main(int argc, char *argv[]) 
{
	int array[] = {2,8,2,19,4,3,8,56,7,45,11};
	int i = 0;
	
	SelectSort(array,sizeof(array)/sizeof(array[0]));
	
	for(i=0; i<sizeof(array)/sizeof(array[0]); i++)
	{
		printf("%d ",array[i]);	
	}
	
	return 0;
}
