#include <stdio.h>

#define tamanhoPadrao 50

void stringCat(char* str1, char* str2, char* strres){    
  int i =0;
  for(i=0; str1[i]!='\0'; i++){    
    strres[i] = str1[i];
  }
  for(int j=0;str2[j] != '\0'; j++){
    strres[i] = str2[j];
    i++;
  }
  strres[i] = '\0';
}

int main(){

  char s1[tamanhoPadrao];
  char s2[tamanhoPadrao];
  char sres[(tamanhoPadrao*2)];
  char garbage;

  printf("Digite sua string: ");
  scanf("%[^\n]", s1); scanf("%c", &garbage);
  printf("Digite sua string: ");
  scanf("%[^\n]", s2); scanf("%c", &garbage);

  stringCat(s1, s2, sres);

  printf("String contatenada = %s\n", sres);
}