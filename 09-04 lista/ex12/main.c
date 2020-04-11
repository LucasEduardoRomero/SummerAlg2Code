#include <stdio.h>      
#include <string.h>

void age(int cYear, int bYear, char* rAge){
  int age = cYear - bYear;
  if(age < 18){
    strcpy(rAge, "menor de idade");
  }else{
    if(age > 18){
      strcpy(rAge, "maior de idade");
    }else{
      strcpy(rAge, "entrando na maior idade");
    }
  }
}

int main(){  
  
  char sourceFile[15];
  char outputFile[15];
  int currentYear;
  printf("Type the name of the source file: ");
  scanf("%s", sourceFile);
  printf("Type the name of the source file: ");
  scanf("%s", outputFile);
  printf("Type the current year: ");
  scanf("%d", &currentYear );

  FILE* file = fopen(sourceFile, "r");
  FILE* resultFile = fopen(outputFile, "w");
  if( file && resultFile ){

    char trash;
    char name[41];
    int birthYear;
    char representAge[30];
    
    while( !feof(file) ){ 

      for(int index=0;index < 40; index++){
        fscanf(file, "%c", &name[index] );      
      }
      name[40] = '\0';
      while( !feof(file) ){
        fscanf(file, "%c", &trash);
        if( trash != ' '){
          fseek(file, -1, SEEK_CUR);
          break;
        }
      }      
      fscanf(file, "%d", &birthYear);
      age(currentYear, birthYear, representAge);
      fprintf(resultFile, "%s %s\n", name, representAge);
      while( !feof(file) ){
        fscanf(file,"%c", &trash);
        if(trash == '\n'){
          break;
        }
      }      
    }
    fclose(resultFile);
    fclose(file);    
  }

  return 0;
}