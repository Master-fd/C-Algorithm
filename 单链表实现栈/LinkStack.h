#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef void LinkStack;

LinkStack* LinkStack_Create();       //创建栈 

void LinkStack_Destroy(LinkStack* stack);       //销毁栈 

void LinkStack_Clear(LinkStack* stack);     //清空栈 

int LinkStack_Length(LinkStack* stack);      //读取栈长度 
 
int LinkStack_Push(LinkStack* stack, void* node);     //压入栈 

void* LinkStack_Pop(LinkStack* stack);            //弹出栈 

void* LinkStack_Top(LinkStack* stack);  //读取栈顶 





#endif

