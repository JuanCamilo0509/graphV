#include "UI.hpp"
#include "ForceModel.hpp"

void UI::render(ForceModel &model, int width, int height) {
  for (const auto &p : graph.nodes) {
    Node *node = p.second.get();
    for (Node *neigh : node->neighbours) {
      r.drawLine(*node, *neigh);
    }
  }

  for (const auto &p : graph.nodes) {
    Node *node = p.second.get();
    r.drawNode(*node, "●");
    node->moveNode(model.totalForce(node, graph, width, height), 0.8f, 0.58f);
  }
}
void UI::update() {
  r.refresh();
  r.clear();
}
