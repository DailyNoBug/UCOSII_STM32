cmake_minimum_required(VERSION 3.10)

# 项目名称
project(ucos_stm32 C ASM)

# 添加启动文件
set(STARTUP_FILE ${CMAKE_CURRENT_SOURCE_DIR}/User/startup_stm32f401xe.s)
#添加asm文件
set(ASM_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Ports/src/os_cpu_a.asm)
# 添加链接器脚本文件
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/User/stm32f401ret6.ld)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Cfg
                    ${CMAKE_CURRENT_SOURCE_DIR}/Ports/inc
                    ${CMAKE_CURRENT_SOURCE_DIR}/Source
                    ${CMAKE_CURRENT_SOURCE_DIR}/User/inc
        )
# 添加源文件
file(GLOB SOURCE_FILES  "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.c"
                        "${CMAKE_CURRENT_SOURCE_DIR}/User/src/*.c"
                        "${CMAKE_CURRENT_SOURCE_DIR}/Ports/src/*.c"
                        "${CMAKE_CURRENT_SOURCE_DIR}/Cfg/*.c"
        )
set(SOURCE_FILES ${SOURCE_FILES})

# 设置编译器和链接器
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_LINKER arm-none-eabi-ld)

# 设置编译选项
set(CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m4 -std=c99 -g -Os -ffunction-sections -fdata-sections -Wall -Wextra -Wno-error")
set(CMAKE_CXX_FLAGS "-mthumb -mcpu=cortex-m4 -std=gnu++17 -g -Os -ffunction-sections -fdata-sections -Wall -Wextra")
set(CMAKE_ASM_FLAGS "-mthumb -mcpu=cortex-m4 -g -x assembler-with-cpp")

# 设置链接选项
set(CMAKE_EXE_LINKER_FLAGS "-mthumb -mabi=aapcs -mcpu=cortex-m4 --specs=nano.specs --specs=nosys.specs -u _printf_float -u _scanf_float -Wl,--gc-sections -Wl,-Map=${PROJECT_NAME}.map -T${LINKER_SCRIPT}")

# 添加可执行文件
add_executable(${PROJECT_NAME}.elf ${SOURCE_FILES} ${STARTUP_FILE} ${ASM_FILE})
target_link_libraries(${PROJECT_NAME}.elf -Wl,-Map=${PROJECT_NAME}.map -Wl,--gc-sections -Wl,--print-memory-usage -Wl,-lc -lm)
# 添加目标文件
add_custom_target(${PROJECT_NAME}.bin ALL DEPENDS ${PROJECT_NAME}.elf COMMAND arm-none-eabi-objcopy -Obinary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin)
# 烧录程序
add_custom_target(flash COMMAND st-flash write ${PROJECT_NAME}.bin 0x08000000 WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
# openocd烧录
add_custom_target(openocd COMMAND openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c init -c "reset halt" -c "flash write_image erase ${PROJECT_NAME}.bin 0x08000000" -c "reset" -c shutdown WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
# 将elf文件的分析log输出到文件中
add_custom_target(readelf COMMAND arm-none-eabi-readelf -a ./ucos_stm32.elf > elflog.txt)
