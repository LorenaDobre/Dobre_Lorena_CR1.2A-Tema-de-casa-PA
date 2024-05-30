#include <stdio.h>
#include <stdlib.h>

#include "Biblioteca.h"

int main()
{
int optiune;

char titlu[100];
   char autor[100];
   int nr_pagini;

  struct Carte **carti[MAX_CARTI];
  struct Carte **cartiAngajat1[MAX_CARTI];
  struct Carte **cartiAngajat2[MAX_CARTI];
  struct Carte **cartiAngajat3[MAX_CARTI];

  int *numar_carti = 0;
  int numarCartiAngajat1 = 0;
  int numarCartiAngajat2 = 0;
  int numarCartiAngajat3 = 0;
do {
        printf("\n===== Sistem de Management al Bibliotecii =====\n");
        printf("1. Adauga o carte manual\n");
        printf("2. Genereaza carti aleatoriu\n");
        printf("0. Iesire\n");
        printf("Alegeti o optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
              printf("Introduceti informatii despre carte:\n");
                printf("Titlu: ");
                scanf(" %99[^\n]", titlu);

                printf("Autor: ");
                scanf(" %99[^\n]", autor);

                printf("Numarul de pagini: ");
                scanf("%d", &nr_pagini);

                adauga_carte(carti,numar_carti);
                break;
            case 2:
                introducere_aleatorie(carti,numar_carti);
                break;
            case 3:
                distribuieCarti(carti, numar_carti, cartiAngajat1, cartiAngajat2, cartiAngajat3);
                afisare_carti_angajati(cartiAngajat1, cartiAngajat2, cartiAngajat3, numarCartiAngajat1, numarCartiAngajat2, numarCartiAngajat3);
                break;
            case 0:
                printf("Programul s-a incheiat.\n");
                break;
            default:
                printf("Optiune invalida!\n");
        }

    } while (optiune != 0);


    return 0;

}
