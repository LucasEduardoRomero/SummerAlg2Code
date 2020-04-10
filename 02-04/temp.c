#include <stdio.h>

float menorTemp(float* vetor, int indice, float valor){
  if(indice == 12){
    if( vetor[indice] < valor){
      return vetor[indice];
    }else{
      return valor;
    }
  }else{
    if(vetor[indice] < valor){
      return menorTemp(vetor, indice+1, vetor[indice]);      
    }else{
      return menorTemp(vetor, indice+1, valor);
    }
  }
}

float maiorTemp(float* vetor, int indice, float valor){
  if(indice == 12){
    if( vetor[indice] > valor){
      return vetor[indice];
    }else{
      return valor;
    }
  }else{
    if(vetor[indice] > valor){
      return maiorTemp(vetor, indice+1, vetor[indice]);      
    }else{
      return maiorTemp(vetor, indice+1, valor);
    }
  }
}


int main(){  
  enum mes{Janeiro = 1,Fevereiro , Marco,Abril,Maio,Junho,Julho,Agosto,Setembro,Outubro0,Novembro,Dezembro}; 
  float vetor[12];
  for(int cont=0;cont<12;cont++){
    printf("digite a temperatura: ");
    scanf("%f",&vetor[cont]);
  }
  float menortemp=menorTemp(vetor, 0, vetor[0]);
  float maiortemp=maiorTemp(vetor, 0, vetor[0]);
  printf("menor temp= %f\n", menortemp);
  printf("maior temp %f\n", maiortemp);

  return 0;
}