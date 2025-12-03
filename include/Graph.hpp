#include <Node.hpp>
#include <fstream>
#include <filesystem>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
namespace fs = std::filesystem;
class Graph {
  // vector<Node> nodes;
  unordered_map<string, Node*> nodes;
  vector<string> getLinks(string file);
  Node *file2Node(string file);

public:
  void getNodes(const string &path);
};
