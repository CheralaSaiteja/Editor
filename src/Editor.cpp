// GLAD
#include <glad/glad.h>
// Others
#include <Editor/Editor.hpp>
#include <Window/Window.hpp>

Window &ewindow = ewindow.GetInstance();

void Editor::Init() {}
void Editor::Start() {
  gladLoadGL();
  int width, height;
  ewindow.wGetWindowSize(width, height);
  glViewport(0, 0, width, height);
}
void Editor::Update() {
  ewindow.wPollEvents();
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  ewindow.Update();
  ewindow.wSwapBuffers();
}
void Editor::PreExit() {}
void Editor::Exit() {}