#include"mini_paint.h"

int check_pred_func(int x1, int y1, int x2, int y2){
int pred = 0, dx = x2 - x1, dy = y2 - y1;
if (dx >= dy)
    pred += 2*(dx / 4) + dx % 5;
else
    pred += 2*(dy / 4) + dy % 5;
return pred;
}
string horizontal_L(string window, int x1, int x2, int y, char c){
    int dx = x2 - x1;
    for (int o = 0; o < y; o++)
        x1 = x1 + (pos_char_in_str('\n', window) + 1);
    while(dx > 0){
        window[x1] = c;
        x1++;
        dx--;
    }
    return window;
}

string vertical_L(string window, int y1, int y2, int x1, char c){
    int dy = y2 - y1;
    for (int o = 0; o < y1; o++)
        x1 = x1 + (pos_char_in_str('\n', window) + 1);
    while(dy > 0){
        window[x1] = c;
        x1 = x1 + (pos_char_in_str('\n', window) + 1);
        dy--;
    }
    return window;

}
string L(string window, int x1, int y1, int x2, int y2, char c){
    int x = 0,  y = 0, check, check_pred;
    string const_window = window;
    if (x1 != x2 && y1 != y2){
        check_pred = check_pred_func( x1, y1, x2, y2);
        for (int i = 0; window[i] != '\0'; i++ ){
            check = (x-x1)*(y2-y1)-(y-y1)*(x2-x1);
            if (( check >= -1*check_pred && check <= check_pred)  && window[i] != '\n')
                window[i] = c;
            if ( ( y < y1 || y > y2  || (y == y1 && x != x1) || (y == y2 && x != x2)) && window[i] != '\n')//
                window[i] = const_window[i];
            if (window[i] != '\n')
                x++;
            else if (window[i] == '\n'){
                y++;
                x = 0;}}}
    else if(y1 == y2) window = horizontal_L(window, x1, x2, y1, c);
    else window = vertical_L(window, y1, y2, x1, c);
    return window;

}

bool error_L(string window, int x, int y, int x1, int y1){
    int wh = char_in_str('\n', window);
    int ww = pos_char_in_str('\n', window);
    if (x < 0 || y < 0 || x1 < 0 || y1 < 0 || x > ww || y > wh  || (x1 - x != 0 && y1 - y != 0) )
        return false;
    return true;
}

string preparation_L(string comand, string window){
    int x1, y1, x2, y2;
    char c;
    x1 = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    y1 = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    x2 = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    y2 = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    c = comand[0];
    if (x2 > pos_char_in_str('\n', window))
        x2 = pos_char_in_str('\n', window) - 1;
    if (y2 > char_in_str('\n', window))
        y2 = char_in_str('\n', window);
    if (y1 > y2){
        int sup = y1;
        y1 = y2;
        y2 = sup;}
    if (x1 > x2){
        int sup = x1;
        x1 = x2;
        x2 = sup;}
    return L(window, x1, y1, x2, y2, c);}
