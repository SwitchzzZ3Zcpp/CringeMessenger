#pragma once

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <memory>

struct DestroyGLFWwindow{

    void operator()(GLFWwindow* ptr){
         glfwDestroyWindow(ptr);
    }

};

typedef std::unique_ptr<GLFWwindow, DestroyGLFWwindow> sGLFWwindow;

class Window{
    static sGLFWwindow window;
    static size_t width, height;
    static std::string title;
public: 
    static void init(const size_t& width, const size_t& height, const std::string& title);
    static bool isShouldClose();
    static void SwapBuffers();
    static void Clear();
    static void term();
    static void Close();
    friend class Events;
    friend class GUIhelper;
};