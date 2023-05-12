# UCOSII FOR STM32F401RET6
## 目前进度：
已经完成了相关代码的集成,操作系统运行正常，任务运行正常，任务切换正常
## 项目目录
```txt
.
├── Cfg
│   ├── app_cfg.h
│   ├── app_hooks.c
│   └── os_cfg.h
├── CMakeLists.txt
├── Ports
│   ├── inc
│   │   └── os_cpu.h
│   └── src
│       ├── os_cpu_a.asm
│       └── os_cpu_c.c
├── README.md
├── Source
│   ├── os_core.c
│   ├── os_dbg_r.c
│   ├── os_flag.c
│   ├── os.h
│   ├── os_mbox.c
│   ├── os_mem.c
│   ├── os_mutex.c
│   ├── os_q.c
│   ├── os_sem.c
│   ├── os_task.c
│   ├── os_time.c
│   ├── os_tmr.c
│   ├── os_trace.h
│   └── ucos_ii.h
└── User
    ├── inc
    │   ├── clock_config.h
    │   ├── gpio.h
    │   ├── iic.h
    │   ├── mpu6050.h
    │   ├── NVIC.h
    │   ├── pwm.h
    │   ├── rev.h
    │   ├── stm32f401ret6.h
    │   ├── task.h
    │   └── uart.h
    ├── src
    │   ├── clock_config.c
    │   ├── gpio.c
    │   ├── iic.c
    │   ├── main.c
    │   ├── mpu6050.c
    │   ├── NVIC.c
    │   ├── pwm.c
    │   ├── rev.c
    │   ├── task.c
    │   └── uart.c
    ├── startup_stm32f401xe.s
    └── stm32f401ret6.ld

```
## 如何构建：
```shell
cd cmake-build-debug
cmake ..
make -j
make openocd
``` 