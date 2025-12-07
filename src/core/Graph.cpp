#include "Graph.hpp"
#include <iostream>

random_device rd;
mt19937 gen(rd());

Graph::Graph(string dirPath, int width, int height)
    : dirPath(dirPath), width(width), height(height) {
  files2Nodes();
};

vector<string> Graph::getLinks(string file) {
  vector<string> links;
  ifstream in(file);
  if (!in.is_open())
    return links;
  string line;
  while (getline(in, line)) {
    size_t pos = 0;
    while (true) {
      size_t start = line.find("](", pos);
      if (start == string::npos)
        break;

      size_t end = line.find(")", start + 1);
      if (end == string::npos)
        break;
      // Skipping ]( at the start.
      string link = line.substr(start + 2, end - start - 2);
      links.push_back(link);

      pos = end + 1;
    }
  }
  return links;
};

int getRandom(int value) {
  uniform_int_distribution<> dist(0, value - 1);
  return dist(gen);
};

void Graph::files2Nodes() {
  for (auto &entry : std::filesystem::recursive_directory_iterator(dirPath)) {
    if (entry.is_regular_file()) {
      string path = entry.path().string();

      if (nodes.find(path) == nodes.end()) {
        nodes[path] = new Node(path, getRandom(width), getRandom(height));
      }
    }
  }

  unordered_map<string, vector<Node *>> inverted;

  for (auto &p : nodes) {
    const string &path = p.first;
    Node *node = p.second;

    vector<string> links = getLinks(path);

    for (const string &ref : links) {
      inverted[ref].push_back(node);
    }
  }

  for (auto &p : nodes) {
    const string &path = p.first;
    Node *target = p.second;

    auto it = inverted.find(path);
    if (it != inverted.end()) {
      for (Node *origin : it->second) {
        origin->neighbours.push_back(target);
      }
    }
  }
}
