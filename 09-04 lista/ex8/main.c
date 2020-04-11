#include <stdio.h>      

#define FILE_NAME "file.txt"

int main(){

  FILE *file = fopen(FILE_NAME, "r");
  if( file ){
    float totalPrice = 0;
    float buffer =0;
    char trash[25];
    while( !feof(file) ){      
      fscanf(file, "%s %f", trash,&buffer );
      totalPrice += buffer;
    }
    printf("Total price = %.2f\n", totalPrice);

  }
 

  return 0;
}