#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*Polje strutura (squadova) koja u sebi imaju vise space marinaca,
prilikom saveanja overwriteat sve u postojecoj datoteci*/

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


	}
	return 1;

}



SMSquad* dodavanjeSquada(SMunit* unit) {

	unit->squads = (SMSquad*)realloc(unit->squads, unit->sAmount + 1);


	printf("\nUnesite squad number : ");
	scanf("%d", &unit->squads[sAmount].squadNumber);
	printf("\nUnesite marine count : ");
	scanf("%d", &unit->squads[sAmount].marineCount);
	printf("\nUnesite squad type");
	scanf("%16s", unit->squads[sAmount].squadType);

	for (int i = 0; squads->marineCount; i++) {

		

		return squads;

	}

}



void inputSquada() {

	int i;
	int j;
	
	for (i = 0; i < sAmount; i++) {

		printf("\n\nUnesite squad number : ");

		printf("\nUnesite marine count : ");
		
		printf("\nUnesite squad type : ");


		for (j = 0; j < squads.marineCount; j++) {

			printf("\nUnesite ime : ");
			scanf("%63[^\n]", SMunit->squads[sAmount].marineArray[j].name);
			printf("\nUnesite rank : ");
			scanf("%31[^\n]", SMunit->squads[sAmount].marineArray[j].rank);
			printf("\nUnesite company : ");
			scanf("%31[^\n]", SMunit->squads[sAmount].marineArray[j].company);
			printf("\nUnesite age : ");
			scanf("%d", SMunit->squads[sAmount].marineArray[j].age);
			printf("\nUnesite years of service : ");
			scanf("%d", SMunit->squads[sAmount].marineArray[j].yearsOfService);
			printf("\nUnesite speciality");
			scanf("%15[^\n]", SMunit->squads[sAmount].marineArray[j].speciality);

		}

	}

}


SMSquad* sRead(char* imeDatoteke) {

	FILE* input = fopen(imeDatoteke, "rb");
	if (input == NULL) {
		exit(EXIT_FAILURE);
	}

	int sAmount;
	fread(&sAmount, sizeof(int), 1, input);

	SMSquad* squadArray = (SMSquad*)malloc(sAmount * sizeof(SMSquad));

	fread(squadArray, sizeof(SMSquad), sAmount, input);

	fclose(input);

	return squadArray;

}



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
