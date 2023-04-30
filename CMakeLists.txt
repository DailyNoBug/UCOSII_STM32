cmake_minimum_required(VERSION 3.25)
project(UCOSII C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m3 -mthumb -mlittle-endian -std=gnu99 -g -Wall -Werror")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=cortex-m3 -mthumb -mlittle-endian")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-m3 -mthumb -mlittle-endian -std=c++11 -g -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/STM32F407VG.ld")

include_directories(Cfg)
include_directories(Source)
include_directories(Ports/inc)

set(uCOS-II_SOURCES
        Source/os.h
        Source/os_core.c
        Source/os_dbg_r.c
        Source/os_flag.c
        Source/os_mbox.c
        Source/os_mem.c
        Source/os_mutex.c
        Source/os_q.c
        Source/os_sem.c
        Source/os_task.c
        Source/os_time.c
        Source/os_tmr.c
        Source/os_trace.h
        Source/ucos_ii.c
        Source/ucos_ii.h
        Cfg/Template/app_cfg.h
        Cfg/Template/app_hooks.c
        Cfg/Template/os_cfg.h

        Ports/inc/os_cpu.h
        Ports/src/os_dbg.c
        )
set(USER_SOURCES
        User/main.c
        )

add_library(uCOS-II STATIC ${uCOS-II_SOURCES})
add_executable(ucosii ${USER_SOURCES})
target_link_libraries(ucosii uCOS-II)
#target_link_libraries(app ${CMAKE_CURRENT_SOURCE_DIR}/startup_stm32f407xx.s)
