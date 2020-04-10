#include <stdio.h>
#include <string.h>

#define NOMEARQUIVO "alunos.txt"

typedef struct TAluno{
	int cod;
	char nome[50];
	char curso[50];
	float n1;
	float n2;
} TAluno ;

/*void guardarConteudo(char* memoria){
  
}*/

int alterarNotas( int codigo, int numeroNota, int valorNota ){
  char content[500];
 // guardarConteudo( content );
  
  
  /*
  int numeroAlvo;
  int numeroAtual;
  char nomeAtual[50];
  char cursoAtual[50];  
  float nota1;
  float nota2;
  
  int linha = 0;
  /*do{
    fscanf(file, "%d %s %s %f %f", &numeroAtual, nomeAtual, cursoAtual, &nota1, &nota2);
    linha++;  
  }while((strcmp(nomeAtual, nome) != 0) && (strcmp(curso, cursoAtual) != 0));
  linha--;*/
  char teste[] = "2o";
  int linhaDesejada = 1;
  int index = 0;
  char caracter;
  do{
    caracter = teste[index];
    if(caracter == codigo){
      printf("%c", caracter);
    }
    index++; 
  }while(caracter != codigo && index <1);
  


  return 1;
}

int main(){
  char codigo;
  printf("digite o codigo do aluno: ");  
  scanf("%c", &codigo);
  int numeronota;
  printf("digite a nota que deseja altera:\n1-primeira nota    2-segunda nota\n");  
  scanf("%d", &numeronota);
  float nota;
  printf("digite a Nota do aluno: ");  
  scanf("%f", &nota);


  char buffer[500];  
  int index;
  FILE* fl;
  fl = (FILE*) fopen("alunos.txt", "r");
  do{
    fscanf(fl, "%c", &buffer[index]);
    index++;
  }while(!(feof(fl))); 
  
  buffer[index] = '\0';
  fclose(fl);  
  fl = (FILE *) fopen(NOMEARQUIVO, "w");
  if(!(fl)){ return -1; }

  int tam = strlen(buffer);
  printf( "%d",tam);
  char caracter;
  index = 0;
  do{
    caracter = buffer[index];
    if(caracter == codigo){
      int space = 0;
      do{      
        fprintf(fl, "%c", buffer[index]);
        index++;
        if(buffer[index] == (int)' ' ){
          space++;
        }
      }while(space < numeronota+2 && index < tam);
      fprintf(fl, "%c", buffer[index]);
      fprintf(fl, "%.2f", nota);
      break;
    }else{
      do{
        fprintf(fl, "%c", buffer[index]);
        index++;        
        }while(buffer[index] != '\0' && buffer[index] != '\n' && index < tam);        
        fprintf(fl, "%c", buffer[index]);        
        index++;
      }    
  }while( caracter !=  codigo && buffer[index] != '\0' && buffer[index] != '\n'  && index < tam);
  if(numeronota = 1){
    index++;
  }
  while(buffer[index] != '\n' && index < tam  && buffer[index] != ' '){
    index++;
  }
  while(index < tam-1){
    printf("%c", buffer[index]);
    fprintf(fl, "%c", buffer[index]);
    index++;
  }
  fclose(fl);

  printf("\n");
  return 0;
}