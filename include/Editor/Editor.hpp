#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <string>
class Editor {
public:
  std::string ProjectRootLocation;
  std::string ScriptsLocation;
  std::string SharedObjectsLocation;
  static Editor &GetInstance() {
    static Editor instance;
    return instance;
  }
  void Init();
  void Start();
  void Update();
  void PreExit();
  void Exit();

private:
  Editor() {}
  Editor(Editor const &);
  void operator=(Editor const &);
};

#endif