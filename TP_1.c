#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int Code;
    char Designation[30];
    float Prix;
    int Quantite;
} Articles;
int N = 0;
Articles TA[100];
void AjoutA(Articles A) {
    for (int i = 0; i < N; i++) {
        if (TA[i].Code == A.Code) {
            printf("Article avec ce code existe deja\n");
            return;
        }
    }
                printf("Designation : ");
                scanf("%s", A.Designation);
                printf("Prix : ");
                scanf("%f", &A.Prix);
                printf("Quantite : ");
                scanf("%d", &A.Quantite);
    TA[N] = A;
    N++;
    printf("Article ajoute\n");
printf("*************************************************************\n");
}
void AfficherA(int cd){
    for(int i = 0 ; i < N ; i++){
        if(TA[i].Code == cd){
            printf("designation : %s \n",TA[i].Designation);
            printf("Prix : %.2f \n",TA[i].Prix);
            printf("Quantite : %d \n",TA[i].Quantite);
        printf("*************************************************************\n");
        }else{
        printf("pas de Articles avec ce code");
        }
    }
}

void VenteA(int cd , int qt){
    for(int i = 0 ; i < N ; i++){
        if(TA[i].Code == cd){
                if( qt <= TA[i].Quantite){
                    TA[i].Quantite = TA[i].Quantite - qt;
                    printf("Vente Validee");
                }else{

                printf("Quantite est faible ");
                }
        }else{
                printf("pas d'Article avec ce code");
        }
    }
}
float Mtotale(int cd){

        float totale;

        for(int i = 0 ; i < N ; i++){

        if(TA[i].Code == cd ){

                totale = TA[i].Quantite * TA[i].Prix;
                printf("Mtotale est : %.2f ",totale);

        }else{

                printf("pas d'Articles evec ce code");

        }
        }

}
void Supprimer(){

    for(int i = 0 ; i < N ; i++){

           if(TA[i].Quantite == 0){

                for(int j = i ; j < N ; j++){

                    TA[j] = TA[j+1];
                }
                N--;
                printf("Les Articles avec qt = 0 est supprimer\n");

            }else{
                printf("pas des Articles avec qt = 0");
            }
        }
}
void QMin(int s){

        for(int i = 0 ; i < N ; i++){

            printf("les Artilces ayant une QMin de %d sont de code :  \n",s);

            if(TA[i].Quantite < s){

                printf(" %d \n",TA[i].Code);

            }else{

            printf("pas des Articles ayant une QMin de %d",s);

            }



        }

}
void Afficher(){

        printf("Les articles Enregistrer : \n");

    for(int i = 0 ; i < N ; i++){
            for(int j = 1 ; j < N ; j++){

                printf("Articles num %d\n",j);
            }

        printf("Code : %d\n",TA[i].Code);
        printf("designation : %s\n",TA[i].Designation);
        printf("prix : %.2f\n",TA[i].Prix);
        printf("quantite : %d\n",TA[i].Quantite);

    }

}

int main() {
    Articles A;
    int choix;
    int CODE;
    int qt;
    int s;

    do {
        printf("\n1- Ajouter un article\n");
        printf("2- Afficher un article\n");
        printf("3- Operation de vente\n");
        printf("4- Montant Total des articles\n");
        printf("5- Supprimer les articles ayant une quantite nulle\n");
        printf("6- Afficher les articles inferieurs au seuil min.\n");
        printf("7- Afficher la liste des articles\n");
        printf("0- Quitter\n");
        printf("*************************************************************\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        printf("*************************************************************\n");

        switch (choix) {
            case 1:
                printf("Code : ");
                scanf("%d", &A.Code);
                AjoutA(A);
                break;

            case 2:
                printf("donner code : ");
                scanf("%d",&CODE);
                AfficherA(CODE);
                break;

            case 3:
                printf("code : ");
                scanf("%d",&CODE);
                printf("qt : ");
                scanf("%d",&qt);
                VenteA(CODE,qt);
                break;

            case 4:
                printf("code : ");
                scanf("%d",&CODE);
                Mtotale(CODE);
                break;

            case 5:
                Supprimer();
                break;

            case 6:
                printf("donner la Quantite QMin  : ");
                scanf("%d",&s);
                QMin(s);
                break;
            case 7:
                Afficher();
                break;



       }

        }while(choix != 0);




    return 0;
}
