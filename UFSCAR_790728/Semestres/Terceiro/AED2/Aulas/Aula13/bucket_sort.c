#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lim_inf 0
#define SIZE 1000000
#define lim_sup SIZE
#define TRUE 1
#define FALSE 0

typedef struct celula{
    double chave;
    struct celula *prox;

}Celula;


void bucketSort ( double v [] , int n ) {
    int i , j ;
    Celula * p , * nova , * morta ;
    Celula ** baldes = ( Celula **) malloc ( n * sizeof( Celula *));


    // inicializando cada balde com uma lista com nó cabeça
    for ( j = 0 ; j < n ; j ++) {
        
        baldes [ j ] = ( Celula *) malloc (sizeof( Celula ));
        baldes [ j ]-> prox = NULL ;
    
    }
    // coloca cada elemento no balde correspondente
    for ( i = 0 ; i < n ; i ++) {
    
        // j = (int)(v[i] * n);
        j = ( int )(( double )( v [ i ] - lim_inf ) / ( lim_sup - lim_inf ) * n );
        p = baldes [ j ];
        // já insere o elemento na ordem correta dentro do balde
        while ( p -> prox != NULL && p -> prox -> chave < v [ i ])
            
            p = p -> prox ;
            nova = ( Celula *) malloc (sizeof( Celula ));
            nova -> chave = v [ i ];
            nova -> prox = p -> prox ;
            p -> prox = nova ;

    }

    // põe os elementos dos baldes de volta no vetor
    i = 0 ;
    for ( j = 0 ; j < n ; j ++) {

        p = baldes [ j ]-> prox ;

        while ( p != NULL ) {
            v [ i ] = p -> chave ;
            i ++;
            p = p -> prox ;
        }
    } 
    // libera os baldes
    for ( j = 0 ; j < n ; j ++) {
        p = baldes [ j ];
        
        while ( p != NULL ) {
            morta = p ;
            p = p -> prox ;
            free ( morta );
        }
    }

    free ( baldes );
} 

void imprimeVetor(double v[],int tam){

    for(int i=0;i<tam;i++){
        printf("%lf,",v[i]);
    }
}

int checa(FILE *arquivo){

    double v1,v2;
    int para = FALSE;
    int contador=0;
    arquivo = fopen("compara.txt","r+");
    while(!para && fread(&v1,sizeof(double),1,arquivo)){
      if(contador > 0 && contador < SIZE-1)
          if(v1<v2)
            para = TRUE;
      
      contador++;
      v2 = v1; 
  }
  fclose(arquivo);

  return !para;
}


int main(){

    int i;

    double v[SIZE];
    FILE *arquivo = (FILE*)malloc(sizeof(FILE));
    arquivo = fopen("opa.txt","r+");

   /*for (i = 0; i < SIZE; i++)
  {
    v[i] = rand() % SIZE;
    fwrite(&v[i],sizeof(double),1,arquivo);
  }*/
    i=0;
  while(fread(&v[i],sizeof(double),1,arquivo)){
      i++;
  }




    clock_t t = clock();
    bucketSort(v,SIZE);
    t = clock() - t;
     double tempo = ((double)t)/((CLOCKS_PER_SEC/1000));
    printf("TEMPO = %.2lf segundos\n",tempo);
  
    fclose(arquivo);

    arquivo = fopen("compara.txt","w+");

    for (i = 0; i < SIZE; i++)
  
        fwrite(&v[i],sizeof(double),1,arquivo);
  
    fclose(arquivo);

    printf("%d\n",checa(arquivo));




  return 0;



}