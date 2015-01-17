#include <stdio.h>
#include <stdlib.h>


typedef struct {
char * buf; /*!< tableau contenant les données écrites puis lues*/
int to_be_read; /*!< tête de lecture : indice du prochain élément à être lu dans le tableau. */
int to_be_written; /*!< tête d'écriture : indice du prochain élément pouvant être remplidans le tableau*/
int lockW; /*!< verrou en écriture : vaut 1 si toutes les cases du tableau attendent d'être lues,vaut 0 sinon*/
int size; /*!< taille du tableau*/
}Buffer;

int main()
{
    printf("Hello world!\n");
    return 0;
}

int init_buffer(int n,Buffer* b1){
    b1->to_be_read=0;
    b1->to_be_written=0;
    b1->lockW=0;

    char * c=NULL;
    c=(char*) calloc(sizeof(char),n);
    if(c==NULL){
    b1->size=0;
    fprintf(stderr,"Erreur MORRAY");
    return 1;
    }
    b1->size=n;
    b1->buf=c;
    return 0;
}

void free_buffer(Buffer* b){
    free(b->buf);
}

void print_buffer(Buffer* b){
    int i=0;
    for(i=0;i<(b->size);i++){
        printf("buf[%d] : %c ",i,*(b->buf+i));
    }
    printf("\nEtat : %d\n",b->lockW);
    printf("Tete de lecture  : %d\n",b->to_be_read);
    printf("Tete d'écriture : %d\n",b->to_be_written);
}

int read_next(char c, Buffer* b){
    if(((b->to_be_read)=!(b->to_be_written)) ||
    (((b->to_be_read)==(b->to_be_written)) && (b->lockW)==1)){
        c=*(b->buf+b->to_be_read);
        if(b->to_be_read==b->size-1){
            b->to_be_read=0;
        }
        else {
            (b->to_be_read)++;
        }
        return 1;
    }
    return 0;
}

int write_next (char c, Buffer* b){
    if(b->lockW==1){
        return 0;
    }

    *(b->buf+b->to_be_written)=c;
    if(b->to_be_written==b->size-1){
            b->to_be_written=0;
        }
        else {
            (b->to_be_written)++;
        }
    if(b->to_be_read==b->to_be_written){
        b->lockW=1;
    }
    return 1;
}
