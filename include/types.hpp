#pragma once
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Vector2i {
  int x;
  int y;
};

struct Node {
  int id;
  string name;
  vector<string> neighbors;
  int color_id; 
  int mass = 1;
  Vector2i force;
  Vector2i acceleration = {0, 0};
  Vector2i velocity = {0, 0};
  Vector2i position;
};

void Fr_nodes(vector<Node> &node, float steps);
void Fr_node(Node &node1, Node &node2);
void acceleration(Node&node);
void velocity(Node &node, float steps);
void position(Node &node, float steps);
