cmake_minimum_required(VERSION 2.8)

project(gps-timestamper C CXX ASM)

FILE(GLOB_RECURSE ASM_SOURCES *.s)
FILE(GLOB_RECURSE C_SOURCES *.c )
FILE(GLOB_RECURSE CPP_SOURCES *.cpp)
FILE(GLOB_RECURSE H_HEADERS *.h)
FILE(GLOB_RECURSE HPP_HEADERS *.hpp)

set(EXE_SOURCES
    ${ASM_SOURCES}
    ${C_SOURCES}
    ${CPP_SOURCES}
    ${H_HEADERS}
    ${HPP_HEADERS}
)

include_directories(
    low-level/Inc
    low-level/Drivers/CMSIS/Device/ST/STM32F4xx/Include
    low-level/Drivers/CMSIS/Include/
    low-level/Drivers/STM32F4xx_HAL_Driver/Inc
    low-level/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
    low-level/Middlewares/ST/STM32_USB_Device_Library/Core/Inc
    low-level/Middlewares/Third_Party/FreeRTOS/Source/include
    low-level/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS
    low-level/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
    high-level/include
)

set(ELF_NAME ${PROJECT_NAME}.elf)
set(BIN_NAME ${PROJECT_NAME}.bin)
set(MAP_NAME ${PROJECT_NAME}.map)

set(LDSCRIPTS "-T STM32F407VGTx_FLASH.ld")
set(LDSCRIPTS_DIR "${PROJECT_SOURCE_DIR}/low-level")

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-g++)

# This two lines to avoid error 
# arm-none-eabi-g++: error: unrecognized command line option '-rdynamic'
# during compiler check. For some reasons test use '-rdynamic' by default, but arm-none-eabi-g* compilers does not support it
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# To remove -rdynamic
SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

add_definitions(-DSTM32F407xx)
add_definitions(-DUSE_HAL_DRIVER)
add_definitions(-DUSE_FULL_ASSERT)

set(CMAKE_C_CXX_FLAGS "-mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DUSE_FULL_ASSERT -DHSE_VALUE=8000000")
set(CMAKE_C_CXX_FLAGS_DEBUG   "-fno-move-loop-invariants -g -DDEBUG -Os")
set(CMAKE_C_CXX_FLAGS_RELEASE "-Os")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_CXX_FLAGS} -std=gnu11")
set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS_DEBUG} ${CMAKE_C_CXX_FLAGS_DEBUG}" )
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${CMAKE_C_CXX_FLAGS_RELEASE}" )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_CXX_FLAGS} -std=gnu++11")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_C_CXX_FLAGS_DEBUG}" )
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_C_CXX_FLAGS_RELEASE}" )

set(CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS} -x assembler-with-cpp")
set(CMAKE_ASM_FLAGS_DEBUG   "${CMAKE_C_FLAGS_DEBUG}" )
set(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}" )

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LDSCRIPTS} -Xlinker --gc-sections -L${LDSCRIPTS_DIR} -Wl,-Map,\"${MAP_NAME}\" --specs=nano.specs")


add_executable(${ELF_NAME} ${EXE_SOURCES})

add_custom_command(TARGET ${ELF_NAME}
                   POST_BUILD
                   COMMAND arm-none-eabi-objcopy ARGS -O binary ${ELF_NAME}  ${BIN_NAME}
                   )

