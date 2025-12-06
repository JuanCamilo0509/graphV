#include "Canvas.hpp"
void Canvas::getScreenSize(int &x, int &y) { getmaxyx(stdscr, y, x); }

void Canvas::printNodePosition(Node &node) {
  mvprintw(node.position.y, node.position.x, "●");
};

void Canvas::getUserCharacter() { getch(); }

void Canvas::sectionGraph(Node &node) {
  printNodePosition(node);
  if (node.neighbours.empty())
    return;
  for (Node *n : node.neighbours)
    sectionGraph(*n);
}

void Canvas::update() {
  refresh();
  clear();
}

void Canvas::killCanvas() { endwin(); }
