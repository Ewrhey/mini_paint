#include"mini_paint.h"

string choice(string comand, string window, char ban_c){ // itc_len - 7
    if(error(comand)){
    char c = comand[0], reserv_c;
    comand = itc_slice_str(comand, 2, 100);
    if (comand[itc_len(comand) - 1] == ban_c){
        cout << "Attention: the background character is selected for the shape, enter a new one: " << endl;
        cin >> reserv_c;
        comand[itc_len(comand) - 1] = reserv_c;
    }
    if (c == 'r')
        window = preparation_r_R(comand, window, c);
    else if (c == 'R')
        window = preparation_r_R(comand, window, c);
    else if (c == 'c')
        window = preparation_c_C(comand, window, c);
    else if (c == 'C')
        window = preparation_c_C(comand, window, c);
    else if (c == 'L')
        window = preparation_L(comand, window);
    }
    else
        cout_color("Error: invalid comand", 4);
    return window;
}

string work_space(int w, int h, char bc){
    string window = "", sup = "";
    for (int i = w; i > 0; i--)
        sup += bc;
    sup += '\n';
    for(int j = h; j > 0; j--)
        window += sup;
    return window;
}
string work_space_preparation(string comand){
    int w, h;
    char bc;
    w = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    h = string_number(itc_slice_str(comand, 0, pos_char_in_str(' ', comand) - 1));
    comand = itc_slice_str(comand, pos_char_in_str(' ', comand) +1, 100);
    bc = comand[0];
    return work_space(w, h, bc);
}
