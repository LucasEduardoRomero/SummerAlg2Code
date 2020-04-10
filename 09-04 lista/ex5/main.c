#include <stdio.h>
#include <string.h>

int countWords( char* name, char* word){
    int countedWords = 0;
    FILE* file = (FILE*) fopen(name, "r");
    if( file ){
      int wordLen = strlen(word);
      char firstchar = word[0];
      char buffer;      
      do{
        fscanf(file, "%c", &buffer );
        if(buffer == firstchar){
          int i =1;
          while( i < wordLen && !feof(file) ){
            fscanf(file, "%c", &buffer );
            if( word[i] != buffer ){
              if(buffer == word[0]){
                i = 0;
              }else{
                break;
              }                            
            }
            i++;
          }
          if( !feof(file) && i == wordLen ){
            countedWords++;
          }
        }
      }while( !feof(file) ); 
    }
    return countedWords;
}

int main(){

  char fileName[25];
  char word[25];
  printf("Type the file name: ");
  scanf("%s", fileName);
  printf("Type the word to search: ");
  scanf("%s", word);
  
  int wordsCounted = countWords( fileName, word);
  printf("The %s has %d times the word %s\n", fileName, wordsCounted, word);
  return 0;
}