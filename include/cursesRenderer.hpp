#pragma once

#include "UIRender.hpp"
#include <string>

#ifdef _WIN32
#include <curses.h>
#else
#include <locale.h>
#include <ncurses.h>
#endif

#ifndef _WIN32
class NcursesRenderer : public UIRender {
public:
  NcursesRenderer() {
    setlocale(LC_ALL, "");
    initscr();
    start_color();
    use_default_colors();
    init_pair(1, COLOR_WHITE, -1);
    init_pair(2, COLOR_BLUE, -1);
    noecho();
    curs_set(0);
  }
  ~NcursesRenderer() override { endwin(); }

  void drawLine(const Node &nodeA, const Node &nodeB) override;
  void getScreenSize(int &x, int &y) override;
  void draw(const Node &node, const std::string &text) override;
  void clear() override { ::clear(); }
  void refresh() override { ::refresh(); }
};
#endif

#ifdef _WIN32
class PDCursesRenderer : public UIRender {
public:
  PDCursesRenderer() {
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, -1);
    init_pair(2, COLOR_BLUE, -1);
    noecho();
    curs_set(0);
  }
  ~PDCursesRenderer() override { endwin(); }

  void drawLine(const Node &nodeA, const Node &nodeB) override;
  void getScreenSize(int &x, int &y) override;
  void draw(const Node &node, const std::string &text) override;
  void clear() override { ::clear(); }
  void refresh() override { ::refresh(); }
};
#endif

#ifdef _WIN32
using cursesRenderer = PDCursesRenderer;
#else
using cursesRenderer = NcursesRenderer;
#endif
