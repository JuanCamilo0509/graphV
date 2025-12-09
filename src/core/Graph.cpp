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
  fs::path root = fs::absolute(dirPath);

  std::unordered_set<std::string> currentFiles;
  for (auto &entry : fs::recursive_directory_iterator(root)) {
    if (!entry.is_regular_file())
      continue;
    fs::path rel = fs::relative(entry.path(), root);
    std::string path = "./" + rel.generic_string();
    currentFiles.insert(path);
  }

  std::unordered_map<std::string, std::unique_ptr<Node>> newNodes;
  newNodes.reserve(nodes.size());

  for (const auto &path : currentFiles) {
    auto it = nodes.find(path);
    if (it != nodes.end()) {
      newNodes.emplace(path, std::move(it->second));
    } else {
      newNodes.emplace(path, std::make_unique<Node>(path, getRandom(width),
                                                    getRandom(height)));
    }
  }

  nodes.swap(newNodes);

  for (auto &p : nodes)
    p.second->neighbours.clear();

  std::unordered_map<std::string, std::vector<std::string>> inverted;
  inverted.reserve(nodes.size());

  for (const auto &p : nodes) {
    const std::string &path = p.first;
    std::vector<std::string> links = getLinks(path);
    for (const auto &ref : links) {
      inverted[ref].push_back(path);
    }
  }

  for (const auto &p : inverted) {
    const std::string &targetPath = p.first;
    auto itTarget = nodes.find(targetPath);
    if (itTarget == nodes.end())
      continue;

    Node *target = itTarget->second.get();
    for (const auto &originPath : p.second) {
      auto itOrigin = nodes.find(originPath);
      if (itOrigin == nodes.end())
        continue;
      Node *origin = itOrigin->second.get();
      origin->neighbours.push_back(target);
    }
  }
}
