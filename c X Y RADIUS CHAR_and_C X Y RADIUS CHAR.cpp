#include"mini_paint.h"

string c(int x, int y, int r, char ch, string a){
          int n = x + 1, h, f, s = pos_char_in_str('\n', a) + 1;
          a[(y * s) - s + x - 1 - (r - 0) * s] = ch;
          a[(y * s) - s + x - 1 + (r - 0) * s] = ch;
    for (int i = 0; i < r; i++)
    {
            h = x - 1;
            f = n;
            a[(y * s) - s + f - 1 - (r - i) * s] = ch;
            a[(y * s) - s + h - 1 - (r - i) * s] = ch;
            a[(y * s) - s + f - 1 + (r - i) * s] = ch;
            a[(y * s) - s + h - 1 + (r - i) * s] = ch;
        n = n + 1;
        x = x - 1;
    }

    a[(y * s) - s + f - 1] = ch;
    a[(y * s) - s + x - 1] = ch;
       return a;
}

string C(int x, int y, int r, char ch, string a)
{

    int n = x + 1, s = pos_char_in_str('\n', a) + 1;
    for (int i = 0; i < r; i++)
    {
        for (int h = x - 1; h != n + 1; h++)
        {
            a[(y * s) - s + h - 1 - (r - i) * s] = ch;
        }
        for (int h = x - 1; h != n + 1; h++)
        {
            a[(y * s) - s + h - 1 + (r - i) * s] = ch;
        }
        n = n + 1;
        x = x - 1;
    }

    for (int h = x; h != n; h++)
    {
        a[(y * s) - s + h - 1] = ch;
    }
    return a;
}

string preparation_c_C(string comand, string window, char c_C){

    int x, y, r;
    char ch;

    x = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);

    y = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);

    r = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);

    ch = comand[0];

    if (c_C == 'c')
        return c(x, y, r, ch, window);
    else
        return C(x, y, r, ch, window);
}
