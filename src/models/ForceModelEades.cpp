#include "ForceModelEades.hpp"
#include <cmath>
#include <ncurses.h>

Vec2<float> ForceModelEades::gravitationalForce(const Node &a, const int width,
                                                const int height) const {
  float cx = width / 2.0f;
  float cy = height / 2.0f;

  float dx = cx - a.position.x;
  float dy = cy - a.position.y;

  float d = sqrt(dx * dx + dy * dy);

  const float eps = 0.01f;
  if (d < eps) {
    return {0.0f, 0.0f};
  }

  float f = 0.05f * d;

  return {f * (dx / d), f * (dy / d)};
}

Vec2<float> ForceModelEades::atractiveForce(const Node &a,
                                            const Node &b) const {
  int eps = 1.0f;
  float dx = b.position.x - a.position.x;
  float dy = b.position.y - a.position.y;
  float d = sqrt(dx * dx + dy * dy);

  if (d < eps)
    d = eps;

  float f = c1 * log(d / k1);
  return {f * (dx / d), f * (dy / d)};
}
Vec2<float> ForceModelEades::repulsiveForce(const Node &a,
                                            const Node &b) const {
  int eps = 1.0;
  float dx = a.position.x - b.position.x;
  float dy = a.position.y - b.position.y;
  float d = sqrt(dx * dx + dy * dy);
  if (d < eps)
    d = eps;
  float f = c2 * (k2 * k2) / (d * d);

  return {f * (dx / d), f * (dy / d)};
}

Vec2<float> ForceModelEades::totalForce(const Node *a, const Graph &graph,
                                        int width, int height) const {
  Vec2<float> total = {0.0, 0.0};
  for (const auto &other : graph.nodes) {
    Node *b = other.second.get();
    if (b == a)
      continue;
    total += repulsiveForce(*a, *b) + gravitationalForce(*a, width, height);
  }

  for (Node *neighbour : a->neighbours)
    total +=
        atractiveForce(*a, *neighbour) + gravitationalForce(*a, width, height);

  return total;
}
