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
  for (const auto &p : graph.nodes) {
    const string &path = p.first;
    Node *node = p.second;
    cout << *node << endl;
  }
}
