#pragma once

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <thread>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <fstream>
#include <mutex>
#include <condition_variable>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "Winmm.lib")

using namespace std;

#define HEIGH_CONSOLE 36
#define WIDTH_CONSOLE 140

#define STOP_VALUE_1 50
#define STOP_VALUE_2 30
#define GO_VALUE_1 110
#define GO_VALUE_2 70

#define MAX_VEHICLES 2
#define MAX_ANIMALS 2
#define MAX_VEHICLE_LENGTH 2
#define MAX_ANIMAL_LENGTH 4
#define MAX_SPEED 200
#define mYFinish 1

#define ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_BACK 8

#define BUTTON_COLOR SetColor(191);
#define SCREEN_COLOR system("Color B0");
#define GREEN_LIGHT TextColor(170);
#define RED_LIGHT TextColor(68);
#define NORMAL TextColor(176);

extern bool MUTED;
extern int LEVEL;