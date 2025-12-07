#pragma once
#include "Graph.hpp"
#include "UIRender.hpp"
#include "ForceModel.hpp"
class UI {
  UIRender &r;
  Graph graph;

public:
  UI(UIRender &r, Graph graph) : r(r), graph(graph) {};
  void render(ForceModel &model, int width, int height);
  void update();
};
