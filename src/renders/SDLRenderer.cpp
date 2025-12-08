#include "SDLRenderer.hpp"
#include <iostream>

SDLRenderer::SDLRenderer() {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Graph SDL2", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDLRenderer::~SDLRenderer() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void SDLRenderer::getScreenSize(int &x, int &y) {
  SDL_GetWindowSize(window, &x, &y);
}

void drawFilledCircle(SDL_Renderer *renderer, int cx, int cy, int radius) {
  for (int dy = -radius; dy <= radius; dy++) {
    for (int dx = -radius; dx <= radius; dx++) {
      if (dx * dx + dy * dy <= radius * radius) {
        SDL_RenderDrawPoint(renderer, cx + dx, cy + dy);
      }
    }
  }
}

void SDLRenderer::drawNode(const Node &node, const std::string &text) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  drawFilledCircle(renderer, node.position.x, node.position.y, 6);
}

void SDLRenderer::drawLine(const Node &nodeA, const Node &nodeB) {
  SDL_SetRenderDrawColor(renderer, 100, 150, 255, 255);
  SDL_RenderDrawLine(renderer, nodeA.position.x, nodeA.position.y,
                     nodeB.position.x, nodeB.position.y);
}

void SDLRenderer::clear() {
  SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
  SDL_RenderClear(renderer);
}

void SDLRenderer::refresh() { SDL_RenderPresent(renderer); }
