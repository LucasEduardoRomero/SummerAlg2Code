#include <stdio.h>      

int myPow(int base, int exp){
  int resp=base;
  if(exp == 0){
    return 1;
  }
  for(int i=1; i<exp; i++){
    resp = resp*base;
  }
  return resp;
}

int intToBin( int decimal ){
  int res = 0;
  int index = 0;
  while( decimal != 0 ){ 
    res = res+(myPow( 10, index )*(decimal%2));
    decimal = decimal/2;
    index++;    
  }
  if( index == 0 ){
    if( decimal == 1 ){
      return 1;
    }else{
      return 0;
    }
  }
  return res;
}

int main(){
  int n;  
  printf("Type the amount of numbers: ");
  scanf("%d", &n);
  int numbers[n];
  for(int i =0;i<n;i++){
    printf("Type the number %d to be converted: ", (i+1));
    scanf("%d", &numbers[i]);
  }
  FILE *file = fopen("file.txt", "w");
  for(int i=0;i<n; i++){
    fprintf(file, "%d\n", intToBin(numbers[i]));
  }   
  return 0;
}