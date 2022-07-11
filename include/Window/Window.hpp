#ifndef WIDNOW_HPP
#define WIDNOW_HPP
#include <GLFW/glfw3.h>
#include <cstddef>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "Editor"

struct WindowBindings {
  int windowCloseKey = GLFW_KEY_ESCAPE;
};

class Window {
public:
  WindowBindings bindings;
  GLFWwindow *wHandle;
  int windowExitStatus;
  static Window &GetInstance() {
    static Window instance;
    return instance;
  }
  void Update() {
    glfwSetWindowShouldClose(
        wHandle, glfwGetKey(wHandle, bindings.windowCloseKey) == true);
    windowExitStatus = glfwWindowShouldClose(wHandle);
  }
  void wPollEvents() { glfwPollEvents(); }
  void wSwapBuffers() { glfwSwapBuffers(wHandle); }
  void wGetWindowSize(int &_width, int &_height) {
    glfwGetWindowSize(wHandle, &_width, &_height);
  }
  void wSetWindowSize(int &_width, int &_height) {
    glfwSetWindowSize(wHandle, _width, _height);
  }

private:
  void CreateWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    wHandle = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME,
                               nullptr, nullptr);
    glfwMakeContextCurrent(wHandle);
  }
  Window() { CreateWindow(); }
  ~Window() {
    glfwDestroyWindow(wHandle);
    glfwTerminate();
  }
  Window(Window const &);
  void operator=(Window const &);
};

#endif