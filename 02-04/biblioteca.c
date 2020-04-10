#include <stdio.h>
#include <string.h>

#define TAMANHO_TOMBOS 20

typedef struct Tombo {
  int numeroTombo; //Chave Primaria
  char nomeObra[50];
  char nomeAutor[50];
  char nomeEditora[50];
  int codigoArea;
} Tombo;

typedef struct Obra {
  int numeroTombo; //Chave estrangeira  
  char dataCompra[11]; // YYYY-mm-dd
  int numeroExemplar;
} Obra;

void iniciarTombos( struct Tombo* tom){
  tom[0].numeroTombo = -2;
  for(int cont=1; cont<TAMANHO_TOMBOS;cont++){
    tom[cont].numeroTombo = -1;
  };    
}

void iniciarObras( struct Obra* obr){
  int tamObras = TAMANHO_TOMBOS*3;
  for(int cont=0;cont<tamObras;cont++){
    obr[cont].numeroTombo = -1;
  }
}

void listarTombos( struct Tombo* tom){
  for(int cont =0;tom[cont].numeroTombo > 0 && cont <TAMANHO_TOMBOS;cont++){
    printf("\n-------------\n");
    printf("numero do tombo: %d\n", tom[cont].numeroTombo);
    printf("nome da Obra: %s\n", tom[cont].nomeObra);
    printf("nome do autor: %s\n", tom[cont].nomeAutor);
    printf("nome da editora: %s\n", tom[cont].nomeEditora);
    printf("codigo da Area: %d\n", tom[cont].codigoArea);
    printf("\n-------------\n");
  }
}

void listarObrasArea( int ar, struct Tombo* tom){
  printf("\nOBRAS POR AREA\n");
  for(int cont =0; tom[cont].numeroTombo > 0 ;cont++){
    if( tom[cont].numeroTombo > 0 && tom[cont].codigoArea == ar){
      printf("\n-------------\n");
      printf("Numero do tombo: %d\n", tom[cont].numeroTombo);
      printf("Nome da Obra: %s\n", tom[cont].nomeObra);
      printf("Nome do Autor: %s\n", tom[cont].nomeAutor);
      printf("Nome da Editora: %s\n", tom[cont].nomeEditora);
      printf("Codigo da Área: %d\n", tom[cont].codigoArea);
      printf("\n-------------\n");
    }
  }
}

void listarObrasAutor( char* autor, struct Tombo* tom){
  printf("\nOBRAS POR AUTOR\n");
  for(int cont =0; tom[cont].numeroTombo > 0 ;cont++){
    if( strcmp(tom[cont].nomeAutor,autor) == 0){
      printf("\n-------------\n");
      printf("Numero do tombo: %d\n", tom[cont].numeroTombo);
      printf("Nome da Obra: %s\n", tom[cont].nomeObra);
      printf("Nome do Autor: %s\n", tom[cont].nomeAutor);
      printf("Nome da Editora: %s\n", tom[cont].nomeEditora);
      printf("Codigo da Área: %d\n", tom[cont].codigoArea);
      printf("\n-------------\n");
    }
  }
}

void listarObrasEditora( char* editora, struct Tombo* tom){
  printf("\nOBRAS POR EDITORA\n");
  for(int cont =0; tom[cont].numeroTombo > 0 ;cont++){
    if( strcmp(tom[cont].nomeAutor, editora) == 0){
      printf("\n-------------\n");
      printf("Numero do tombo: %d\n", tom[cont].numeroTombo);
      printf("Nome da Obra: %s\n", tom[cont].nomeObra);
      printf("Nome do Autor: %s\n", tom[cont].nomeAutor);
      printf("Nome da Editora: %s\n", tom[cont].nomeEditora);
      printf("Codigo da Área: %d\n", tom[cont].codigoArea);
      printf("\n-------------\n");
    }
  }
}

void listarObras( struct Obra* obr){
  int tamObra = TAMANHO_TOMBOS*3;
  for(int cont =0; cont<tamObra ;cont++){
    if( obr[cont].numeroTombo > 0 ){
      printf("\n-------------\n");
      printf("numero do tombo: %d\n", obr[cont].numeroTombo);
      printf("numero do exemplar: %d\n", obr[cont].numeroExemplar);
      printf("Data da compra: %s\n", obr[cont].dataCompra);
      printf("\n-------------\n");
    }
  }
}

int cadastrarTombo( struct Tombo* tom, int numeroTombo, char* nObra, char* nAutor, char* nEditora, int cArea){
  int index = 0;
  while( tom[index].numeroTombo > 0 && index < TAMANHO_TOMBOS){
    index++;
  }
  if((index == (TAMANHO_TOMBOS-1) && tom[TAMANHO_TOMBOS-1].numeroTombo < 0) || (index < TAMANHO_TOMBOS-1)){
    tom[index].numeroTombo = numeroTombo;
    strcpy(tom[index].nomeObra,nObra);
    strcpy(tom[index].nomeAutor,nAutor);
    strcpy(tom[index].nomeEditora,nEditora);
    tom[index].codigoArea = cArea;
    return 1;
  }else{
    return -1;
  }
}

