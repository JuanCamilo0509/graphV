#pragma once
#include <string>
using namespace std;

class UIRender {
public:
  virtual void clear() = 0;
  virtual void getScreenSize(int &x, int &y) = 0;
  virtual void draw(int x, int y, const string &text) = 0;
  virtual void refresh() = 0;
  virtual ~UIRender() = default;
};
