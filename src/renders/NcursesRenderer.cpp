#include "NcursesRenderer.hpp"
void NcursesRenderer::getScreenSize(int &x, int &y) { getmaxyx(stdscr, y, x); }

void NcursesRenderer::draw(int x, int y, const string &text) {
  mvprintw(y, x, "%s", text.c_str());
};
