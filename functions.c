#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int provjeraDatoteke(char* imeDatoteke) {

        FILE* input = fopen(imeDatoteke, "rb+");

        printf("Funkcija provjera datoteke");

        if (input == NULL) {
                printf("\nNe postoji datoteka, kreiranje datoteke...");

                FILE* input = fopen(imeDatoteke, "wb+");

                if (input == NULL) {
                        printf("\nGreska u kreiranju datoteke");
                        exit(EXIT_FAILURE);
                }

                fclose(input);

        }

        else {

                fclose(input);

                return 1;
        }

}

void dodavanje(char* imeDatoteke) {

        FILE* input = fopen(imeDatoteke, "wb+");

        if (input == NULL) {
                perror("Dodavanje u datoteku.");
                exit(EXIT_FAILURE);
        }

        SpaceMarine temp;

        printf("\nUnesite ime : ");
        scanf("%63[^\n]", temp.name);
        printf("\nUnesite rank : ");
        scanf("%31[^\n]", temp.rank);
        printf("\nUnesite company : ");
        scanf("%31[^\n]", temp.company);
        printf("\nUnesite age : ");
        scanf("%d", &temp.age);
        printf("\nUnesite years of service : ");
        scanf("%d", &temp.yearsOfService);
        printf("\nUnesite speciality");
        scanf("%15[^\n]", temp.speciality);


}

void zatvaranje() {
        exit(EXIT_SUCCESS);
}
