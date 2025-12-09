#pragma once
#include "ForceModel.hpp"
#include "Graph.hpp"
#include "UIRender.hpp"
class UI {
  UIRender &r;
  Graph &graph;

public:
  UI(UIRender &r, Graph &graph) : r(r), graph(graph) {};
  void render(ForceModel &model, int width, int height);
  void update();
};
