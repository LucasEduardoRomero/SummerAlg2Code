#include <stdio.h>

#define FILE_CAT "file_cat.txt"

void fileCat(char* firstFile, char* secondFile){

  FILE* file;
  FILE* fileCat;
  file = fopen( firstFile, "r");
  fileCat = fopen(FILE_CAT, "w");
  if( (file) && (fileCat)){
    char buffer;
    fscanf(file, "%c", &buffer);
    while( !feof(file) ){
      fprintf(fileCat, "%c", buffer );
      fscanf(file, "%c", &buffer);     
    }    
    fclose(file);

    file = fopen( secondFile, "r");
    if( (file) ){
      fscanf(file, "%c", &buffer);
      while( !feof(file) ){
      fprintf(fileCat, "%c", buffer );
      fscanf(file, "%c", &buffer);     
      }      
    }
    fclose(file);    
  }
  



  
  fclose(fileCat);
}


int main(){

  char firstFile[25];
  char secondFile[25];
  printf("Type the first file: ");
  scanf("%s", firstFile );
  printf("Type the second file: ");
  scanf("%s", secondFile );

  fileCat(firstFile, secondFile);
  
  return 0;
}