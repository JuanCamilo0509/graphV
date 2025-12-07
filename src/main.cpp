#include "ForceModelEades.hpp"
#include "Graph.hpp"
#include "NcursesRenderer.hpp"
#include "UI.hpp"
#include <chrono>
#include <thread>
using namespace std;

int main(int argc, char *argv[]) {
  NcursesRenderer renderer;
  ForceModelEades model;
  int width, height;
  renderer.getScreenSize(width, height);
  Graph graph(argv[1], width, height);
  UI ui(renderer, graph);
  while (true) {
    ui.render(model, width, height);
    ui.update();
    this_thread::sleep_for(chrono::milliseconds(200));
  }
}
