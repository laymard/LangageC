#include <stdio.h>
#include <stdlib.h>
#define TAILLE_NOM_MAX 40
#define TAILLE_FILE_MAX 30



typedef struct{
    char nom[TAILLE_NOM_MAX];
    char prenom[TAILLE_NOM_MAX];
    int anneeN;
    int anneeD;
}Individu;

int compareIndividus(Individu i1, Individu i2);
int enregistreIndividus(Individu d[], int N, char nomFichier[]);
int lireIndividus(Individu d[], char nomFichier[]);

int main()
{
    int res;
    Individu i1={"robert","dupont",1871,1913};
    Individu i2={"henri","dupond",1945,0};
    Individu i3={"irene","martin",1890,1940};
    Individu donnees[10];
    char nomFichier[TAILLE_FILE_MAX];
    donnees[0]=i1;
    donnees[1]=i2;
    donnees[2]=i3;
    Individu donnees2[10];
    //nomFichier="sauvegarde.txt"; //  a demandé
    int N=3;
    int j=0;

    enregistreIndividus(donnees,N,"sauvegarde.txt");

    res=compareIndividus(i1,i2);
    fprintf(stdout,"test %s %d\n",i1.prenom,i1.anneeD);
    printf("test 2 %d\n",donnees[0].anneeD);


    printf("Comparation de i1 et 12 : %d\n", res);
    lireIndividus(donnees2,"sauvegarde.txt");
    for(j=0;j<3;j++){
        printf("Indi %d  : %s %s %d %d\n",j,donnees2[j].prenom,donnees2[j].nom,donnees2[j].anneeN,donnees2[j].anneeD);
    }



    return 0;
}

int compareIndividus(Individu i1, Individu i2){
    int a1 = i1.anneeN;
    int a2 = i2.anneeN;

    if (a1>a2){
            return 1;
    }
    else if (a1<a2){
        return -1;
    }

    return 0;
}

int enregistreIndividus(Individu d[], int N, char nomFichier[]){
    FILE* fichier;
    int i=0;
    fichier=fopen(nomFichier,"w");
    if (fichier==NULL){
        fprintf(stderr,"Erreur morray");
        return 0;
    }

    for(i=0;i<N;i++){
        fprintf(fichier,"%s %s %d %d\n",d[i].prenom,d[i].nom,d[i].anneeN,d[i].anneeD);
    }
    fclose(fichier);
    return 1;
}

int lireIndividus(Individu d[], char nomFichier[]){
    FILE* fechier;
    int i=0;
    int res = 1;
    fechier=fopen(nomFichier,"r");
    if (fechier==NULL){
        fprintf(stderr,"Erreur morray");
        return 0;
    }
    while ((fscanf(fechier,"%s %s %d %d",&(d[i].prenom),&(d[i].nom),&(d[i].anneeN),&(d[i].anneeD)))&&i<10){
        i++;
    }
    return 1;

}



