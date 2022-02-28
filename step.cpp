#include "mini_paint.h"
int step(int c){
      int b = 1;
      for(int i = c; i != 0; i--){
            b = b * 10;
      }
      return b;
}
