#include <stdio.h>      
#include <string.h>

int main(){  
  
  char sourceFile[15];
  char outputFile[15];
  printf("Type the name of the source file: ");
  scanf("%s", sourceFile);
  printf("Type the name of the source file: ");
  scanf("%s", outputFile);

  FILE* file = fopen(sourceFile, "r");
  if( file ){
    long int largestPopulation = -1;
    char largestCity[41];

    char trash;
    char city[41];
    long int population;
    
    while( !feof(file) ){ 

      for(int index=0;index < 40; index++){
        fscanf(file, "%c", &city[index] );      
      }
      city[40] = '\0';
      fscanf(file, "%c", &trash);
      fscanf(file, "%li", &population);
      if( population > largestPopulation){
        largestPopulation = population;
        strcpy(largestCity, city);
      }
      while( !feof(file) ){
        fscanf(file,"%c", &trash);
        if(trash == '\n'){
          break;
        }
      }      
    }
    fclose(file);

    file = fopen(outputFile, "w");
    if( file ){
      fprintf(file, "%s %li", largestCity, largestPopulation);
    }
  }

  return 0;
}