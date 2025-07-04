#include "canvas.hpp"
#include "graph.hpp"
#include "types.hpp"
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

int main() {
  Graph graph("/home/idk/myself/projects/graphV/testing_container/");

  // Utf-8
  setlocale(LC_ALL, "");

  Canvas canvas;
  canvas.init();
  int xMax, yMax;
  canvas.getScreenSize(xMax, yMax);

  vector<Node> &nodesCollection = graph.getNodes();

  srand(time(0));
  for (Node &node : nodesCollection) {
    node.position.x = rand() % xMax;
    node.position.y = rand() % yMax;
    node.color_id = (rand() % 7) + 1;
  }

  float dt = 0.1;
  int stepts = 0;
  while (stepts < 1000) {
    Fr_nodes(nodesCollection, dt);

    for (int i = 0; i < graph.getNodesCount(); i++) {
      mvprintw(i, 0, "Node(%d): F(%d, %d), P(%d, %d), a(%d, %d), v(%d, %d)", i,
               nodesCollection[i].force.x, nodesCollection[i].force.y,
               nodesCollection[i].position.x, nodesCollection[i].position.y,
               nodesCollection[i].acceleration.x,
               nodesCollection[i].acceleration.y, nodesCollection[i].velocity.x,
               nodesCollection[i].velocity.y);
    }
    for (Node node : nodesCollection) {
      canvas.printNodePosition(node);
    }

    canvas.update();
    this_thread::sleep_for(std::chrono::milliseconds(200));
    stepts += 1;
  }

  canvas.getUserCharacter();
  canvas.killCanvas();

  return 0;
}
