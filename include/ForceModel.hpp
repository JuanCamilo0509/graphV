#pragma once
#include "Node.hpp"
#include "Graph.hpp"
#include <vector>
using namespace std;
class ForceModel {
public:
  virtual Vec2<float> repulsiveForce(const Node &a, const Node &b) const = 0;
  virtual Vec2<float> atractiveForce(const Node &a, const Node &b) const = 0;
  virtual Vec2<float> totalForce(const Node *a, const Graph &graph) const = 0;
  virtual ~ForceModel() = default;
};
