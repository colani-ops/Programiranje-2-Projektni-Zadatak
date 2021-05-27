#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*Polje strutura (squadova) koja u sebi imaju vise space marinaca,
prilikom saveanja overwriteat sve u postojecoj datoteci
squadAmount iznosi velicinu polja squadova odnosno broj squadova u datoteci
te bi trebao biti prvi zapisan u datoteci.*/

/*Prilikom otvaranja datoteke, u slucaju da datoteka ne postoji, korisnik unosi zeljeni broj
squadova odnosno velicinu polja squadova (prilikom dodavanja squadova se velicina polja/squad amount povecava i updatea)*/



int provjeraDatoteke(char* imeDatoteke) {

	FILE* input = fopen(imeDatoteke, "rb+");

	printf("Funkcija provjera datoteke");

	if (input == NULL) {
		printf("\nNe postoji datoteka, kreiranje datoteke...");

		FILE* input = fopen(imeDatoteke, "wb+");
		printf("\nUnesite broj squadova : ");
		scanf("%d", &squadAmount);
		fwrite(&squadAmount, sizeof(int), 1, input);

		if (input == NULL) {
			printf("\nGreska u kreiranju datoteke");
			exit(EXIT_FAILURE);
		}

		fclose(input);
	}

	else {

		fread(&squadAmount, sizeof(int), 1, input);

		fclose(input);
	}
	return 1;

}



void dodavanjeSquada(char* imeDatoteke) {

	int test;

	FILE* file = fopen(imeDatoteke, "rb+");
	if (file == NULL) {
		perror("Otvaranje datoteke.");
		exit(EXIT_FAILURE);
	}

	fread(&squadAmount, sizeof(int), 1, file);
	printf("Trenutni broj squadova je : %d", squadAmount);


	printf("\n");

	scanf("%d", &test);

}

void provjeraBrojaSquadova(char* imeDatoteke) {

	FILE* file = fopen(imeDatoteke, "rb");

	fread(&squadAmount, sizeof(int), 1, file);
	system("cls");

	printf("\nTrenutni broj squadova je : %d", squadAmount);
	printf("\n\nPress any key to continue.");
	_getch();

	fclose(file);

}



/*void inputSquada() {

	int i;
	int j;
	
	for (i = 0; i < sAmount; i++) {

		printf("\n\nUnesite squad number : ");

		printf("\nUnesite marine count : ");
		
		printf("\nUnesite squad type : ");


		for (j = 0; j < squadArray.marineCount; j++) {

			printf("\nUnesite ime : ");
			scanf("%63[^\n]", SMunit->squadArray[sAmount].marineArray[j].name);
			printf("\nUnesite rank : ");
			scanf("%31[^\n]", SMunit->squadArray[sAmount].marineArray[j].rank);
			printf("\nUnesite company : ");
			scanf("%31[^\n]", SMunit->squadArray[sAmount].marineArray[j].company);
			printf("\nUnesite age : ");
			scanf("%d", SMunit->squadArray[sAmount].marineArray[j].age);
			printf("\nUnesite years of service : ");
			scanf("%d", SMunit->squadArray[sAmount].marineArray[j].yearsOfService);
			printf("\nUnesite speciality");
			scanf("%15[^\n]", SMunit->squadArray[sAmount].marineArray[j].speciality);

		}

	}

}*/




/*SMSquad* sRead(char* imeDatoteke) {

	FILE* input = fopen(imeDatoteke, "rb");
	if (input == NULL) {
		exit(EXIT_FAILURE);
	}

	int sAmount;
	

	SMSquad* squadArray = (SMSquad*)malloc(sAmount * sizeof(SMSquad));

	fread(squadArray, sizeof(SMSquad), sAmount, input);

	fclose(input);

	return squadArray;

}*/



void sWrite(char* imeDatoteke, SMSquad* outArray, int sizeOfOutArray) {

	FILE* output = fopen(imeDatoteke, "wb");
	if (output == NULL) {
		exit(EXIT_FAILURE);
	}

	fwrite(&sizeOfOutArray, sizeof(int), 1, output);
	fwrite(outArray, sizeof(SMSquad), sizeOfOutArray, output);
	fclose(output);
}



void zatvaranje() {
	exit(EXIT_SUCCESS);
}



/*

struct unit {

	squads [1, 2, 3, 4, 5]
		
		1. squad => struct smsquad 
			[sm1, sm2, sm3, sm4]

				sm1 => struct spacemarine


}

*/
