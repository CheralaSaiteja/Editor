
#include <Editor/Editor.hpp>
#include <Window/Window.hpp>
#include <iostream>

Editor &editor =    editor.GetInstance();
Window &window = window.GetInstance();
int main(int, char **) {
  std::cout << "Hello, Editor!\n";
  editor.Init();
  editor.Start();
  while (!window.windowExitStatus) {
    editor.Update();
  }
  editor.PreExit();
  editor.Exit();
}
