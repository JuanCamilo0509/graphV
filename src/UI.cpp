#include "UI.hpp"
#include "ForceModel.hpp"

void UI::render(ForceModel &model) {
  for (const auto &p : graph.nodes) {
    Node *node = p.second;
    r.draw(node->position.x, node->position.y, "●");
    node->moveNode(model.totalForce(*node), 0.1f, 0.58f);
  }
}
void UI::update() {
  r.refresh();
  r.clear();
}
