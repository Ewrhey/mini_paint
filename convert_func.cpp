#include"mini_paint.h"

int char_number(char c){
return c - '0';
}

int string_number(string str){
int i = 0, n = 0;
while (str[i] != '\0'){
    n = n * 10;
    n += char_number(str[i]);
    i++;
}
return n;
}
