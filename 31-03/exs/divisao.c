#include <stdio.h>

/*
mod( 5, 2 )
mod( 3, 2 )
mod( 1, 2 )
return 1;
*/

int mod(int x, int y){
    if( x > y ){
        return mod(x-y, y);
    }else{
        if( x < y ){
            return x;
        }else{
            return 0;
        }
    }
}

int main(){

    int dividendo = 0;
    int divisor = 0;
    int res = 0;
    
    printf("Digite o dividendo: ");
    scanf("%d", &dividendo);
    printf("Digite o divisor: ");
    scanf("%d", &divisor);

    res = mod(dividendo, divisor);
    printf("%d MOD %d = %d \n", divisor, dividendo, res);
    return 0;
}