# CMakeList.txt: MyPBR 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.16)

project("MyPBR")

# 将源代码添加到此项目的可执行文件。
add_executable(MyPBR "MyPBR.cpp" "MyPBR.h")

set(CMAKE_CXX_STANDARD 17)

# --- GLFW ---
set(GLFW_DIR "${CMAKE_SOURCE_DIR}/glfw-3.3.8.bin.WIN64")
target_include_directories(MyPBR PRIVATE "${GLFW_DIR}/include")

# 根据架构选择库文件
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(GLFW_LIB_DIR "${GLFW_DIR}/lib-vc2022")
else()
    set(GLFW_LIB_DIR "${GLFW_DIR}/lib-vc2022")
endif()
target_link_directories(MyPBR PRIVATE "${GLFW_LIB_DIR}")
target_link_libraries(MyPBR PRIVATE glfw3)

# 消除 MSVCRT 运行时库冲突警告
if(MSVC)
    set_target_properties(MyPBR PROPERTIES LINK_FLAGS "/NODEFAULTLIB:MSVCRT")
endif()

# --- GLM ---
set(GLM_DIR "${CMAKE_SOURCE_DIR}/glm")
target_include_directories(MyPBR PRIVATE "${GLM_DIR}")

# --- Vulkan SDK (使用环境变量) ---
set(VULKAN_DIR "$ENV{VULKAN_SDK}")
if(NOT VULKAN_DIR)
    message(FATAL_ERROR "VULKAN_SDK 环境变量未设置")
endif()
target_include_directories(MyPBR PRIVATE "${VULKAN_DIR}/Include")
target_link_directories(MyPBR PRIVATE "${VULKAN_DIR}/Lib")
target_link_libraries(MyPBR PRIVATE vulkan-1)
