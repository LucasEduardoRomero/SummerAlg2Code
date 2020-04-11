#include <stdio.h>      
#include <string.h>

#define FILE_NAME "emp.txt"
#define NUMBER_OF_EMPLOYEES 5
int main(){ 
  FILE* file = fopen(FILE_NAME, "w");
  if( file ){
    char name[15];
    int serviceYears;
    for(int count=0; count<NUMBER_OF_EMPLOYEES; count++){
      printf("Type the name of the employee: ");
      scanf("%s", name);
      printf("Type the amount of service years of the employee: ");
      scanf("%d", &serviceYears);
      fprintf(file, "%s %d\n", name, serviceYears);
    }
    fclose(file);
    
    file = fopen(FILE_NAME, "r");
    if( file ){
      printf("\n----------------------------\n");
      for(int count=0; (count<NUMBER_OF_EMPLOYEES) && (!feof(file)); count++ ){
        fscanf(file, "%s %d", name, &serviceYears);
        printf("Employee %d\nName = %s\nYear of Service = %d\n--------------------\n", (count+1), name, serviceYears);
      }
    }
  }
  return 0;
}