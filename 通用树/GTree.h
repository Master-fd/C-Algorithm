#ifndef _GTREE_H_
#define _GTREE_H_



typedef void GTree;
typedef void GTreeData;
typedef void (GTree_Printf)(GTreeData*);

GTree* GTree_Create(void);		//创建树 

void GTree_Destroy(GTree* tree);	//销毁树 

void GTree_Clear(GTree* tree);	//清空树 

int GTree_Insert(GTree* tree, GTreeData* data, int pPos);		//插入树节点

void GTree_Display(GTree* tree, GTree_Printf* pFunc, int gap, char div);		//遍历树 
 
#endif


