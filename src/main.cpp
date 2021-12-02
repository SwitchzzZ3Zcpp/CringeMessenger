#include "Window/GUI.hpp"
#include "Window/Window.hpp"
#include "Window/Events.hpp"


int main(){
    try{
        Window::init(1920, 1080, "CringeMessenger");
        Events::init();
        GUIhelper::init();
        float color[4] = {0.0f, 0.0f, 0.0f, 0.0f};
        while(!Window::isShouldClose()){
            glClearColor(color[0],color[1],color[2],color[3]);
            Window::Clear();
            GUIhelper::NewFrame();
            
            ImGui::Begin("Welcome!");
            ImGui::Text("Hello World!");
            ImGui::SliderFloat4("Color",color,0.f,1.f);
            ImGui::End();

            GUIhelper::EndFrame();
            Window::SwapBuffers();
            Events::PollEvents();
        }

        GUIhelper::term();
        Window::term();
    }
    catch(std::exception& ex){
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}