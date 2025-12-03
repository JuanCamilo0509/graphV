#include "Graph.hpp"
#include "Node.hpp"
#include <Canvas.hpp>
#include <ForceModelEades.hpp>
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

int main(int argc, char *argv[]) {
  Graph graph;
  graph.getNodes(argv[1]);
  // Set up to accept utf-8 characters
  // setlocale(LC_ALL, "");

  // ForceModelEades model;

  // Node a;
  // a.position = {50.0f, 1.0f};
  //
  // Node b;
  // b.position = {50.0f, 15.0f};
  //
  // Node c;
  // c.position = {80.0f, 10.0f};
  //
  // float dt = 0.1f;
  //
  // a.neighbours = {&b, &c};
  // b.neighbours = {&a, &c};
  // c.neighbours = {&a, &b};
  //
  // vector<Node> allNodes = {a, b, c};
  //
  // Canvas canvas;
  // while (true) {
  //   for (Node &node : allNodes)
  //     canvas.printNodePosition(node);
  //   for (Node &node : allNodes)
  //     node.moveNode(model.totalForce(node), dt, 0.58f);
  //   canvas.update();
  //   this_thread::sleep_for(std::chrono::milliseconds(100));
  // }
  // canvas.killCanvas();

  return 0;
}
