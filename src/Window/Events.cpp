#include "Events.hpp"

void Events::PollEvents(){
    glfwPollEvents();
}

void Events::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	Window::width = width;
	Window::height = height;
	glViewport(0, 0, width, height);
}

void Events::init(){
    glfwSetFramebufferSizeCallback(Window::window.get(),Events::framebuffer_size_callback);
}