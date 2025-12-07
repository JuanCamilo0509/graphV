#pragma once
#include "Graph.hpp"
#include "Node.hpp"
#include <vector>
using namespace std;
class ForceModel {
public:
  virtual Vec2<float> repulsiveForce(const Node &a, const Node &b) const = 0;
  virtual Vec2<float> atractiveForce(const Node &a, const Node &b) const = 0;
  virtual Vec2<float> gravitationalForce(const Node &a, const int width,
                                         const int height) const = 0;
  virtual Vec2<float> totalForce(const Node *a, const Graph &graph, int width,
                                 int height) const = 0;
  virtual ~ForceModel() = default;
};
