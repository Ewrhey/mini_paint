#include"mini_paint.h"

string r(string window, int x, int y, int w, int h, char c){
    for (int o = 0; o < y; o++)
        x = x + pos_char_in_str('\n', window) + 1;
    if (h > 1 && w > 1){
    for(int i = 1; i < w; i++){
        window[x] = c;
        x++;}
    for(int j = 1; j < h; j++){
        window[x] = c;
        x += pos_char_in_str('\n', window) + 1;}
    for(int i = w; i > 1; i--){
        window[x] = c;
        x--;}
    for(int j = h; j > 1; j--){
        window[x] = c;
        x -= pos_char_in_str('\n', window) + 1;}
    } else window[x] = c;
    //cout << window << endl;
    return window;
}

string R(string window, int x, int y, int w, int h, char c){
    for (int o = 0; o < y; o++)
        x = x + pos_char_in_str('\n', window) + 1;
    while (h > 0){
        for(int i = 0; i < w; i++){
            window[x] = c;
            x++;
        }
        x = x - w;
        x += pos_char_in_str('\n', window) + 1;
        h--;
    }
    //cout << window << endl;
    return window;
}

string preparation_r_R(string comand, string window, char r_R){
    int x, y, w, h;
    char c;
    x = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    y = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    w = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    h = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    c = comand[0];
    if (x + w > pos_char_in_str('\n', window))
        w = pos_char_in_str('\n', window) - x;
    if (y + h > char_in_str('\n', window))
        h = char_in_str('\n', window) - y;
    if(r_R == 'r')
        return r(window, x, y, w, h, c);
    else
        return R(window, x, y, w, h, c);
}



