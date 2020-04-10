#include <stdio.h>

#define MY_FILE "arq.txt"

int fileExists( char name[25]){
  int resp;
  FILE* file = fopen(name, "r");
  if(file != NULL){
    resp = 1;
  }else{
    resp = 0;    
  }
  fclose(file);
  return resp;
}

int main(){

  FILE* file;
  char mode;
  if( fileExists(MY_FILE) == 1){
    //file exists
    mode = 'a';
  }else{
    //file does not exist
    mode = 'w';
  }
  file = fopen(MY_FILE, &mode);
  if( file != NULL ){
    // user enter data
    char buffer;
    scanf("%c", &buffer);
    while( buffer != '0'){
      fprintf(file, "%c", buffer);
      scanf("%c", &buffer);
    }    
    fclose(file);

    file = fopen(MY_FILE, "r");  
    printf("\nTexto do Arquivo:\n");
    while( !feof(file) ){      
      printf("%c", buffer);
      fscanf(file, "%c", &buffer);
    }
  }
  printf("\n");
  return 0;
}