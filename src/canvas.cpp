#include "canvas.hpp"
void Canvas::init() {
  initscr();
  noecho();
  curs_set(0);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}
void Canvas::getScreenSize(int &x, int &y) { getmaxyx(stdscr, y, x); }

void Canvas::plotLineV(int x0, int y0, int x1, int y1) {
  int dx = x1 - x0;
  int dy = y1 - y0;
  int xi = 1;

  if (dx < 0) {
    xi = -1;
    dx = -dx;
  }

  int D = 2 * dy - dx;
  int x = x0;
  for (int y = y0 + 1; y < y1; y++) {
    mvprintw(y, x, "*");
    if (D > 0) {
      x += xi;
      D = D + (2 * (dx - dy));
    } else {
      D = D + 2 * dx;
    }
  }
}

void Canvas::plotLineH(int x0, int y0, int x1, int y1) {
  int dx = x1 - x0;
  int dy = y1 - y0;
  int yi = 1;

  if (dy < 0) {
    yi = -1;
    dy = -dy;
  }

  int D = 2 * dy - dx;
  int y = y0;
  for (int x = x0 + 1; x < x1; x++) {
    mvprintw(y, x, "*");
    if (D > 0) {
      y += yi;
      D = D + (2 * (dy - dx));
    } else {
      D = D + 2 * dy;
    }
  }
}

void Canvas::plotLine(int x0, int y0, int x1, int y1) {
  if (abs(y1 - y0) < abs(x1 - x0)) {
    if (x0 > x1) {
      plotLineH(x1, y1, x0, y0);
    } else {
      plotLineH(x0, y0, x1, y1);
    }
  } else {
    if (y0 > y1) {
      plotLineV(x1, y1, x0, y0);
    } else {
      plotLineV(x0, y0, x1, y1);
    }
  }
}
void Canvas::printNodePosition(Node node) {
  attron(COLOR_PAIR(node.color_id));
  mvprintw(node.position.y, node.position.x, "●");
  attroff(COLOR_PAIR(node.color_id));
};
void Canvas::getUserCharacter() { getch(); }

void Canvas::update() {
  refresh();
  clear();
}

void Canvas::killCanvas() { endwin(); }
