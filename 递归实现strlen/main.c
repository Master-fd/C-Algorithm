/*****************************************************************************
**�ļ�����main.c
**���ܣ����õݹ�,���ڵ��ú�����ʱ��ջ�ᱣ�溯����¼,ʵ�ֲ����ַ������� 
**���ߣ���ɶ� 
**QQ��1003768663
**���ڣ�2014.9.24
*****************************************************************************/ 
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/************************************************
**�ݹ鷽ʽʵ�ֲ���
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
**���淽��ʵ�ֲ����ַ���
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
