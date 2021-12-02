#include "Window.hpp"

sGLFWwindow Window::window;
size_t Window::width, Window::height;
std::string Window::title;

void Window::init(const size_t& width, const size_t& height, const std::string& title){
    Window::width = width;
    Window::height = height;
    Window::title = title;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    Window::window.reset(glfwCreateWindow(Window::width,Window::height,title.c_str(),nullptr,nullptr));
    if(Window::window.get()==nullptr){
        glfwTerminate();
        throw std::runtime_error("WINDOW::INIT Failed to Create Window!");
    }
    glfwMakeContextCurrent(Window::window.get());

    if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))){
        Window::window.reset();
        glfwTerminate();
        throw std::runtime_error("WINDOW::INIT Failed to Load OpenGL Loader!");  
    }

}

bool Window::isShouldClose(){
    return glfwWindowShouldClose(Window::window.get());
}

void Window::SwapBuffers(){
    glfwSwapBuffers(Window::window.get());
}

void Window::Clear(){
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::term(){
    Window::window.reset();
    glfwTerminate();
}

void Window::Close(){
    glfwSetWindowShouldClose(Window::window.get(),true);
}
