#include"mini_paint.h"

void save_func(string window){
    ofstream result;
    result.open("result_operation_file.it");
    result << window;
    result.close();
}

int choice_color(string color){
if (color == "RGB_R")
    return 4;
else if (color == "RGB_G")
    return 2;
else if (color == "RGB_B")
    return 1;
else
    return 15;
}

void cout_color(string str, int color){
SetColor(color, 0);
cout << str << endl;
SetColor(15, 0);
}

    int main(int argc, char *argv[]){
    string way = "";
    bool save = false;
    if (argc == 1) cin >> way;
    else if(argc == 2) way = argv[1];
    else if(argc == 3 && argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's' && argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e'){
        way = argv[1];
        save = true;
    }
    else
        cout_color("Error: a lot of arguments", 4);
    main_2 (way, save);
    return 0;}

int main_2 (string way, bool save){
    string comand, window, color;
    ifstream file(way);
    if (file.is_open()){
        getline(file, comand);
        bool check_window = work_space_error(comand);
        window = work_space_preparation(comand);
        char wind_c_con = window[0];
        while (getline(file, comand) && check_window){
            color = itc_slice_str(comand, itc_len(comand) - 5, 100);
            comand = itc_slice_str(comand, 0, itc_len(comand) - 7);
            //cout << comand<< endl;
            window = choice(comand, window, wind_c_con);
            cout_color(window, choice_color(color));
            }
        if (!check_window)
            cout_color("Error: invalid data work_space", 4);
        if (save)
            save_func(window);
        file.close();}
    else if (way[itc_len(way) - 1] != 't' || way[itc_len(way) - 2] != 'i' || way[itc_len(way) - 3] != '.')
            cout_color("Error: Operation file has not correct extension", 4);
    else
        cout_color("Error: Operation file corrupted", 4);
    return 0;}
