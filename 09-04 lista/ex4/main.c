#include <stdio.h>
#include <ctype.h>

void fileLowerToUpper(char* firstFile, char* secondFile){

  FILE* file;
  FILE* fileUpper;
  file = fopen( firstFile, "r");
  fileUpper = fopen( secondFile, "w");
  if( (file) && (fileUpper)){
    char buffer,upperBuffer;
    int count=0;
    int flag=1;    
    fscanf(file, "%c", &buffer);
    while( !feof(file) ){
      upperBuffer = toupper(buffer);
      fprintf( fileUpper, "%c", upperBuffer);
      fscanf(file, "%c", &buffer);        
    }    
  }
  fclose(fileUpper);
}


int main(){

  char firstFile[25];
  char secondFile[25];
  printf("Type the file to be copied: ");
  scanf("%s", firstFile );
  printf("Type the second file: ");
  scanf("%s", secondFile );

  fileLowerToUpper(firstFile, secondFile);
  
  return 0;
}