int cadastrarObra( struct Obra* obr, int numeroTombo, char* dataCompra, int indiceTombo){
  int primeiroIndice;
  if(indiceTombo != 0){
    primeiroIndice = 3*indiceTombo;
  }else{
    primeiroIndice = 0;
  }
  int aux = primeiroIndice+2;
  for(int cont=primeiroIndice; aux>=cont; cont++){
    if( obr[cont].numeroTombo == -1){
      obr[cont].numeroTombo = numeroTombo;
      if( aux-cont == 0){
        obr[cont].numeroExemplar = 3;        
      }else{
        if(aux-cont == 1){
          obr[cont].numeroExemplar = 2;      
        }else{
          obr[cont].numeroExemplar = 1;
        }
      }
      strcpy(obr[cont].dataCompra, dataCompra);
      return 1;
    }
  }
  return -1;//exemplares cheios
}

int main(){
  int opcao = 0;  
  struct Tombo tombos[TAMANHO_TOMBOS];
  struct Obra obras[(TAMANHO_TOMBOS*3)];
  iniciarTombos( tombos ); 
  iniciarObras( obras);  

  while(opcao != 6){
    do{
      printf("Menu:\n1-Cadastrar tombos\n2-Cadastrar obras\n3-Mostrar obras por área\n4-Mostrar obras por autor\n5-Mostrar obras por editora\n6-Encerrar o programa\n");
      scanf("%d", &opcao);
    }while( opcao < 1 || opcao > 6);
    switch (opcao){
      case 1: ;
        //pega e valida numero do tombo
        int flagTombo = 0;
        int numeroT;        
        do{
          printf("Digite o número do tombo: ");
          scanf("%d", &numeroT); //1
          flagTombo = 1;
          if(numeroT > 0){
            for(int cNumeroTombo=0; tombos[cNumeroTombo].numeroTombo != -1;cNumeroTombo++){
              if(numeroT == tombos[cNumeroTombo].numeroTombo){
                flagTombo = 0;
                break;
              }
            }
          }else{
            flagTombo = 0;
          } 
        }while(flagTombo == 0);
        
        // pega nome obra
        char nomeObra[50];
        printf("Digite o nome da obra: ");
        scanf("%s", nomeObra);
        
        // pega nome do autor
        char nomeAutor[50];
        printf("Digite o nome do autor: ");
        scanf("%s", nomeAutor);

        // pega nome do Editora
        char nomeEditora[50];
        printf("Digite o nome da editora: ");
        scanf("%s", nomeEditora);

        // codigo area
        int codigoArea;
        do{
        printf("Digite o codigo da area:\n1-Exatas  2-Humanas  3-Biomédicas\n");
        scanf("%d", &codigoArea);
        }while(codigoArea < 1 || codigoArea > 3);

        //Guarda no registro
        int resp = cadastrarTombo( tombos, numeroT, nomeObra, nomeAutor, nomeEditora, codigoArea);
        if(resp == 1){
          printf("Inserção Realizada com Sucesso!\n\n");
          
        }else{
          if(resp == -1){
            printf("Inserção Falhou! Limite de Tomos alcançado\n\n");
          }    
        }       
        break;     
      
      case 2: ;
        // pega e valida numero do tombo
        int nTombo;
        int nTomboValido = 0;     
        int indiceTombo =0;   
        do{
          indiceTombo = 0;
          printf("Digite o numero do tombo: ");
          scanf("%d", &nTombo);
          if( nTombo > 0){
            for(int cont=0; tombos[cont].numeroTombo != -1;cont++){
              
              if( tombos[cont].numeroTombo == nTombo){
                nTomboValido = 1;
                indiceTombo--;
              }
              indiceTombo++;
            } 
          }
        }while(nTomboValido == 0);

        //data da compra
        char dCompra[11];
        printf("Digite a data da compra( YYYY-mm-dd ): ");
        scanf("%s",dCompra);

        resp = cadastrarObra( obras, nTomboValido, dCompra, indiceTombo);
        if(resp == 1){
          printf("Cadastro da Obra Realizado!\n");
        }else{
          if( resp == -1){
            printf("Cadastro falhou! Exemplares cheios!\n");
          }
        }
        break;

      case 3: ;
        int area;
        printf("Digite a área a pesquisar:\n1-Exatas  2-Humanas\n3-Biomédicas\n");
        scanf("%d", &area);        
        listarObrasArea( area, tombos );
        break;      
      
      case 4: ;
        char aut[50];
        printf("Digite o nome do autor");
        scanf("%s", aut);
        listarObrasAutor( aut, tombos );
        break;

      case 5: ;
        char edit[50];
        printf("Digite o nome da editora");
        scanf("%s", edit);
        listarObrasEditora( edit, tombos );
        break;

      default:
        // 6-sair do programa
        break;         
    }
  }
  return 0;
}