/*****************************************************************************
**文件名：main.c
**功能：利用递归,即在调用函数的时候栈会保存函数记录,实现测量字符串长度 
**作者：朱飞东 
**QQ：1003768663
**日期：2014.9.24
*****************************************************************************/ 
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/************************************************
**递归方式实现测量
****************************************/ 
int strlenn(const char *s)
{	
	static int a = 0;
	
	if(s == NULL)
	{
		return -1;
	}
	else
	{
		if(*s == '\0')
		{
			printf("%s \n", "end");
			return 0;
		}
		else
		{
			
			s++;
			printf("%s \n", s);
			strlenn(s);
			
			printf("%s \n", s);
			a++;
			return a;
		}	
	}
} 
/*******************************************************************
**常规方法实现测量字符串
*******************************************************************/ 
/*int strlenn(const char *s)
{
	int a = 0;
	
	while((s != NULL) && (*s != '\0'))
	{
		s++;
		a++;	
	}

	return a;
} */
int main(int argc, char *argv[]) 
{
	printf("strlenn = %d\n", strlenn("ABSDS"));
	printf("strlen(NULL) = %d\n", strlenn(NULL));
	printf("strlen(\"\") = %d\n", strlenn(""));
	return 0;
}
