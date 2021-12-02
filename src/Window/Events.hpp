#pragma once
#include "Window.hpp"


class Events{
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

public:

    static void PollEvents();
    static void init();
};