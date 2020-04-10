#include <stdio.h>
#include <string.h>

void toLower(char* texto){
    int tamanho = strlen(texto);
    for(int c=0;c<tamanho;c++){
        if(texto[c] >= 65 && texto[c] <= 90){
            texto[c] += 32; 
        }
    }
}


int retirarEspacos(char* texto){    
    int contEspaco = 0;
    for(int x = 0; texto[x] != '\0'; x++){
        while(texto[x] == ' '){
            contEspaco++;
            for(int y = x; texto[y] != '\0'; y++){
                texto[y] = texto[y + 1];
            }            
        }
    }  
    texto[strlen(texto)] = '\n';
    return contEspaco;  
}


int limparTexto(char* texto){
    int x=1;
    int sobrenomes = 0;
    //pegar primeira letra
    while( texto[x] != '\0' && texto[x] != ' ' ){
       texto[x] = ' ';
        x++;
    }

    x++;    
    while(sobrenomes != 1){       
             
        //primeira posicao da palavra a ser testada                    
        int aux = x;

        //eh conectivo
        if( !((texto[aux] == 'e' && texto[(aux+1)] == ' ') || (texto[aux] == 'd' && (texto[aux+2] == ' '|| texto[aux+3] == ' ')))  ){

            //nao
            //eh ultima palavra ?
            while(texto[aux] != ' '){
                if( texto[aux] == '\0' || texto[aux] == '\n'){
                    printf("\n vamos retirar alguns espaços ! \n");
                    retirarEspacos(texto);
                    return 1;
                }else{
                    aux++;
                }
            }
            x++;
            while( texto[x] != ' ' ){
                texto[x] = ' ';
                x++;
            }
            x++;
            sobrenomes++;                
        }else{
            while( texto[x] != ' ' ){
                texto[x] = ' ';
                x++;
            }
            x++;
        }
    }
    // estamos na ultima palavra? senao, pular pra ela. 
    while(sobrenomes > 0){
        int aux = x;
        //eh conectivo
        if ( ((texto[aux] == 'e' && texto[(aux+1)] == ' ') || (texto[aux] == 'd' && (texto[aux+2] == ' ' || texto[aux+3] == ' ' ))) ){
            while( texto[x] != ' ' ){
                texto[x] = ' ';
                x++;
            }
            x++; 
        }else{
            int posicao = aux;
            while(texto[aux] != ' '){
                if( texto[aux] == '\0' || texto[aux] == '\n'){
                    retirarEspacos(texto);
                    return 1;
                }else{
                    aux++;
                }
            }
            while(posicao != aux){
                texto[posicao] = ' ';
                posicao++;
            }
            x++;
        }
    }

}




int main(){

    char in[50];
    char nome[50];
    char login[50];
    int res = 0;    

    printf("Digite o nome: ");
    scanf("%[^\n]", in);
    strcpy(nome, in);

    toLower(in);
    res = limparTexto(in);
    strcpy(login, in);
    printf("\n---------");
    printf("\nNome = %s",nome);
    printf("\nLogin = %s",login);
    printf("---------\n");
    return 0;
}