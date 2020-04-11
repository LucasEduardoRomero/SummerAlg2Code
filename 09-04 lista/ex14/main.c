#include <stdio.h>      
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"
#define NAME_MAX_LENGTH 41

int main(){ 
  int numberOfStudents;
  printf("Type the amount of students: ");
  scanf("%d", &numberOfStudents);

  //allocating a dynamic array of strings
  char** names = (char**) malloc( numberOfStudents*sizeof(char*));
  for(int count=0; count<numberOfStudents; count++){
    names[count] = (char*) malloc( NAME_MAX_LENGTH * sizeof(char) );
  }
  //alocating a dynamic array of strings
  float* finalGrade = (float*) malloc( numberOfStudents*(sizeof(float)));

  FILE* file = fopen(FILE_NAME, "w");
  if( file ){
    for(int count=0; count < numberOfStudents; count++){
      printf("Type the name of the student %d:", (count+1)); 
      while ((getchar()) != '\n');
      scanf("%[^\n]", names[count]);
      names[count][40]='\0';
      while ((getchar()) != '\n');
      printf("Type the final grade of the student %d:", (count+1));
      scanf("%f", &finalGrade[count]);
    }
    for(int count=0; count<numberOfStudents; count++ ){
      fprintf(file, "%s", names[count]);
      int iterations = 40-strlen(names[count]);
      for( int i=0;i< iterations; i++){
        fprintf(file," ");
      }
      fprintf(file, " %.2f\n",finalGrade[count]);
    }
    fclose(file);
  }
  return 0;
}