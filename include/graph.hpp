#include "node.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
using namespace filesystem;
using namespace std;
using namespace filesystem;

class Graph {
  void setNodes();
  vector<string> setNeighbors(path);
  path containerPath_; // Path
  int nodesCount_ = 0; // Amount of files in the container
  vector<Node> nodes_;

public:
  Graph(path container);
  int getNodesCount();
  path getPathContainer();
  vector<Node> &getNodes();
};
