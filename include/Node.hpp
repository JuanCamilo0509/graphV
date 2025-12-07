#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T> struct Vec2 {
  T x;
  T y;
  Vec2 &operator+=(const Vec2 &other) {
    x += other.x;
    y += other.y;
    return *this;
  }
  Vec2 &operator+(const Vec2 &other) {
    x = x + other.x;
    y = y + other.y;
    return *this;
  }
};
class Node {
public:
  Node(string file, int x, int y) {
    path = file;
    position = {x, y};
    Forces = {0, 0};
    velocity = {0, 0};
    neighbours = {};
  };

  Vec2<int> position;
  Vec2<float> Forces;
  Vec2<float> velocity;
  string path;
  vector<Node *> neighbours;

  void moveNode(const Vec2<float> &force, float t, float damping);
};

std::ostream &operator<<(ostream &os, const Node &n);
