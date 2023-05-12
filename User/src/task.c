//
// Created by lsc on 23-5-9.
//
#include "task.h"
int lll=1000;
void delay_init(void)
{
    SysTick->CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->LOAD = 42000000/OS_TICKS_PER_SEC -1; // 设置重装载值为最大值
    SysTick->VAL = 0; // 清除当前计数值
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                     SysTick_CTRL_TICKINT_Msk   |
                     SysTick_CTRL_ENABLE_Msk;
    NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
}
void TIME_INIT(void) {
    USART_SendStr(USART1,"[SWITCH] First Task\n");
    delay_init();
}
void IMU_TASK(void){
    while(1){
        MPU6050_Read();
        OSTimeDlyHMSM(0,0,0,20);
    }
}

void ULOG_TASK(void){
    char buffer[128];
    while(1){
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"Accel: %f %f %f\n Gyro: %f %f %f\n Temp: %f\n",Ax,Ay,Az,Gx,Gy,Gz,temp);
        USART_SendStr(USART1,buffer);
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"[DATA] raw1: %d\n[DATA] raw2: %d\n[DATA] raw3: %d\n[DATA] raw4: %d\n[DATA] raw5: %d\n[DATA] raw6: %d\n[DATA] raw7: %d\n[DATA] raw8: %d\n",data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8]);
        USART_SendStr(USART1,buffer);
        OSTimeDlyHMSM(0,0,1,0);
    }
}

void MOTOR_TASK(void){
    while(1){
        if(data[7]>1200&&data[7]){
            //遥控器未开启
            PWM_All(1000);
        }
        else if(data[2]==0||3000-data[2]>2000){
            PWM_All(1000);
        }
        else{
            PWM_All(3000-data[2]);
        }
        OSTimeDlyHMSM(0,0,0,20);
    }
}