/*********************************************************************************
**文件名：main.c
**功能：找出一定范围内的所有素数相关函数实现 
**作者：朱飞东 
**QQ ：1003768663
**日期：2014.10.8
*********************************************************************************/ 

#include <math.h>
#include <stdio.h>
#include "PriNum.h"

//求100以内的所有素数 
void PriNum100(int *basepri)
{
	char flag = 0;
	int i = 0, j = 0, k = 0;
	
	for(i=2; i<= 100; i++)   //利用10以内的素数,求出100以内的所有素数 
	{
		flag = 1;
		
		for(j=0; j<4; j++)	//每个数都除以这里面的素数 
		{
			if((i%basepri[j] == 0) && (i!= basepri[j]))	//可以整除,不是素数 
			{
				flag = 0;
				break;	
			}	
		}
		if(flag)
		{
			basepri[k] = i;  //依次保存素数 
			k++;
			//printf("%d\n", i);
		}
	}
}
void PriNum10000()
{
	char flag = 0;
	int i = 0, j = 0, k = 0;
	int basepri[50] = {2,3,5,7};   //10以内的所有素数
	int basepri1[5000] = {0};
	int count = 0;
	
	PriNum100(basepri);	//先求出100以内的素数 
	while(basepri[count] > 0)
	{
		count++;
	}
	
	printf("100yinei:%d",count);
	
	for(i=101; i<= 10000; i++)   //利用100以内的素数,求出10000以内的所有素数 
	{
		flag = 1;
		
		for(j=0; j<count; j++)	//每个数都除以这里面的素数 
		{
			if((i%basepri[j] == 0) && (i!= basepri[j]))	//可以整除,不是素数 
			{
				flag = 0;
				break;	
			}	
		}
		if(flag)
		{
			basepri1[k] = i;  //依次保存101--10000的素数 
			k++;
			printf("%d\n", i);
		}
	}
}


