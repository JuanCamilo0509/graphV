#include "types.hpp"
#include <cstdlib>
#include <ncurses.h>
#include <iostream>
#include <vector>
using namespace std;

class Canvas {
public:
  void init();
  void getScreenSize(int &x, int &y);
  void plotLine(int x0, int y0, int x1, int y1);
  void killCanvas();
  void update();
  void getUserCharacter();
  void printNodePosition(Node node);

private:
  void plotLineV(int x0, int y0, int x1, int y1);
  void plotLineH(int x0, int y0, int x1, int y1);
};
