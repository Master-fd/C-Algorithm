#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);       //����ջ 

void SeqStack_Destroy(SeqStack* stack);       //����ջ 

void SeqStack_Clear(SeqStack* stack);     //���ջ 

int SeqStack_Length(SeqStack* stack);      //��ȡջ���� 
 
int SeqStack_Capacity(SeqStack* stack);      //����ջ���� 

int SeqStack_Push(SeqStack* stack, void* node);     //ѹ��ջ 

void* SeqStack_Pop(SeqStack* stack);            //����ջ 

void* SeqStack_Top(SeqStack* stack);  //��ȡջ�� 




#endif


