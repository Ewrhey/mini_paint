#include "mini_paint.h"

bool error(string comand){
    if(char_in_str(' ', comand) == 5 && (comand[0] == 'r' || comand[0] == 'R'))
        return true;
    else if(char_in_str(' ', comand) == 4 && (comand[0] == 'c' || comand[0] == 'C'))
        return true;
    else if(char_in_str(' ', comand) == 5 && comand[0] == 'L')
        return true;
    else
        return false;
}

bool work_space_error(string window){
    if(char_in_str(' ', window) != 2)
        return false;
    if (!control_string(itc_slice_str(window, 0, pos_char_in_str(' ', window) - 1)))
        return false;
    int ww = string_number(itc_slice_str(window, 0, pos_char_in_str(' ', window) - 1));
    window = itc_slice_str(window, pos_char_in_str(' ', window) + 1, 100);
    if (!control_string(itc_slice_str(window, 0, pos_char_in_str(' ', window) - 1)))
        return false;
    int wh = string_number(itc_slice_str(window, 0, pos_char_in_str(' ', window) - 1));
    if (ww > 300 || ww < 0 || wh > 300 || wh < 0)
        return false;
return true;
}
