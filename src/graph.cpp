#include "graph.hpp"

Graph::Graph(path container) : containerPath_{container} {
  try {
    setNodes();
  } catch (filesystem_error const &err) {
    cout << "Folder wasn't Found, check the file path";
  }
}

vector<string> Graph::setNeighbors(path filename) {
  ifstream file(filename, ifstream::in);
  string content((istreambuf_iterator<char>(file)),
                 istreambuf_iterator<char>());
  vector<string> link_path;
  size_t pos = 0;
  while ((pos = content.find("](", pos)) != string::npos) {
    int pos2 = content.find(")", pos);
    link_path.push_back(content.substr(pos + 2, pos2 - pos - 2));
    pos = pos2;
  }
  return link_path;
}

void Graph::setNodes() {
  // Is it really the best way? Idk, but it's the less fancy one.
  vector<path> files_directory;
  for (auto const &node : directory_iterator(containerPath_)) {
    files_directory.push_back(node);
    nodesCount_ += 1;
  }

  for (const string &path_node : files_directory) {
    vector<string> neighbors = setNeighbors(containerPath_ / path_node);
    Node node;
    node.name = path_node;
    node.neighbors = neighbors;
    nodes_.push_back(node);
  }
}

int Graph::getNodesCount() { return nodesCount_; }
vector<Node>& Graph::getNodes() { return nodes_; };
path Graph::getPathContainer() { return containerPath_; }
