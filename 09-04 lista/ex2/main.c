#include <stdio.h>


int countLines( char* name ){
  FILE* file = fopen(name, "r");
  int countLines = 0;
  char buffer;
  while( !feof(file) ){
        fscanf(file, "%c", &buffer);
    if( buffer == '\n' ){
      countLines++;
    }
  }
  if(buffer != '\n'){
    countLines++;
  }
  return countLines;
}

int main(){

  char name[25];
  printf("Type the file name: ");
  scanf("%s", name);  
  int lines = countLines( name );
  printf("file has %d line(s)\n", lines);
}