//
// Created by lsc on 23-6-30.
//
#include "QLMonitor.h"
int TickNum=0;
int maxTick=0;
char buffer[32];
char finnal[2048];
extern OS_TCB *prevTask,*nextTask;
int max(int a ,int b){
    return a>b?a:b;
}
void SetTickNum(int Tick){
    TickNum = Tick;
    maxTick = max(Tick,maxTick);
    if(TickNum == maxTick){
//        USART_SendStr(USART1,"fullTick\n");
    }
}
void StoreSwInfo(){
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"Tick: %d Task %s end\n",TickNum,prevTask->OSTCBTaskName);
    strcat(finnal,buffer);

    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"Tick: %d Task %s begin\n",TickNum,nextTask->OSTCBTaskName);
    strcat(finnal,buffer);
}
void SendSwInfo(){
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"Tick: %d Task %s end\n",TickNum,prevTask->OSTCBTaskName);
    USART_SendStr(USART1,buffer);

    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"Tick: %d Task %s begin\n",TickNum,nextTask->OSTCBTaskName);
    USART_SendStr(USART1,buffer);
}