#include"mini_paint.h"
int itc_len(string str){
 int i = 0, counter = 0;
 while (str[i] != '\0'){
    i++;
    counter++;
 }
 return counter;
 }

int char_in_str(char c, string str){
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            counter++;
    return counter;
}
int pos_char_in_str(char c, string str){
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return -1;
}
string itc_slice_str(string str, int start, int end_){
if(end_ < start)
    return str;
else if(end_ > itc_len(str)-1)
    end_ = itc_len(str)-1;
string str1 = "";
while (start <= end_){
    str1 += str[start];
    start++;
}
return str1;
}
void SetColor(int a, int bg) {
    HANDLE pr = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(pr, (WORD)((bg << 4) | a));}

