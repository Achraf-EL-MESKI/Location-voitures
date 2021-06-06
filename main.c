#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Structs.h"
#include "Menus.h"
#include "Operations.h"
int (*listeFonctions[3])() = {Location,GestionVoitures,GestionClients};
//void (*Fonctions_Location[1])(FILE *rep) = {visualiser};/*,louer,retourner,modifier,supprimer};*/
//void (*Fonctions_GesVoi[4])(FILE *rep) = {Lister,Ajouter,Modifier,Supprimer};
//void (*Fonctions_Gescli[4])(FILE *rep) = {LISTER,AJOUTER,MODIFIER,SUPPRIMER};


int main()
{
    int id ;

    FILE *contracts , *cars , *tenants;

    cars = fopen("Voitures.txt", "a+");
    tenants = fopen("Clients.txt", "a+");
    contracts = fopen ("ContratsLocations.txt", "a+");

    int choix,(*functionAdress)() , choice;
    printf("\n     ========================================\n");
    printf("                   BIENVENUE :)\n");
    printf("     ========================================\n\n");
	do
    {
        printf("\n                Menu Principal        \n\n\n");
        printf("     Location..............................1\n");
        printf("     Gestion voitures......................2\n");
        printf("     Gestion clients.......................3\n");
        printf("     Quitter...............................4\n");
        printf("\n\n                Votre choix : ");
        scanf("%d",&choix);
        printf("\n\n");
    }
    while(choix<1 || choix>4);
    printf("      ========================================\n");
    if(choix==4)
    {
        printf("      Merci d'avoir utiliser notre service :)\n");
        printf("      ========================================\n\n");
        exit(1);
    }
    else functionAdress=listeFonctions[choix-1];
    choice = functionAdress();
    switch(choix){
       /*  e 1 : switch (choice){

              case 1 : visualiser(contracts);
                      break ;
              case 2 : lou
        } 
		while(choice!=6) Location();*/
          case 2 : switch(choice){

               case 1 : Lister(cars);
                        break ;
               case 2 : Ajouter(cars);
                        break ;


          }
          while (choice!=5) GestionVoitures();
          break ;
          case 3 : switch(choice){
               case 1 : LISTER(tenants);
                        break ;
               case 2 : AJOUTER(tenants);
                        break ;
               case 3 : MODIFIER(tenants , id);
                        break ;

          }
          while(choice!=5) GestionClients();
          break;
    }



    return 0;
}
