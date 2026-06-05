// MyPBR.cpp: 定义应用程序的入口点。
//
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include "MyPBR.h"

using namespace std;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(800, 600, "MyPBR", nullptr, nullptr);
	// 创建vulkan实例、设备、交换链...全部从这里开始
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		// 渲染循环
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
