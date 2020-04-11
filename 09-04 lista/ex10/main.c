#include <stdio.h>      
#include <string.h>

#define RESULT_FILE_NAME "result.txt"

int dateToAge(int dtoday, int mtoday, int ytoday, int d, int m, int y){
  int age = 0;
  age = ytoday - y;
  if(mtoday < m){
    age--;    
  }else{
    if( (mtoday == m) && (dtoday < d) ){
      age--;
    }
  }
  return age;
}

int main(){  
  char filename[20];
  int dtoday, mtoday, ytoday;  
  printf("Type the file name to be opened: ");
  scanf("%s", filename);  
  printf("Type today date dd/mm/yyyy: ");
  scanf("%d/%d/%d", &dtoday, &mtoday, &ytoday);
  FILE *file = fopen(filename, "r");
  FILE *resultFile = fopen(RESULT_FILE_NAME, "w");
  if( file && resultFile ){
    int day,month,year;
    char name[15];
    while( !feof(file) ){
      fscanf(file, "%s %d %d %d", name, &day, &month, &year);
      fprintf(resultFile, "%s %d\n", name, dateToAge(dtoday, mtoday, ytoday, day, month, year));    
    }
  }
  return 0;
}