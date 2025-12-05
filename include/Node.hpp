#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Vec2 {
  float x;
  float y;
  Vec2 &operator+=(const Vec2 &other) {
    x += other.x;
    y += other.y;
    return *this;
  }
};
class Node {
public:
  Node(string file) {
    path = file;
    position = {0, 0};
    Forces = {0, 0};
    velocity = {0, 0};
    neighbours = {};
  };

  Vec2 position;
  Vec2 Forces;
  Vec2 velocity;
  string path;
  vector<Node *> neighbours;

  void moveNode(const Vec2 &force, float &t, float damping);
};

std::ostream &operator<<(ostream &os, const Node &n);
