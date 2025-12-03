#include "Graph.hpp"

Node *Graph::file2Node(string file) {
  Node *n = new Node(file);
  return n;
}

vector<string> Graph::getLinks(string file) {
  vector<string> links;
  ifstream in(file);
  if (!in.is_open())
    return links;
  string line;
  while (getline(in, line)) {
    size_t pos = 0;
    while (true) {
      size_t start = line.find(")[", pos);
      if (start == string::npos)
        break;

      size_t end = line.find("]", start + 1);
      if (end == string::npos)
        break;
      string link = line.substr(start + 1, end - start - 1);
      links.push_back(link);

      pos = end + 1;
    }
  }
  return links;
};

void Graph::getNodes(const string &rootFolder) {

  for (auto &entry :
       std::filesystem::recursive_directory_iterator(rootFolder)) {
    if (entry.is_regular_file()) {
      string path = entry.path().string();

      if (nodes.find(path) == nodes.end()) {
        nodes[path] = new Node(path);
      }
    }
  }

  unordered_map<string, vector<Node *>> inverted;

  for (auto &p : nodes) {
    const string &path = p.first;
    Node *node = p.second;

    vector<string> links = getLinks(path); // <-- tu parser

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
