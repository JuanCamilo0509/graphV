#include "Graph.hpp"
#include "Node.hpp"
#include <Canvas.hpp>
#include <ForceModelEades.hpp>
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  int width = 0;
  int height = 0;
  float t = 0.1;
  Canvas canvas;
  canvas.getScreenSize(width, height);
  Graph graph(width, height);
  ForceModelEades model;
  graph.getNodes(argv[1]);
  while (true) {
    for (const auto &p : graph.nodes) {
      const string &path = p.first;
      Node *node = p.second;
      canvas.printNodePosition(*node);
      // printw("%s", node->path.c_str()); // Interesting
      node->moveNode(model.totalForce(*node), t, 0.58f);
    }
    canvas.update();
    this_thread::sleep_for(chrono::milliseconds(200));
  }
  canvas.killCanvas();
}
