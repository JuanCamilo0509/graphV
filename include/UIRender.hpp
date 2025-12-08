#pragma once
#include "Node.hpp"
#include <string>
using namespace std;

class UIRender {
public:
  virtual void clear() = 0;
  virtual void getScreenSize(int &x, int &y) = 0;
  virtual void drawNode(const Node &node, const string &text) = 0;
  virtual void drawLine(const Node &nodeA, const Node &nodeB) = 0;
  virtual void refresh() = 0;
  virtual ~UIRender() = default;
};
