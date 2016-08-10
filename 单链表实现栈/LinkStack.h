#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef void LinkStack;

LinkStack* LinkStack_Create();       //����ջ 

void LinkStack_Destroy(LinkStack* stack);       //����ջ 

void LinkStack_Clear(LinkStack* stack);     //���ջ 

int LinkStack_Length(LinkStack* stack);      //��ȡջ���� 
 
int LinkStack_Push(LinkStack* stack, void* node);     //ѹ��ջ 

void* LinkStack_Pop(LinkStack* stack);            //����ջ 

void* LinkStack_Top(LinkStack* stack);  //��ȡջ�� 





#endif

