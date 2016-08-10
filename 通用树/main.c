/**************************************************************************
**文件名：GTree.c
**功能：通用树结构相关功能函数的测试 
**作者：朱飞东
**QQ： 1003768663
**日期：2014.10.8

**备注：各功能函数尚未完成，只完成了树的插入节点和创建和遍历，其他的尚未完成 
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
    
	GTree_Insert(tree, (GTreeData*)'A', -1);	//根节点 ，没有父节点，所以-1 
    GTree_Insert(tree, (GTreeData*)'B', 0);		//父节点为根节点 0
    GTree_Insert(tree, (GTreeData*)'C', 0);		//父节点为根节点 0
    GTree_Insert(tree, (GTreeData*)'D', 0);		//父节点为根节点 0
    GTree_Insert(tree, (GTreeData*)'E', 1);		//父节点为B   1
    GTree_Insert(tree, (GTreeData*)'F', 1);		//父节点为B   1
    GTree_Insert(tree, (GTreeData*)'H', 3);		//父节点为D   3
    GTree_Insert(tree, (GTreeData*)'I', 3);		//父节点为D   3
    GTree_Insert(tree, (GTreeData*)'J', 3);		//父节点为D   3
	
	GTree_Display(tree, printf_data, 2, '*');
	 
	return 0;
}
