#include "NcursesRenderer.hpp"
#include "Node.hpp"
void NcursesRenderer::getScreenSize(int &x, int &y) { getmaxyx(stdscr, y, x); }

void NcursesRenderer::draw(const Node &node, const string &text) {
  // For the future with a better drawline function
  // for (const auto neig : node.neighbours)
  //   drawLine(node, *neig);
  mvprintw(node.position.y, node.position.x, "%s", text.c_str());
};

void NcursesRenderer::drawLine(const Node &nodeA, const Node &nodeB) {
  int y1 = nodeB.position.y;
  int y0 = nodeA.position.y;
  int x1 = nodeB.position.x;
  int x0 = nodeA.position.x;
  while (x0 != x1 || y0 != y1) {
    if (x0 < x1)
      x0++;
    else if (x0 > x1)
      x0--;

    if (y0 < y1)
      y0++;
    else if (y0 > y1)
      y0--;
    mvprintw(y0, x0, "");
  }
}
