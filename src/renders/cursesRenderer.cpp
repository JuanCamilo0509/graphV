#include "Node.hpp"
#include "cursesRenderer.hpp"
void cursesRenderer::getScreenSize(int &x, int &y) { getmaxyx(stdscr, y, x); }

void cursesRenderer::drawNode(const Node &node, const string &text) {
  for (const auto neig : node.neighbours)
    drawLine(node, *neig);
  attron(COLOR_PAIR(1));
  attron(A_BOLD);
  mvprintw(node.position.y, node.position.x, "%s", text.c_str());
  attroff(A_BOLD);
  attroff(COLOR_PAIR(1));
};

void cursesRenderer::drawLine(const Node &nodeA, const Node &nodeB) {
  int x0 = nodeA.position.x;
  int y0 = nodeA.position.y;
  int x1 = nodeB.position.x;
  int y1 = nodeB.position.y;

  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = (x0 < x1) ? 1 : -1;
  int sy = (y0 < y1) ? 1 : -1;
  int err = dx - dy;

  while (true) {
    if (!((x0 == nodeA.position.x && y0 == nodeA.position.y) ||
          (x0 == nodeB.position.x && y0 == nodeB.position.y))) {
      attron(COLOR_PAIR(2));
      attron(A_DIM);
      mvprintw(y0, x0, "");
      attroff(A_DIM);
      attroff(COLOR_PAIR(2));
    }

    if (x0 == x1 && y0 == y1)
      break;

    int e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      x0 += sx;
    }
    if (e2 < dx) {
      err += dx;
      y0 += sy;
    }
  }
}
