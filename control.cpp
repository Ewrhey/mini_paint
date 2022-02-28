#include "mini_paint.h"
bool control_string(string a){
     string b = "1234567890";
      for(int i = 0; a[i] != '\0'; i++)
          if (pos_char_in_str(a[i], b) == -1)
              return false;
      return true;
}

bool control_char(char a){
      string b = "1234567890";
      if (pos_char_in_str(a, b) == -1)
          return false;
      return true;
}
