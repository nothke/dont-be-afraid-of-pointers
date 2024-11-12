#include <stdio.h>

int main(){

   int a[]= {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   int len = sizeof(a)/sizeof(int);
   int *x = a;
   int i = 0;

   for(i = 0; i < len; i++){
      printf("Address of subscript %d = %d Value = %d\n", i, x, *x);
      x++;
   }

   return 0;
}