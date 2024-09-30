#ifndef MODELETAB_H_INCLUDED
#define MODELETAB_H_INCLUDED



void entete()
{
printf("|************************************************************************|\n");

printf("|*************************** HIS ASD3 ***********************************|\n");

printf("|******************* Projet Algorithmes de Tri **************************|\n");

printf("|************* Encadrer par Monsieur Mourad Benmalek ********************|\n");

printf("|************************************************************************|\n");

printf("|             Module : ALGORITHMIQUE ET STRUCTRE DE DONNEES 3            |\n");

printf("|             R%calis%c par :  * AIT MOKHTAR MOHAMED AMINE *               |\n",130, 130);

printf("| Travail r%calis%c sur une machine de processus :i7 11 eme CPU @ 2.80GHZ  |\n",130,130);

printf("**************************************************************************\n\n");

};


void menu()
{
    printf("[1].Creer un tableau \n \n");

    printf("[2].Tri a bulles \n \n");

    printf("[3].Tri par selection \n \n");

    printf("[4].Tri par insertion \n \n");

    printf("[5].Tri par fusion \n \n");

    printf("[6].Tri rapide \n \n");

    printf("[7].Tableau Comparatif \n \n");

    printf("[8].Quitter \n \n");
}

void menutriBulles()
{
    printf("*********Tri a Bulles********** \n \n");

    printf("[1].Tri a bulles basique \n \n");

    printf("[2].Tri a bulles ameliorer \n \n");

    printf("[3].Revenir au menue principale \n \n");

    printf("******************************* \n \n");

}



void affichtemp(float temps)
{

    printf("*******************************************\n");

    printf("Temps d'execution par (s) est : %lf s \n",temps);

    printf("*******************************************\n");

}

//Procédure qui génere des valeurs aléatoires et les affectes a chaque cases du Tableau
void genTab(int n,int T[])
{
int i;
  //Remplissage du Tableau avec des valeurs aléatoire
        for(i=0;i<n;i++)
        {
            T[i]=rand()%(100-1)+1; //rand() génère un nombre aléatoire
        }

}

//Procédure qui affiche un Tableau
void affichTab(int T[],int n)
{
  int i;
//Parcours de toute les cases avec affichage
        for(i=0;i<n;i++)
        {
            printf("| %d ",T[i] );
        }
            printf("|");
            printf("\n");

}

//Fonction qui sauvgarde les valeurs du tableau T dans un tableau Ts pour pouvoir garder les méme valeurs du tableau initial (T) lors de l'éxécution des différents tri
int sauvT(int T[],int n)
{
int *Ts; //Un pointeur Ts de type entier
int i;//indice pour parcourir chaque case du tableau T

Ts=malloc(n*(sizeof(int))); //Le pointeur Ts va pointer vers le tableau créer dynamiquement

for (i=0;i<=n;i++)
    {
     *(Ts+i)=T[i];//Chaque élement de T[i] va étre sauvgarderé dans *(Ts+i)
    }
return Ts;
}

//Procédure qui tri le tableau avec le tri a bulles
void triBulles(int T[],int n)
{
int i,j,tmp;

for(j=1;j<=n;j++)// pour faire l'operation N fois
{
    for(i=0;i<n-1;i++)
    {
        if ( T[i] > T[i+1] )//Permuter les deux élement si T[i] > T[i+1]
        {
         tmp = T[i];
         T[i] = T[i+1];
         T[i+1] = tmp;

        }
    }
}
}

//Procédure qui tri le tableau avec le tri a bulles améliorer
void triBulles2(int T[],int n)
{
int i,j,tmp,x;

x=n;
for(j=1;j<=n;j++)// pour faire l'operation N fois
{
    x=x-1;//Mettre a jour la limite supérieure pour ne plus avoir l'itération inutile comme dans la procédure (void)triBulles
    for(i=0;i<x;i++)
    {
        if ( T[i] > T[i+1] )//Permuter les deux élement si T[i] > T[i+1]
        {
         tmp = T[i];
         T[i] = T[i+1];
         T[i+1] = tmp;

        }
    }
}
}

//Procédure qui tri le tableau avec le tri par sélection
void triSelection(int T[],int n)
{
int i,j,tmp;

for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n;j++)
    {
        if ( T[i] > T[j] )
        {
            tmp = T[i];
            T[i] = T[j];
            T[j] = tmp;
        }
    }
}
}

//Procédure qui tri le tableau avec le tri par insértion
void triInsertion(int tab[],int n)
{
int i,j,tmp;

for (i=1 ; i <= n-1; i++)
{
 j = i;

    while (j > 0 && tab[j-1] > tab[j])
    {
      tmp = tab[j];
      tab[j] = tab[j-1];
      tab[j-1] = tmp;

      j=j-1;
    }
  }
}

