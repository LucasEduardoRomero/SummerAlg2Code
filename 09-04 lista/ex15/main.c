#include <stdio.h>      
#include <string.h>

#define FILE_NAME "sales"
#define AUX_FILE_NAME "aux"
typedef struct Sale{
  int codigo_vendedor;
  char nome_vendedor[20];
  float valor_da_venda;
  int mes;  
} Sale;

// Return the amount of a specific register in a file
// Return -1 case error
int countRegisters(char* file_name, int register_size){
  FILE* file = fopen(file_name, "rb");
  int count_registers = -1;
  if( file ){
    fseek(file, 0, SEEK_END);
    long int file_size = ftell( file );
    if( file_size >= register_size){
      count_registers = file_size/register_size;
    }
  } 
  fclose( file ); 
  return count_registers;
}

int main(){ 

  int option = 0;
  printf("Welcome to Sales Manager\n");
  do{
    do{
      printf("1 - Create the file\n2 - Include a sale in the file\n3 - Exclude a specific seller\n4 - Alter the value of a sale\n5 - Print all registered sales\n6 - Exclude the file (DANGER)\n7 - Finish the program\nOption: ");  
      scanf("%d", &option);
    }while( option < 1 || option > 7);
    switch ( option ){

      case 1: {
        FILE* file = fopen(FILE_NAME,"wb");
        if( file ){          
          printf("Success creating the file!");
        }else{
          printf("Failed creating the file!");
        }
        printf("\n.\n.\n");
        fclose( file );
        break;
      }

      case 2: {
        int registers_number = countRegisters(FILE_NAME, sizeof(Sale));
        FILE* file = fopen(FILE_NAME, "rb+");
        if( file ){
          struct Sale sale;          
          printf("Type the seller code: ");
          scanf("%d", &sale.codigo_vendedor );
          printf("Type the seller name: ");
          scanf("%s", sale.nome_vendedor );
          printf("Type the sale value: ");
          scanf("%f", &sale.valor_da_venda );
          printf("Type month number of the sale: ");
          scanf("%d", &sale.mes );
          
          //File already has sales
          if( registers_number > 0){
            int registerIsValid = 1;
            Sale sales[registers_number];
            fread(sales, sizeof(Sale), registers_number , file);  
            for(int count=0; count < registers_number; count++){
              if( sales[count].codigo_vendedor == sale.codigo_vendedor && sales[count].mes == sale.mes){
                registerIsValid = 0;
                break;
              }
            }
            // if the seller code and sale month is diferent
            if( registerIsValid ){
              FILE* replacedFile = fopen( AUX_FILE_NAME, "wb");
              if( replacedFile ){
                int count;
                int registered = 0;
                for(count=0; count < registers_number; count++){
                  if( (sales[count].codigo_vendedor > sale.codigo_vendedor && registered == 0) || (sales[count].codigo_vendedor == sale.codigo_vendedor && sales[count].mes > sale.mes && registered == 0) ){
                    fwrite( &sale, sizeof(sale), 1, replacedFile);
                    fwrite( &sales[count], sizeof(sales[count]), 1, replacedFile); 
                    registered = 1;
                  }else{
                    fwrite( &sales[count], sizeof(sales[count]), 1, replacedFile);
                  }                  
                } 
                if( !registered ){
                  fwrite( &sale, sizeof(sale), 1, replacedFile);
                }
                fclose( replacedFile );
                fclose( file );
                remove( FILE_NAME );
                rename(  AUX_FILE_NAME, FILE_NAME );
              }
            }else{
              //if the seller code and sale month is repeated
              printf("\n.\n.\nFailed. The seller code and sale month is already registered");
            }
          }else{
          //File dont has any sale
            fwrite(&sale, sizeof(sale), 1, file);
          }
        }
        fclose(file);
        printf("\n.\n.\n");
        break; 
      } 

      case 3: {
        FILE* file = fopen( FILE_NAME, "rb");
        if( file ){
          char name[20];
          printf("Type the name of the seller: ");
          scanf("%s", name);
          int deleted = 0;
          FILE* auxFile = fopen( AUX_FILE_NAME, "wb");
          int register_amount = countRegisters(FILE_NAME, sizeof(Sale));
          struct Sale sale;
          for(int index=0; index < register_amount; index++ ){
            fread( &sale, sizeof(Sale), 1, file);
            if( strcmp( sale.nome_vendedor, name) != 0){
              fwrite( &sale, sizeof(sale), 1, auxFile );
            }
          }
          fclose( file );
          fclose( auxFile );
          remove( FILE_NAME );
          rename(  AUX_FILE_NAME, FILE_NAME );
          printf("\n.\nSuccess Deleting Seller!\n");
        }else{
          fclose(file);
        }
        printf("\n.\n.\n");
        break;        
      }

      case 4: {
        FILE* file = fopen( FILE_NAME, "rb+");
        if( file ){
          int seller_code,sale_month;
          float sale_value;
          int altered = 0;
          struct Sale sale;
          printf("Type the Seller Code: ");
          scanf("%d", &seller_code);
          printf("Type the Sale month: ");
          scanf("%d", &sale_month);
          printf("Type the new Sale Value: ");
          scanf("%f", &sale_value);
          int amount_register = countRegisters(FILE_NAME, sizeof(Sale));
          for(int count=0; count < amount_register; count++ ){
            fread( &sale, sizeof(Sale), 1, file);
            if( sale.codigo_vendedor == seller_code && sale.mes == sale_month ){
              altered = 1;
              sale.valor_da_venda = sale_value;
              fseek(file, -sizeof(Sale), SEEK_CUR);
              fwrite( &sale, sizeof(sale), 1, file);
              break;
            }
          }
          if( altered ){
            printf("\n.\nSuccess editing the sale value!\n");
          }else{
            printf("\n.\nFailed editing the sale value!\n");
          }
        }
        fclose(file);
        break;
      }

      case 5: {
        int registers_number = countRegisters(FILE_NAME, sizeof(Sale));
        if( registers_number > 0){
          FILE* file = fopen(FILE_NAME, "rb");
          if( file ){
            Sale sales[registers_number];
            fread(sales, sizeof(Sale), registers_number, file);
            printf("\n----------------\n");
            for(int index=0; index < registers_number; index++){
              printf("Register %d\nSeller Code: %d\nSeller Name %s\nSale value: R$ %.2f\nSale Month: %d\n----------------\n", (index+1), sales[index].codigo_vendedor, sales[index].nome_vendedor, sales[index].valor_da_venda, sales[index].mes);
            }            
          }
          fclose(file);          
        }
        break;
      }

      case 6: {
        int result = remove( FILE_NAME );
        if( !result ){
          printf("\n.\nSuccess removing file!\n");
        }else{
          printf("\n.\nFailed removing the file!\n");
        }
        break;
      }

      default:
        break;
    }
  }while( option != 7 );
  return 0;
}