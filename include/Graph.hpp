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
  int width;
  int height;

public:
  Graph(int width, int height) : width(width), height(height) {};
  unordered_map<string, Node *> nodes;
  vector<string> getLinks(string file);
  void getNodes(const string &path);
};
