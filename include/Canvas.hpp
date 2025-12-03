#pragma once
#include "Node.hpp"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <vector>
using namespace std;

class Canvas {
public:
  Canvas() {
    initscr();
    noecho();
    curs_set(0);
    setlocale(LC_ALL, "");
  };
  void getScreenSize(int &x, int &y);
  void printNodePosition(Node node);
  void killCanvas();
  void getUserCharacter();
  void update();
};
