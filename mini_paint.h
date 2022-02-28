#ifndef MINI_PAINT_H_INCLUDED
#define MINI_PAINT_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "Windows.h"
using namespace std;

int main_2 (string way, bool save);
int choice_color(string color);
void cout_color(string str, int color);
void save_func(string window);


bool error(string comand);
string choice(string comand, string window, char ban_c);

string r(string window, int x, int y, int w, int h, char c);
string R(string window, int x, int y, int w, int h, char c);
string r_R_error(string window, int x, int y, int w, int h);
string preparation_r_R(string comand, string window, char r_R);

string c(int x, int y, int r, char ch, string window );
string C(int x, int y, int r, char ch, string a);
string preparation_c_C(string comand, string window, char c_C);

string L(string window, int x1, int y1, int x2, int y2, char c);
bool error_L(string window, int x, int y, int x1, int y1);
string preparation_L(string comand, string window);
int absi(int a);
int check_pred_func(int x1, int y1, int x2, int y2);

string work_space(int w, int h, char cb);
string work_space_preparation(string comand);
bool work_space_error(string window);

void SetColor(int a, int bg);
int itc_len(string);
int char_in_str(char c, string str);
int pos_char_in_str(char c, string str);
string itc_slice_str(string str, int start, int end_);
int string_number(string str);
char number_char(int n);
int char_number(char c);
bool control_string(string a);
bool control_char(char a);
#endif //MINI_PAINT_H_INCLUDED
