#include <cmath>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <dos.h>
#include <fstream>
#include <graphics.h>
#include <iostream>
#define ON 1
#define OFF 0
#define p(x) (8 * (x - 1))
#define INC 7
#define ROW 40
#define COL 20
#define MAX_ITEM 5
#define LEFT 75
#define UP 72
#define DOWN 80
#define RIGHT 77
typedef char option[15];

void help();
void high_scores();
void resume();
void victory();
bool if_win();
void over();
bool game_over();
void add_tile();
bool possible();
void right();
void down();
void up();
void left();
void save();
void play();
void high_count();
void update();
void draw();
void init();
void doCursor(int);
void getGrString(char *);
void newLine();
void start();
void target();
void reverse_video(int x, int y, char *str);
void normal_video(int x, int y, char *str);
void control_menu();
char menu();
void home_draw();
void home();
