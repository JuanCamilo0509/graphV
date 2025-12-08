#pragma once
#include <ForceModel.hpp>

class ForceModelEades : public ForceModel {
  float c1;
  float c2;
  float k1;
  float k2;

public:
  ForceModelEades(float c1, float c2, float k1, float k2)
      : c1(c1), c2(c2), k1(k1), k2(k2) {};
  Vec2<float> atractiveForce(const Node &a, const Node &b) const override;
  Vec2<float> gravitationalForce(const Node &a, const int width,
                                 const int height) const override;
  Vec2<float> repulsiveForce(const Node &a, const Node &b) const override;
  Vec2<float> totalForce(const Node *a, const Graph &graph, int width,
                         int height) const override;
};
