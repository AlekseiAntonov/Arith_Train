//
// Created by user on 31.01.2020.
//

#ifndef TESTAPP_MAIN_H
#define TESTAPP_MAIN_H

using namespace std;

#include <windows.h>
#include <utility>

static double RND(double a, double b);

pair<int, pair<int,int>> CreateEquation();

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int StrToInt(char *s);

char* IntToStr(int n);

#endif //TESTAPP_MAIN_H
