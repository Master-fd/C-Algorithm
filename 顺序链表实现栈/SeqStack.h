#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);       //创建栈 

void SeqStack_Destroy(SeqStack* stack);       //销毁栈 

void SeqStack_Clear(SeqStack* stack);     //清空栈 

int SeqStack_Length(SeqStack* stack);      //读取栈长度 
 
int SeqStack_Capacity(SeqStack* stack);      //捕获栈容量 

int SeqStack_Push(SeqStack* stack, void* node);     //压入栈 

void* SeqStack_Pop(SeqStack* stack);            //弹出栈 

void* SeqStack_Top(SeqStack* stack);  //读取栈顶 




#endif


