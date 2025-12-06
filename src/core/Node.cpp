#include <Node.hpp>

void Node::moveNode(const Vec2<float> &force, float t, float damping) {
  this->velocity.x = force.x * t * damping;
  this->velocity.y = force.y * t * damping;
  this->position.x =
      (1 / 2) * force.x * t * t + this->velocity.x * t + this->position.x;
  this->position.y =
      (1 / 2) * force.y * t * t + this->velocity.y * t + this->position.y;
}

std::ostream &operator<<(std::ostream &os, const Node &n) {
  os << n.path << " -> [ ";
  for (auto *neigh : n.neighbours) {
    os << neigh->path << " ";
  }
  os << "]";
  return os;
}
