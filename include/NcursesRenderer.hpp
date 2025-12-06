#pragma once
#include "UIRender.hpp"
#include <ncurses.h>
using namespace std;

class NcursesRenderer : public UIRender {
public:
  NcursesRenderer() {
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(0);
  };
  ~NcursesRenderer() { endwin(); }
  void getScreenSize(int &x, int &y) override;
  void draw(int x, int y, const string &text) override;
  void clear() override { ::clear(); }
  void refresh() override { ::refresh(); }
};
