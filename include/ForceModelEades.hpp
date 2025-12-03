#pragma once
#include <ForceModel.hpp>

class ForceModelEades : public ForceModel {
public:
  ForceModelEades();
  Vec2 atractiveForce(const Node &a, const Node &b) const override;
  Vec2 repulsiveForce(const Node &a, const Node &b) const override;
  Vec2 totalForce(const Node &a) const override;
};
