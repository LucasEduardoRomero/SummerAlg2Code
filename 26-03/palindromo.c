#include <stdio.h>
#include <string.h>

int main(){

    char texto[51],inv[51];
    printf("Digite a string a ser testada\n");
    scanf("%[^\n]",texto);
    int contEspaco,contLetras,contNumeros=0;
    for(int x = 0; texto[x] != '\0'; x++){
        while(texto[x] == ' '){
            contEspaco++;
            for(int y = x; texto[y] != '\0'; y++){
                texto[y] = texto[y + 1];
            }
        }
    }    
    int tamanho = strlen(texto);
    for(int i=0;i<tamanho;i++){
        if((texto[i] >=65 && texto[i] <=90) ||(texto[i] >=97 && texto[i] <=122)){
            contLetras++;
        }else{
            if(texto[i] >=48 && texto[i]<=57){
                contNumeros++;
            }
        }
        inv[i] = texto[tamanho-i-1];
    }
    inv[tamanho] = '\0';
    printf("--------------\n");

    if(strcmp(inv,texto) == 0){
        printf("palindromo\n");
    }else{
        printf("não palindromo\n");
    }

    printf("%d espaços em branco\n",contEspaco);
    printf("%d letras\n",contLetras);
    printf("%d numeros\n",contNumeros);
    


    return 0;
}