//Procédure qui tri le tableau avec le tri par fusion
void fusion(int tab[], int debut, int milieu, int fin)
{
int n1 = milieu - debut + 1;
int n2 = fin - milieu;

int G[n1], D[n2];

for (int i = 0; i < n1; i++)
    G[i] = tab[debut + i];

    for (int j = 0; j < n2; j++)

        D[j] = tab[milieu + 1 + j];

// maintient trois pointeurs, un pour chacun des deux tableaux et un pour maintenir l'index actuel du tableau trié final
 int i, j, k;
 i = 0;
 j = 0;
 k = debut;

while (i < n1 && j < n2)
{
    if (G[i] <= D[j])
    {
     tab[k] = G[i];
     i++;
    }
    else
    {
    tab[k] = D[j];
    j++;
    }
    k++;
}

// Copiez tous les éléments restants du tableau non vide
while (i < n1)
{
 tab[k] = G[i];
 i++;
 k++;
}

while (j < n2)
{
tab[k] = D[j];
j++;
k++;
}

}

//Procedure pour le Tri par fusion
void triFusion(int tab[], int debut, int fin)
{
    if (debut < fin)
    {

    // Trouvez le point milieu pour diviser le tableau en deux moitiés
    int m = (debut + fin) / 2;

    triFusion(tab, debut, m);
    triFusion(tab, m + 1, fin);

    // Fusionnez les deux moitiés triées
    fusion(tab, debut, m, fin);
    }
}

//Fonction qui fais la division du tableau ( Pour le Tri Rapide )
int partitionner(int *tableau, int p, int r) {

    int pivot = tableau[p], i = p-1, j = r+1;
    int temp;
    while (1)
    {
        do
            j--;
        while (tableau[j] > pivot);
        do
            i++;
        while (tableau[i] < pivot);
        if (i < j)
        {
            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
        else
            return j;
    }
}

//Procédure qui tri le tableau avec le tri rapide récursivement
void triRapide(int *tableau, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partitionner(tableau, p, r);
        triRapide(tableau, p, q);
        triRapide(tableau, q+1, r);
    }
}

//Procédure pour effacer l'affichage
void clrScreen()
{
    system("cls || clear");

}

//Procédure qui affiche les différent temps d'éxecution de chaque tri
void comparatif ()
{
float t;
clock_t debut,fin;
int Taille[5]={100,1000,5000,10000,100000};
int i;
//affichTab(Taille,5);
int *T=NULL;
int *Ts;
                //AFFICHAGE DE LA PREMIERE LIGNE DU TABLEAU COMPARATIF //
printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("|   n   |");

printf("      Tri a bulles       ");

printf("| Tri a bulles ameliorer ");

printf("|    Tri par selection   ");

printf("|    Tri par insertion   ");

printf("|    Tri par fusion      ");

printf("|       Tri rapide       |\n");
printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");


for (i=0;i<5;i++)
{
T=malloc(Taille[i]*(sizeof(int)));//Création d'un Tableau dynamique
printf("|%d\t|",Taille[i]);
genTab(Taille[i],T);

Ts=sauvT(T,Taille[i]);//Sauvgarder les valeurs du tableau T dans le tableau Ts

debut=clock();
triBulles(T,Taille[i]);
fin=clock();

t=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'éxecution du tri a bulles en seconde  dans la variable temps

printf("       %f\t  |\t ",t);

T=sauvT(Ts,Taille[i]);//Remplir le tableau T avec le Tableau Ts non trié

debut=clock();
triBulles2(T,Taille[i]);
fin=clock();

t=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'éxecution du tri a bulles en seconde  dans la variable temps

printf("   %f\t   |",t);

T=sauvT(Ts,Taille[i]);//Remplir le tableau T avec le Tableau Ts non trié

debut=clock();
triSelection(T,Taille[i]);
fin=clock();

t=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'éxecution du tri a bulles en seconde  dans la variable temps

printf("        %f     ",t);

T=sauvT(Ts,Taille[i]);//Remplir le tableau T avec le Tableau Ts non trié

debut=clock();
triInsertion(T,Taille[i]);
fin=clock();

t=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'éxecution du tri a bulles en seconde  dans la variable temps

printf("   |          %f      |",t);

T=sauvT(Ts,Taille[i]);//Remplir le tableau T avec le Tableau Ts non trié

debut = clock();
triFusion(T,0,Taille[i]-1);
fin=clock();

t=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'éxecution du tri par Fusion en seconde  dans la variable temps


printf("       %f         |   ",t);

T=sauvT(Ts,Taille[i]);//Remplir le tableau T avec le Tableau Ts non trié

debut = clock();
triRapide(T, 0, Taille[i]-1);
fin=clock();

t=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'éxecution du tri Rapide en seconde  dans la variable temps

printf("     %f        |\n",t);

printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

}
}
#endif // MODELETAB_H_INCLUDE|
