#include "ForceModelEades.hpp"
#include "Graph.hpp"
#include "SDLRenderer.hpp"
#include "UI.hpp"
#include "cursesRenderer.hpp"
#include <chrono>
#include <thread>
using namespace std;

int main(int argc, char *argv[]) {
  SDLRenderer renderer;
  ForceModelEades model(renderer.c1, renderer.c2, renderer.k1, renderer.k2);
  int width, height;
  SDL_Event event;
  bool running = true;
  renderer.getScreenSize(width, height);
  Graph graph(argv[1], width, height);
  UI ui(renderer, graph);
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        running = false;
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          running = false;
        }
      }
    }
    ui.render(model, width, height);
    ui.update();
    this_thread::sleep_for(chrono::milliseconds(200));
  }
}
