#pragma once
#include "Node.hpp"
#include <vector>
using namespace std;
class ForceModel {
public:
  virtual Vec2 repulsiveForce(const Node &a, const Node &b) const = 0;
  virtual Vec2 atractiveForce(const Node &a, const Node &b) const = 0;
  virtual Vec2 totalForce(const Node &a) const = 0;
  virtual ~ForceModel() = default;
};
