#include "Biblioteca.h"

// Funcție pentru introducerea manuala a unei cărți
void adauga_carte(struct Carte **carti, int *numar_carti)
{
    char titlu[100];
    char autor[100];
    int nr_pagini;

    if (*numar_carti < MAX_CARTI) // Verificăm dacă există loc în bibliotecă
        {

        strcpy(biblioteca[*numar_carti].titlu, titlu);
        strcpy(biblioteca[*numar_carti].autor, autor);
        biblioteca[*numar_carti].nr_pagini = nr_pagini;
        (*numar_carti)++;
        printf("Carte adaugata cu succes.\n");
    }
    else
    {
        printf("Biblioteca este plina. Nu se pot adauga carti noi.\n");
    }
}


struct Carte generareCarte()
{
    struct Carte book;
    /// Generăm un titlu aleatoriu pentru carte
    char titlu[101];
    sprintf(titlu, "Titlu%d", rand() % 1000); // Concatenăm "Carte" cu un număr aleatoriu între 0 și 999
    strcpy(book.titlu, titlu);
    /// Generam un nume aleatoriu pentru autor
   char autor[101];
    sprintf(autor, "Autor%d", rand() % 1000); // Concatenăm "Carte" cu un număr aleatoriu între 0 și 999
    strcpy(book.autor, autor);
    /// Generăm un număr aleatoriu de pagini între 1 și 1000
    book.nr_pagini = rand() % 1000 + 1;
    return book;
}
// Funcție pentru introducerea aleatorie
void introducere_aleatorie(struct Carte **carti, int *numar_carti) {

       printf("Introduceti numarul de carti aleatorii pe care doriti sa le generati: ");
        int n;
        scanf("%d", &n);
        getchar(); // Consumăm caracterul newline

        for (int i = 0; i < n; i++) {
            *carti = realloc(*carti, (*numar_carti + 1) * sizeof(struct Carte));
            if (*carti == 0) {
                printf("Memorie insuficienta!\n");
                return;
            }
            (*carti)[*numar_carti] = generareCarte();
            (*numar_carti)++;
        }
}

void distribuieCarti(struct Carte **carti,int *numar_carti, struct Carte **cartiAngajat1, struct Carte **cartiAngajat2, struct Carte **cartiAngajat3) {
    long long pagini_totale = 0;
    for (int i = 0; i < *numar_carti; ++i) {
        pagini_totale += carti[i]->nr_pagini;
    }

    long long pagini_medii = pagini_totale / 3;

    long long pagini_angajat1 = 0, pagini_angajat2 = 0, pagini_angajat3 = 0;

    long long numarCartiAngajat1=0, numarCartiAngajat2=0, numarCartiAngajat3=0;

    for (int i = 0; i < *numar_carti; ++i)
        {
        if (pagini_angajat1 + carti[i]->nr_pagini <= pagini_medii) { ///Verificam daca primul angajat mai poate primii carti
            cartiAngajat1[numarCartiAngajat1++] = carti[i];
            pagini_angajat1 += carti[i]->nr_pagini;
        }
       else if (pagini_angajat2 + carti[i]->nr_pagini <= pagini_medii) {///Verificam daca al doilea angajat mai poate primii carti
            cartiAngajat2[numarCartiAngajat2++] = carti[i];
            pagini_angajat2 += carti[i]->nr_pagini;
        } else {
            cartiAngajat3[numarCartiAngajat3++] = carti[i];
            pagini_angajat3 += carti[i]->nr_pagini;
        }
    }
}

void afisare_carti_angajati(struct Carte **carti_angajat1, struct Carte **carti_angajat2, struct Carte **carti_angajat3, int numarCartiAngajat1, int numarCartiAngajat2, int numarCartiAngajat3) {
    ///Afisam cartile distribuite fiecarui angajat
    printf("Cărțile atribuite angajatului 1:\n");
    for (int i = 0; i < numarCartiAngajat1; ++i) {
        printf("Titlu: %s, Autor: %s, Număr pagini: %d\n", carti_angajat1[i]->titlu, carti_angajat1[i]->autor, carti_angajat1[i]->nr_pagini);
    }
    printf("\n");

    printf("Cărțile atribuite angajatului 2:\n");
    for (int i = 0; i < numarCartiAngajat2; ++i) {
        printf("Titlu: %s, Autor: %s, Număr pagini: %d\n", carti_angajat2[i]->titlu, carti_angajat2[i]->autor, carti_angajat2[i]->nr_pagini);
    }
    printf("\n");

    printf("Cărțile atribuite angajatului 3:\n");
    for (int i = 0; i < numarCartiAngajat3; ++i) {
        printf("Titlu: %s, Autor: %s, Număr pagini: %d\n", carti_angajat3[i]->titlu, carti_angajat3[i]->autor, carti_angajat3[i]->nr_pagini);
    }
    printf("\n");
}

