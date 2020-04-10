#include <stdio.h>
/*
MMC(5,2) >
2
MMC(5,1) >
2
3
4
5
MMC(1,1) >
  >
10
*/

int mmc(int x, int y){
    for(int z=2;x>=z || y >= z;z++){
        if( ((x%z)==0) && ((y%z)==0)){
            return z*mmc(x/z,y/z);
        }else{
            if( ((x%z)==0) && ((y%z)!=0)){
                return z*mmc(x/z,y);
            }else{
                if( ((x%z)==0) && ((y%z)==0) ){
                    return z*mmc(x,y/z);
                }else{
                    if( x==1 && y==1){
                        return 1;
                    }
                }
            }
        }
    }   
}


int main(){

    int x= 5;
    int y=2;
    int res = mmc(x,y);
    printf("%d \n", res);
    
    return 0;
}



// OUTRO ALGORITMO

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