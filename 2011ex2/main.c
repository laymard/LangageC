#include <stdio.h>
#include <stdlib.h>
#define TAILMAX 6


int* f2(void){
    int table[] = {5,4,3,2,1,0};
    int *ptrcour, *ptri;
    int i, nbOctets;

    ptrcour = table+ TAILMAX;

    printf("ptrcour-table : %d, *table = %d, *(ptrcour-1) = %d\n",ptrcour-table, *table, *(ptrcour-1));

    ptrcour=ptri= (int *) calloc(TAILMAX, sizeof(int));
    for (i=0;i<TAILMAX;i++){
        *(ptrcour++)= TAILMAX-i-1;
        printf("i=%d, ptrcour[i]=%d\n",i,(*(ptri+i)));
    }

}


int main()
{
    int *ptrPN=(int*) NULL;
    f2();
    return 0;
}
