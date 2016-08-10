#ifndef _GTREE_H_
#define _GTREE_H_



typedef void GTree;
typedef void GTreeData;
typedef void (GTree_Printf)(GTreeData*);

GTree* GTree_Create(void);		//������ 

void GTree_Destroy(GTree* tree);	//������ 

void GTree_Clear(GTree* tree);	//����� 

int GTree_Insert(GTree* tree, GTreeData* data, int pPos);		//�������ڵ�

void GTree_Display(GTree* tree, GTree_Printf* pFunc, int gap, char div);		//������ 
 
#endif


