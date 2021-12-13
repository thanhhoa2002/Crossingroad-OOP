#pragma once

#include "CONSTANT.h"

void FixConsoleWindow();
void GotoXY(int, int);
void hideCursor();
void removeScrollBar();
void setConsoleWindow(int, int);
void SetColor(int);
void TextColor(int);
void print_color(const char*, const char*);