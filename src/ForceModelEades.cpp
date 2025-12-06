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
    d = 0.0001f;
  float k = 1.0f; // k = C*sqrt(area/#vertices)
  float f = (d * d) / k;
  return {f * (dx / d), f * (dy / d)};
}
Vec2<float> ForceModelEades::repulsiveForce(const Node &a,
                                            const Node &b) const {
  float dx = a.position.x - b.position.x;
  float dy = a.position.y - b.position.y;
  float d = sqrt(dx * dx + dy * dy);
  if (d < 0.0001f)
    d = 0.0001f;
  float k = 1.0f;
  float f = (k * k) / (d * d);

  return {f * (dx / d), f * (dy / d)};
}

Vec2<float> ForceModelEades::totalForce(const Node &a) const {
  float min = 1.0f;
  Vec2<float> total = {0.0, 0.0};
  for (Node *currentNode : a.neighbours) {
    float distance = sqrt((a.position.x - currentNode->position.x) *
                              (a.position.x - currentNode->position.x) +
                          (a.position.y - currentNode->position.y) *
                              (a.position.y - currentNode->position.y));
    if (distance < min) {
      total += repulsiveForce(a, *currentNode);
    } else {
      total += atractiveForce(a, *currentNode);
    }
  }
  return total;
}
