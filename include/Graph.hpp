#pragma once
#include <Node.hpp>
#include <filesystem>
#include <fstream>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
namespace fs = std::filesystem;
class Graph {
  string dirPath;
  int width;
  int height;
  vector<string> getLinks(string file);
  void files2Nodes();

public:
  Graph(string dirPath, int width, int height);
  unordered_map<string, Node *> nodes;
};
