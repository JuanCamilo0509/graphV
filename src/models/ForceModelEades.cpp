#include "ForceModelEades.hpp"
#include <cmath>

using namespace std;

ForceModelEades::ForceModelEades() {}

Vec2<float> ForceModelEades::atractiveForce(const Node &a,
                                            const Node &b) const {
  float dx = b.position.x - a.position.x;
  float dy = b.position.y - a.position.y;
  float d = sqrt(dx * dx + dy * dy);
  if (d < 0.0001f)
    d = 0.01f;
  float k = 1.0f; // k = C*sqrt(area/#vertices)
  float c1 = 1.5f;
  float f = c1 * log(d / k);
  return {f * (dx / d), f * (dy / d)};
}
Vec2<float> ForceModelEades::repulsiveForce(const Node &a,
                                            const Node &b) const {
  float dx = a.position.x - b.position.x;
  float dy = a.position.y - b.position.y;
  float d = sqrt(dx * dx + dy * dy);
  if (d < 0.0001f)
    d = 0.01f;
  float k = 1.0f;
  float c2 = 0.05f;
  float f = c2 * (k * k) / (d * d);

  return {f * (dx / d), f * (dy / d)};
}

Vec2<float> ForceModelEades::totalForce(const Node *a,
                                        const Graph &graph) const {
  Vec2<float> total = {0.0, 0.0};
  for (const auto &other : graph.nodes) {
    if (other.second == a)
      continue;
    total += repulsiveForce(*a, *other.second);
  }

  for (Node *neighbour : a->neighbours)
    total += atractiveForce(*a, *neighbour);

  return total;
}
