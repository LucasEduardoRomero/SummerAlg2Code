#include <stdio.h>

int MMC(int x,int y){
	if(x > 0 & y > 0){
		for(int z=2; x>=z || y>=z; z++){
			if((x%z==0)&&(y%z==0)){
				return z*MMC(x/z,y/z);
			}
			if((x%z==0)&&(y%z!=0)){
				return z*MMC(x/z,y);
			}
			if((x%z!=0)&&(y%z==0)){
				return z*MMC(x,y/z);
				}
		}
	}else{
		return 0;
	}
}

int main(){
	
	int x,y;
  printf("Digite os dois numeros separados por espaço:\n");
	scanf("%d %d",&x,&y);
  
	printf("MMC: %d\n",MMC(x,y));
	
	return 0;
}