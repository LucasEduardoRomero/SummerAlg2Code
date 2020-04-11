#include <stdio.h>      
#include <string.h>

#define FILE_NAME "cadastro.txt"

int main(){

  char name[15];
  char number[12]; 
  FILE *file = fopen(FILE_NAME, "w");
  if( file ){
    while(1){
    printf("Type the name: ");
    scanf("%s", name);
    printf("Type the number like 99999999 : ");
    scanf("%s", number);
    if( strcmp(number, "0") == 0 ){
      break;
    }
    fprintf(file, "%s %s\n", name, number);
    }
  }  
  return 0;
}