#include "canvas.hpp"
#include "graph.hpp"
#include "node.hpp"
#include <vector>
using namespace std;

int main() {
  Graph graph("/home/idk/myself/projects/graphV/testing_container/");
  int count = graph.getNodesCount();

  // utf-8
  setlocale(LC_ALL, "");

  Canvas canvas;
  canvas.init();
  int xMax, yMax;
  canvas.getScreenSize(xMax, yMax);

  srand(time(0));
  vector<Node> &nodesCollections = graph.getNodes();

  for (Node &node : nodesCollections) {
    node.px = rand() % xMax;
    node.py = rand() % yMax;
  }

  for (Node node : nodesCollections) {
    canvas.printNode(node);
  }

  canvas.update();
  canvas.getUserCharacter();
  canvas.killCanvas();

  return 0;
}
