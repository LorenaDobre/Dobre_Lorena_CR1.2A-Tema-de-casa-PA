#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_CARTI 10000

struct Carte
{
    char titlu[100];
    char autor[100];
    int nr_pagini;
}biblioteca[MAX_CARTI];

void adauga_carte(struct Carte **carti, int *numar_carti);
struct Carte generareCarte();
void introducere_aleatorie(struct Carte **carti, int *numar_carti) ;
void distribuieCarti(struct Carte **carti, int *numar_carti, struct Carte **cartiAngajat1, struct Carte **cartiAngajat2, struct Carte **cartiAngajat3);
void afisare_carti_angajati(struct Carte **carti_angajat1, struct Carte **carti_angajat2, struct Carte **carti_angajat3, int numarCartiAngajat1, int numarCartiAngajat2, int numarCartiAngajat3);

#endif

