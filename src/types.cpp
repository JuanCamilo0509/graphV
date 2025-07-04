#include "types.hpp"

void Fr_node(Node &affect_node, Node &force_node) {
  int L0 = 5;
  int k = 5;
  int dx = force_node.position.x - affect_node.position.x;
  int dy = force_node.position.y - affect_node.position.y;
  float length = sqrt((dx * dx) + (dy * dy));
  int stretch = length - L0;
  if (stretch < 0.1e-6) {
    return;
  }
  int F = k * stretch;
  float dir_x = dx / length;
  float dir_y = dy / length;
  affect_node.force.x += (int)F * dir_x;
  affect_node.force.y += (int)F * dir_y;
};

void Fr_nodes(vector<Node> &nodes, float step) {
  for (Node &node : nodes)
    node.force = {0, 0};
  for (Node &affect_node : nodes) {
    for (Node &force_node : nodes) {
      Fr_node(affect_node, force_node);
    }
  }
  for (Node &node : nodes) {
    acceleration(node);
    velocity(node, step);
    position(node, step);
  }
};

void acceleration(Node &node) {
  node.acceleration = {node.force.x / node.mass, node.force.y / node.mass};
};

void velocity(Node &node, float time_step) {
  node.velocity.x += node.acceleration.x * time_step;
  node.velocity.y += node.acceleration.y * time_step;
};

void position(Node &node, float time_step) {
  node.position.x += node.velocity.x * time_step +
                     node.acceleration.x * time_step * time_step / (2);
  node.position.y += node.velocity.y * time_step +
                     node.acceleration.y * time_step * time_step / (2);
}
