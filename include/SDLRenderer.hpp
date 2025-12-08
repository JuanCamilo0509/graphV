#pragma once

#include "UIRender.hpp"
#include <SDL2/SDL.h>

class SDLRenderer : public UIRender {
public:
  float c1 = 30.0f;
  float c2 = 20.0f;
  float k1 = 30.0f;
  float k2 = 40.0f;
  SDLRenderer();
  ~SDLRenderer() override;
  void drawLine(const Node &nodeA, const Node &nodeB) override;
  void getScreenSize(int &x, int &y) override;
  void drawNode(const Node &node, const std::string &text) override;
  void clear() override;
  void refresh() override;

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};
