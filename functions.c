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
		printf("\nUnesite pocetni broj squadova : ");
		scanf("%d", &squadAmount);
		fwrite(&squadAmount, sizeof(int), 1, input);

		//pocetnoDodavanjeSquada(imeDatoteke);



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



void pocetnoDodavanjeSquada(char* imeDatoteke, int squadAmount) { //dinamicki alocirati polje squadova ovdje za squadAmount broj clanova, prilikom dodavanja novih clanova otvoriti file na append nacin, pregaziti prvi int (coutner) sa novim odnosno squadAmount++ i onda appendirati na kraj novi squad.

	system("cls");

	printf("\nUnesite pocetne squadove u datoteku : ");

	int i, j;

	SMSquad* TempSquadArray = (SMSquad*)malloc(squadAmount * sizeof(SMSquad)); //dinamicka alokacija temp polja squadova
	if (TempSquadArray == NULL) {
		perror("SMSquad pointer tempsquadarray je NULL, dinamicka alokacija se nije mogla izvrsiti kod pocetnog dodavanja");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < squadAmount; i++) { //prolazak kroz polje squadova

		printf("\n\nUnesite broj marinaca u %d. squadu : ", i + 1);
		scanf("%d", &(TempSquadArray + i) -> marineCount);

		(TempSquadArray + i)->marinesArray = (SM*)malloc((TempSquadArray + i)->marineCount) * sizeof(SM);
		
		for (j = 0; j < (TempSquadArray + i) -> marineCount; j++) { //prolazak kroz polje marinaca

			//Kako doci do marinesArray koji je vec u strukturi?

			printf("\nUnesite ime %d. Space Marinca.", j + 1);
			fgets((TempSquadArray + i)->(marinesArray + j)->name, 16, stdin);

			printf("\nUnesite rank %d. Space Marinca.", j + 1);
			printf("\n 1.Battle Brother");
			printf("\n 2.Sergeant");
			printf("\n 3.Lieuetenant");
			printf("\n 4.Captain");
			printf("\n 5.Vanguard\n");
			scanf("%d", &((TempSquadArray + i) -> (TempMarineArray+ j) -> rank));

			printf("\nUnesite starost %d. Space Marinca : ", j + 1);
			scanf("%d",&((TempSquadArray + i)->(TempMarineArray + j)->age));

			printf("\nUnesite godine u sluzbi %d. Space Marinca", j + 1);
			//scanf("%d", );
		}

		printf("\n\nUnesite tip %d. Space Marine squada : ", i + 1);
		printf("\n 1. Assault Squad");
		printf("\n 2. Support Squad");
		printf("\n 3. Tactical Squad");
		
		scanf("%d", &(TempSquadArray + i) -> squadType);
	}

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



//ovoj funkciji se predaje marine rank odnosno,
//nekakav SMSquad[i] -> marinesArray[j] -> rank. Broj rank se ovdje prevodi u 
//string koji ce biti ispisan na ekran a zapisan je kao broj.
/*char* rankDecoding(char* imeDatoteke, ) {

	/*switch()
		
	default:
		return unknown string;



}*/



/*void dodavanjeSquada(char* imeDatoteke) {

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

}*/



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



/*void brisanjeSquada() {



}*/



/*Ova funkcija cita zapisane squadove (polje squadova) u datoteci. Namjenjena je spremati ono sto procita u privremeno polje squadova koje ce
vrlo vjerovatno predati funkciji sWrite na kraju programa kada se sve stvari obave na njoj, koja sve to zapisuje u datoteku preko postojecih informacija*/
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
	array_of_squads [1, 2, 3, 4, 5]
		
		1. squad => array of space marines [sm1, sm2, sm3, sm4] {

				sm1 => space marine info

			squad info
		}

		2. squad...{

		}


}

*/
