/**************************************************************************
**�ļ�����GTree.c
**���ܣ�ͨ�����ṹ��ع��ܺ����Ĳ��� 
**���ߣ���ɶ�
**QQ�� 1003768663
**���ڣ�2014.10.8

**��ע�������ܺ�����δ��ɣ�ֻ��������Ĳ���ڵ�ʹ����ͱ�������������δ��� 
**************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include "GTree.h"

void printf_data(GTreeData* data)
{
    printf("%c", (int)data);
}

int main(int argc, char *argv[]) 
{
	GTree* tree = GTree_Create();
    int i = 0;
    
	GTree_Insert(tree, (GTreeData*)'A', -1);	//���ڵ� ��û�и��ڵ㣬����-1 
    GTree_Insert(tree, (GTreeData*)'B', 0);		//���ڵ�Ϊ���ڵ� 0
    GTree_Insert(tree, (GTreeData*)'C', 0);		//���ڵ�Ϊ���ڵ� 0
    GTree_Insert(tree, (GTreeData*)'D', 0);		//���ڵ�Ϊ���ڵ� 0
    GTree_Insert(tree, (GTreeData*)'E', 1);		//���ڵ�ΪB   1
    GTree_Insert(tree, (GTreeData*)'F', 1);		//���ڵ�ΪB   1
    GTree_Insert(tree, (GTreeData*)'H', 3);		//���ڵ�ΪD   3
    GTree_Insert(tree, (GTreeData*)'I', 3);		//���ڵ�ΪD   3
    GTree_Insert(tree, (GTreeData*)'J', 3);		//���ڵ�ΪD   3
	
	GTree_Display(tree, printf_data, 2, '*');
	 
	return 0;
}
