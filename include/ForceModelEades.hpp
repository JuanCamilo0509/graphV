#pragma once
#include <ForceModel.hpp>

class ForceModelEades : public ForceModel {
public:
  ForceModelEades();
  Vec2<float> atractiveForce(const Node &a, const Node &b) const override;
  Vec2<float> gravitationalForce(const Node &a, const int width,
                                 const int height) const override;
  Vec2<float> repulsiveForce(const Node &a, const Node &b) const override;
  Vec2<float> totalForce(const Node *a, const Graph &graph, int width,
                         int height) const override;
};
