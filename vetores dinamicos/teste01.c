#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array_list_int.h"

int main(){
    time_t inicio,fim;
    int n,i,x,erro;
    array_list_int *l01 = array_list_create();
    scanf("%d",&n);
    inicio = time(0);
    for ( i=0 ; i<n ; ++i ){
        scanf("%d",&x);
        if (array_list_push_back(l01,x)!=(i+1)){
            fprintf(stderr,"\033[0;31mErro:\033[0m:\tValor %d não inserido!\n",x);
            fprintf(stderr,"\tA lista possui %d elementos.\n",array_list_size(l01));
            exit(1);
        }
    }
    fim=time(0);
    fprintf(stderr,"Inserção de %d elementos em %.4lf milisegundos.\n",
                 n,(((double)fim-(double)inicio)/CLOCKS_PER_SEC)*1000);
    printf("%d\n",array_list_size(l01));
    for ( i=0 ; i<array_list_size(l01) ; ++i){
        x = array_list_get(l01,i,&erro);
        if (!erro){
            printf("%d ",x);
        } else {
            fprintf(stderr,"ERRO: índice %d não é válido!\n",i);
            exit(2);
        }
    }
    printf("\n");
    return 0;
}