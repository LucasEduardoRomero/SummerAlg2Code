#include <stdio.h>
 
void flipFile(char* file1, char* file2, int columns){
  FILE *file, *flipedFile;
  file = fopen(file1, "r");
  flipedFile = fopen(file2, "w");
  
  if( file && flipedFile ){
    int cont=1;
    long int lastPosition=0;  
    do{ 
      if(cont == 1){
        fseek(file, -(columns*cont) , SEEK_END);
      }else{
        fseek(file, -(columns*cont)-(cont-1), SEEK_END);
      }   
        
      lastPosition = ftell(file);
      char buffer[31];      
      for(int index=0;index<columns ; index++){       
        fscanf(file, "%c", &buffer[29-index]);
      }      
      buffer[31] = '\0';
      if( cont > 1){
        fprintf(flipedFile, "\n");
      }
      for(int index=0; index<columns;index++){
        fprintf(flipedFile, "%c", buffer[index]);
      }
      cont++;
    }while( lastPosition > 10 );    
  }
}

int main(){

  char fileName[25];
  char fileName2[25];
  printf("Type the file name: ");
  scanf("%s", fileName);
  printf("Type the file name: ");
  scanf("%s", fileName2);
  flipFile(fileName, fileName2, 30);
  return 0;
}