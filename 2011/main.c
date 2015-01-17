#include <stdio.h>
#include <stdlib.h>
#define R1 ((char) 'R')

int main()
{

    const char carac[5] = {'A','B','C','D','E'};
    const int table[5] = {81,82,3,4,5};
    int a=3, b=2, c=1;
    printf("carac[5] :  %d\n", carac[5]);
    printf("%c\n",table[4]);

    if(0){printf("lalalalla");}
    if(c){printf("ok 1\n");}

    if((a=b) || (a=c++)){
        printf("ok 2 \n");
        printf("entré dans la boucle :a=%d, b=%d, c=%d\n",a,b,c);
        a=a+b++;
        printf("apres calcul : a=%d, b=%d\n",a,b);
    }

    if((b=c*b)>c)
        c+= a + ++b;
    printf("Q4 : a=%d, b=%d, c=%d\n",a,b,c);

    c=a*5 +((a<<2) & b);
    printf ("Q5 : a=%d, b=%d, c=%d\n",a,b,c);

    return 0;
}
