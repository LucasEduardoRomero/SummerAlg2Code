#include <stdio.h>

int main(){

    int f1,f2,f3;
    int d1,d2,d3 = 100000;
    int f,d;
    int cont = 0;
    do{
        printf("Digite o numero do empregado: ");
        scanf("%d", &f);
        do{
        printf("Digite a quantia de meses: ");
        scanf("%d",&d);
        }while(d==d1 || d==d2 || d==d3);
            
        if((d!=0 && f!=0)){
            if(d < d1){
                d3 = d2;
                d2 = d1;
                d1 = d;
                f3 = f2;
                f2 = f1;
                f1 = f;            
            }else{
                if( d < d2 ){
                    d3 = d2;
                    d2 = d;
                    f3 = f2;
                    f2 = f;                
                }else{
                    if(d < d3){
                        d3 = d;
                        f3 = f;
                    }
                }
            }
        }
    }while(d!=0 && f!=0);
    
    printf("Empregados mais recentes: ");
    printf("codigo: %d --- meses: %d\n",f1,d1);
    printf("codigo: %d --- meses: %d\n",f2,d2);
    printf("codigo: %d --- meses: %d\n",f3,d3);


    return 0;
}