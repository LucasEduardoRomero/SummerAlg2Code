#include <stdio.h>
#include <string.h>

#define CAMINHO_ARQUIVO "./vendas.dat"

typedef struct cadastraVenda {
  int codigo;
  char nome[50];
  float valorVenda;
  char mes[20];
} cadastraVenda;

void cadastrarVenda( int c, char n[50], float v, char m[50] ){
  FILE* file;
  file = (FILE*) fopen( CAMINHO_ARQUIVO, "wb");
  struct cadastraVenda venda;
  venda.codigo = c;
  venda.valorVenda = v;
  strcpy(venda.nome, n);
  strcpy(venda.mes, m);
  fwrite( &venda, sizeof(struct cadastraVenda), 1, file );
  fclose(file);
}

int main(){
  int op;
  int codigo = 0;
  float valorVenda;
  char nome[50];
  char mes[50];
  char meses_default[13][20];
  int codigos[5];
  int meses[5];
  for(int i =0; i<5;i++){
    codigos[i] = -1;
    meses[i] = -1;
  }
  strcpy(meses_default[1],"Janeiro"); 
  strcpy(meses_default[2],"Fevereiro"); 
  strcpy(meses_default[3],"Março"); 
  strcpy(meses_default[4],"Abril"); 
  strcpy(meses_default[5],"Maio"); 
  strcpy(meses_default[6],"Junho"); 
  strcpy(meses_default[7],"Julho"); 
  strcpy(meses_default[8],"Agosto"); 
  strcpy(meses_default[9],"Setembro"); 
  strcpy(meses_default[10],"Outubro"); 
  strcpy(meses_default[11],"Novembro"); 
  strcpy(meses_default[12],"Dezembro"); 
  
  do{
    printf("Digite o Código do vendedor: ");
    scanf("%d", &codigo );
  }while(codigo <= 0);
  codigos[0] = codigo;
    
  printf("Digite o nome do vendedor: ");
  scanf("%s", nome );

  printf("Digite o valor da venda: ");
  scanf("%f", &valorVenda);
  do{
    printf("Digite o mes da venda:\n1 - Janeiro      12 - Dezembro\n");  
    scanf("%d", &op);  
  }while(op < 1 || op > 12);
  strcpy(mes,meses_default[op]);
  meses[0] = op;


  cadastrarVenda(codigo, nome, valorVenda, mes);
  for(int cont =1; cont<5; cont++){ 
    do{
      printf("Digite o Código do vendedor: ");
      scanf("%d", &codigo );
    } while(codigo <= 0);
    
    printf("Digite o nome do vendedor: ");
    scanf("%s", nome );

    printf("Digite o valor da venda: ");
    scanf("%f", &valorVenda);
    do{
      printf("\nDigite o mes da venda:1 - Janeiro   12- Dezembro\n");
      scanf("%d", &op);
    }while(op < 1 || op > 12);
    strcpy(mes,meses_default[op]);
  
    for(int i =0; i < 5; i++){      
      if( (codigos[i] > 0) && (meses[i] > 0) && (codigos[i] == codigo) && (strcmp(mes,meses_default[meses[i]]) == 0) ){
        printf("Esse cadastro nao e valido\n");
      }else{
        cadastrarVenda( codigo, nome, valorVenda, mes );    
      }
    }
  }

  return 0;

}