#pragma once
#include <vector>
#include <iostream>
using namespace std;
struct Node {
  int id;
  string name;
  vector<string> neighbors;
  int px;
  int py;
};
