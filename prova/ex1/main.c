#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define ITERACOES 5

typedef struct Ingredientes{
  char nome[26];
  int quantidade;
} Ingredientes;

typedef struct Receita{
  char nome[26];
  int quant_ingredientes;
  struct Ingredientes** ingredientes;  
} Receita;

int main(){

  struct Receita receitas[ITERACOES];
  for(int index=0; index < ITERACOES; index++){
    char garbage;
    if(index != 0){
      scanf("%c", &garbage);
    }
    printf("Digite o nome da receita: ");    
    scanf("%[^\n]", receitas[index].nome ); scanf("%c", &garbage);  
    receitas[index].nome[ strlen(receitas[index].nome) ] = '\0';
    printf("Digite a quantidade de ingredientes: ");
    scanf("%d", &receitas[index].quant_ingredientes );
    
    receitas[index].ingredientes = (Ingredientes**) malloc( receitas[index].quant_ingredientes * sizeof(Ingredientes*));
    for(int j=0; j<receitas[index].quant_ingredientes; j++){
      receitas[index].ingredientes[j] = (Ingredientes*) malloc( 1*sizeof(Ingredientes));
    }
    
    for(int j=0; j<receitas[index].quant_ingredientes; j++){
      printf("Digite o nome do ingrediente: "); 
      scanf("%c", &garbage);
      scanf("%[^\n]", receitas[index].ingredientes[j]->nome );
      scanf("%c", &garbage);
      receitas[index].ingredientes[j]->nome[ strlen(receitas[index].ingredientes[j]->nome) ] = '\0';
      printf("Digite a quantidade do ingrediente: ");
      scanf("%d", &receitas[index].ingredientes[j]->quantidade);
    }
  }

  while ((getchar()) != '\n');
  char nome_receita[25];
  int contador = 0;
  do{
    char garbage;
    printf("\n-----PROCURAR RECEITAS-----\n");
    printf("Digite o nome da receita: ");    
    scanf("%[^\n]", nome_receita );  
    scanf("%c", &garbage);    
    nome_receita[ strlen(nome_receita) ] = '\0';
    if( strcmp(nome_receita, "") != 0  ){
      for(int count=0; count<ITERACOES; count++){
        if( strcmp(nome_receita, receitas[count].nome) == 0){
          printf("Nome da Receita: %s\nQuantidade de Ingredientes: %d\n", receitas[count].nome, receitas[count].quant_ingredientes);
          for( int j=0; j< receitas[count].quant_ingredientes; j++){
            printf("- %s X %d\n", receitas[count].ingredientes[j]->nome, receitas[count].ingredientes[j]->quantidade );
          }
          break;
        }else{
          if( ITERACOES-count == 1){
            printf("\nPerdão, não encontramos a receita!\n");
          }
        }
      }
    }
    contador++;
  }while( strcmp(nome_receita, "") != 0 );




  return 0;
}