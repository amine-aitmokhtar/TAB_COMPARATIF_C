#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"ModeleTab.h"

int main()
{

//variable n pour la taille du tableau T ,variable choix pour s�lectioner un choix dans switch(choix),variable bulles pour s�lectioner un choix dans switch(bulles)
int n=0;
char c,bulles,choix;

float temps;
clock_t debut,fin;//Fonction clock() pour calculer le temps d'�x�cution de chaque algorithme tri

int *Ts; // un pointeur de type entier, utiliser pour sauvgarder le tableau T
int *T=NULL;// un pointeur de type entier qui est NULL

     principale://Etiquette explication de son utilit� dans chaque appel dans le programme

     clrScreen();
     entete();
     menu();
     printf("\n");
     printf("> Taper votre Choix ");

     fflush(stdin); //fflush vide le tampon d'entr�e
     choix = (char)getche();//Affecter le seul caract�re du clavier a la variable (char)Choix qui s'affiche imm�diatement sur l'�cran de sortie sans attendre de taper la touche Entr�e.

     switch (choix)
     {
         case '1': //Cr�ation et g�nerer le tableau

                clrScreen();
                printf("choix= %c\n\n",choix);
                Tab:
                do//Boucle r�peter pour obliger l'utilisateur de renter une taille strictement > 0
                {
                 clrScreen();
                 printf("Veuillez introduire la taille du tableau\n");
                 scanf("%d",&n);
                }
                while(n<=0);

                 T=malloc(n*(sizeof(int)));//Cr�ation d'un Tableau dynamique
                 genTab(n,T);
                 printf("\n");

                 Ts=sauvT(T,n);////Sauvgarder les valeurs du tableau T dans le tableau Ts

                 printf("\n");

                 break;

          case '2': //Tri a bulles

                menuebulles:
                clrScreen();

                printf("choix= %c\n\n",choix);
                menutriBulles();
                printf("\n");

                printf("> Taper votre Choix ");

                bulles= getche();//Affecter le seul caract�re du clavier a la variable (char)bulles qui s'affiche imm�diatement sur l'�cran de sortie sans attendre de taper la touche Entr�e.

                if (n<=0) goto Tab;// Si la taille du tableau n'a pas �tais donner le goto va aller au case "1" pour pouvoir cr�er le tableau

                switch(bulles)
                {
                  case '1' ://Tri a bulles basique

                           clrScreen();
                           T=sauvT(Ts,n);//Remplir le tableau T avec le Tableau Ts non tri�

                           debut= clock();
                           triBulles(T,n);
                           fin=clock();

                           temps=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'�xecution du tri a bulles en seconde  dans la variable temps


                           affichtemp(temps);



                 break;


                  case '2'://Tri a bulles Am�liorer

                           clrScreen();
                           T=sauvT(Ts,n);//Remplir le tableau T avec le Tableau Ts non tri�

                           debut= clock();
                           triBulles2(T,n);
                           fin=clock();

                           temps=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'�xecution du tri a Bulles am�liorer en seconde  dans la variable temps


                           affichtemp(temps);

                 break;

                  case '3':
                           goto principale; //goto qui permet de revenir au menue principale

                           break;


                  default : //Si le choix taper ne vaut aucune des valeurs pr�sente dans le menue tri a bulles, le default sera ex�cuter.

                            clrScreen();
                            printf("ERROR : le choix n'existe pas \n" );
                            goto menuebulles; //goto qui permet de rester dans le menue du tri a bulle en cas de mauvaise saisie

                           break;
                }


                fflush(stdin); // flush vide le tampon d'entr�e

                printf("Pour revenir au menue du tri a bulles\n");
                system("PAUSE");
                goto menuebulles ;//goto qui permet de revenir au menue du tri a bulles apr�s avoir s�lectionn� le case 1 ou le case 2

                break;


         case '3'://Tri par S�lection
                clrScreen();
                if (n<=0) goto Tab; // Si la taille du tableau n'a pas �tais donner le goto va aller au case "1" pour pouvoir cr�er le tableau

                printf("choix = %c\n\n",choix);


                T=sauvT(Ts,n);//Remplir le tableau T avec le Tableau Ts non tri�

                debut = clock();
                triSelection(T,n);
                fin=clock();

                temps=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'�xecution du tri par S�lection en seconde  dans la variable temps


                affichtemp(temps); //Affichage du temps d'�xecution en seconde du tri par selection

                break;

         case '4'://Tri par Ins�rtion
                clrScreen();
                if (n<=0) goto Tab;// Si la taille du tableau n'a pas �tais donner le goto va aller au case "1" pour pouvoir cr�er le tableau

                printf("choix = %c\n\n",choix);

                T=sauvT(Ts,n);//Remplir le tableau T avec le Tableau Ts non tri�

                debut = clock();
                triInsertion(T,n);
                fin=clock();

                temps=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'�xecution du tri par insertion en seconde  dans la variable temps


                affichtemp(temps);//Affichage du temps d'�xecution en seconde du tri par insertion


                break;

         case '5'://Tri par Fusion
                clrScreen();
                if (n<=0) goto Tab;// Si la taille du tableau n'a pas �tais donner le goto va aller au case "1" pour pouvoir cr�er le tableau

                printf("choix = %c\n\n",choix);

                T=sauvT(Ts,n);//Remplir le tableau T avec le Tableau Ts non tri�


                debut = clock();
                triFusion(T,0, n- 1);
                fin=clock();

                temps=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'�xecution du tri par Fusion en seconde  dans la variable temps


                affichtemp(temps); //Affichage du temps d'�xecution en seconde du tri par fusion


                break;

         case '6'://Tri Rapide
                clrScreen();
                if (n<=0) goto Tab;// Si la taille du tableau n'a pas �tais donner le goto va aller au case "1" pour pouvoir cr�er le tableau

                printf("choix = %c\n\n",choix);

                T=sauvT(Ts,n);//Remplir le tableau T avec le Tableau Ts non tri�

                debut = clock();
                triRapide(T, 0, n-1);
                fin=clock();

                temps=(float)(fin-debut)/CLOCKS_PER_SEC;//Affecter la valeurs du temps d'�xecution du tri Rapide en seconde  dans la variable temps


                affichtemp(temps);//Affichage du temps d'�xecution en seconde du tri rapide


                break;

         case '7'://Tableau Comparatif
                clrScreen();
                printf("choix = %c\n\n",choix);
                printf("                                  ************************** TABLEAU COMPARATIF DU TEMPS D'EXECUTION ************************** \n \n");

                comparatif();

                printf("                                  **************************** LE TEMPS D'EXECUTION EST EN SECONDE **************************** \n \n");

                break;

         case '8'://Quitter le Programme
                exit(0);//Quitter le projet ASD3


        default: //Si le choix taper ne vaut aucune des valeurs pr�sente dans le menu, le default sera ex�cuter

                clrScreen();
                goto principale; //goto qui permet de revenir au menue principale si la valeur entrer n'est �gale a aucun des case du switch
                                // le goto principale ma permit aussi apr�s pleusieurs test d'�x�cution de faire le controle de saisie
                break;

    }

     printf("> Revenir au menue principale \n" );
     system("PAUSE");

     goto principale; //goto qui permet de revenir au menue principale mais d'abord apr�s l'�xecution d'un des case

return 0;

}





