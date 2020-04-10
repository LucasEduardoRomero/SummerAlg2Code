#include <stdio.h>
#include <string.h>

typedef struct Conta{
    int conta;
    char nome[50];
    float saldo;
} Conta;

int main(){

    int cont_contas = 0;
    struct Conta contas[15];
    for(int cont=0;cont<15;cont++){
        contas[cont].conta = -1;
    }

    int flag = 0;
    while( flag != 4 ){
        
        printf("1-Cadastrar conta\n2-Visualizar todas as contas de determinado cliente\n3-Excluir a conta com menor saldo\n4-Sair\n");
        scanf("%d", &flag);
        while( flag < 1 || flag > 4 ){
            printf("1-Cadastrar conta\n2-Visualizar todas as contas de determinado cliente\n3-Excluir a conta com menor saldo\n4-Sair\n");
            scanf("%d", &flag);
        };
        switch(flag){

            char n[50];
            case 1: ;
                //pega e valida conta 
                int c,flag_conta = 0;
                do{
                    int cc = 0;
                    int flag_conta_igual =0 ;
                    flag_conta = 1;
                    printf("Digite o número da conta: ");
                    scanf("%d", &c);
                    if(c >= 0){
                        while( cc < 15 && flag_conta_igual == 0){
                            if( contas[cc].conta == c){
                                flag_conta_igual = 1;
                                flag_conta = 0;
                            }else{
                                cc++;
                            }
                        } 
                    }else{
                        flag_conta = 0;
                    }
                }while(flag_conta == 0);
                //pega nome do cliente
                printf("Digite o nome do cliente: ");
                scanf("%s", n);

                //pega e valida saldo
                float s;
                int flag_saldo = 0;
                do{
                    int cs = 0;
                    int flag_saldo_igual = 0;
                    flag_saldo = 1;
                    printf("Digite o saldo: ");
                    scanf("%f",&s);
                    while(cs < 15 && flag_saldo_igual == 0){ 
                        if( contas[cs].saldo == s){
                        flag_saldo_igual = 1;
                        flag_saldo = 0;
                        }else{
                            cs++;
                        }
                    }                    
                }while(flag_saldo == 0);  

                strcpy( contas[cont_contas].nome, n );   
                contas[cont_contas].saldo = s;
                contas[cont_contas].conta = c;
                cont_contas++;
            break;

            case 2: ;                
                printf("Digite o nome do cliente: ");
                scanf("%s", n);
                for(int i=0;i<15;i++){
                    if( strcmp( contas[i].nome, n ) == 0 ){
                        printf("\n---------\nConta %d\nCliente %s\nSaldo %.2f\n---------\n",contas[i].conta,contas[i].nome,contas[i].saldo);
                    }
                }
            break;

            case 3: ; 
                int indice =0;
                int menorSaldo=contas[0].saldo;
                for(int i=1;i<15;i++){
                    if( contas[i].conta > 0 && contas[i].saldo < menorSaldo ){
                        indice = i;
                        menorSaldo = contas[i].saldo;
                    }
                }
                contas[indice].saldo = 0;
                contas[indice].conta = -1;
                strcpy(contas[indice].nome, "");
            break;
        }

    };


    return 0;
}