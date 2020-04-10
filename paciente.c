#include <stdio.h>

int main(){

    int risco, idade = 0;
    float peso = 0;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);
    printf("Digite o seu peso: ");
    scanf("%f", &peso);    

    if( idade <= 20 ){
        if( peso < 50 ){
            risco = 9;
        }else{
            if( peso < 90 ){
                risco = 8;
            }else{
                risco = 7;
            }
        }
    }else{
        if( (idade >= 21) && (idade <= 50) ){
            if( peso < 50 ){
                risco = 6;
            }else{
                if( (peso > 50) && (peso <  90) ){
                    risco = 5;
                }else{
                    risco = 4;
                }
            }
        }else{
            if( peso < 50 ){
                risco = 3;
            }else{
                if( (peso > 50) && (peso < 90) ){
                    risco = 2;
                }else{
                    risco = 1;
                }
            }
        }
    }

    printf("--------\nVocê pertence ao grupo de risco %d\n", risco);


    return 0;
}