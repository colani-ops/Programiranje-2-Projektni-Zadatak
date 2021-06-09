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

		SMSquad* TempSquadArray = pocetnoDodavanjeSquada(imeDatoteke, squadAmount);
		sWrite(imeDatoteke, TempSquadArray, squadAmount);



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



SMSquad* pocetnoDodavanjeSquada(char* imeDatoteke, int squadAmount) { //dinamicki alocirati polje squadova ovdje za squadAmount broj clanova, prilikom dodavanja novih clanova otvoriti file na append nacin, pregaziti prvi int (coutner) sa novim odnosno squadAmount++ i onda appendirati na kraj novi squad.

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
		scanf("%d", &(TempSquadArray[i].marineCount));

		TempSquadArray[i].marinesArray = (SM*)malloc((TempSquadArray[i].marineCount) * sizeof(SM));
		
		for (j = 0; j < TempSquadArray[i].marineCount; j++) { //prolazak kroz polje marinaca

			printf("\nUnesite ime %d. Space Marinca (16 znakova max) : ", j + 1);
			scanf("%16s", TempSquadArray[i].marinesArray[j].name);
			//fgets(TempSquadArray[i].marinesArray[j].name, 16, stdin);

			printf("\nUnesite rank %d. Space Marinca : ", j + 1);
			printf("\n 1.Battle Brother");
			printf("\n 2.Sergeant");
			printf("\n 3.Lieuetenant");
			printf("\n 4.Captain");
			printf("\n 5.Vanguard\n");
			scanf("%d", &(TempSquadArray[i].marinesArray[j].rank)); //_getch();

			printf("\nUnesite starost %d. Space Marinca : ", j + 1);
			scanf("%d", &(TempSquadArray[i].marinesArray[j].age)); //_getch();

			printf("\nUnesite godine u sluzbi %d. Space Marinca : ", j + 1);
			scanf("%d", &(TempSquadArray[i].marinesArray[j].yearsOfService)); //_getch();
		}

		printf("\n\nUnesite tip %d. Space Marine squada : ", i + 1);
		printf("\n 1. Assault Squad");
		printf("\n 2. Support Squad");
		printf("\n 3. Tactical Squad\n");
		
		scanf("%d", &(TempSquadArray + i) -> squadType);
	}

	return TempSquadArray;

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



void dodavanjeSquada(char* imeDatoteke) {

	SMSquad* AddSquadArray = sRead(imeDatoteke, squadAmount);

	AddSquadArray = (SMSquad*)realloc(AddSquadArray, sizeof(AddSquadArray) + sizeof(SMSquad)); //realokacija temp polja squadova za + 1 squad.
	if (AddSquadArray == NULL) {
		perror("SMSquad pointer AddSquadArray je NULL, dinamicka realokacija se nije mogla izvrsiti kod dodavanja");
		exit(EXIT_FAILURE);
	}


	system("cls");

	printf("\nUnesite squad u datoteku : ");

	int i, j;

	for (i = squadAmount; i < squadAmount + 1; i++) { //prolazak kroz polje squadova

		printf("\n\nUnesite broj marinaca u %d. squadu : ", i + 1);
		scanf("%d", &(AddSquadArray[i].marineCount));

		AddSquadArray[i].marinesArray = (SM*)malloc((AddSquadArray[i].marineCount) * sizeof(SM));

		for (j = 0; j < AddSquadArray[i].marineCount; j++) { //prolazak kroz polje marinaca

			printf("\nUnesite ime %d. Space Marinca (16 znakova max) : ", j + 1);
			scanf("%16s", AddSquadArray[i].marinesArray[j].name);
			//fgets(TempSquadArray[i].marinesArray[j].name, 16, stdin);

			printf("\nUnesite rank %d. Space Marinca : ", j + 1);
			printf("\n 1.Battle Brother");
			printf("\n 2.Sergeant");
			printf("\n 3.Lieuetenant");
			printf("\n 4.Captain");
			printf("\n 5.Vanguard\n");
			scanf("%d", &(AddSquadArray[i].marinesArray[j].rank)); _getch();

			printf("\nUnesite starost %d. Space Marinca : ", j + 1);
			scanf("%d", &(AddSquadArray[i].marinesArray[j].age)); _getch();

			printf("\nUnesite godine u sluzbi %d. Space Marinca : ", j + 1);
			scanf("%d", &(AddSquadArray[i].marinesArray[j].yearsOfService)); _getch();
		}

		printf("\n\nUnesite tip %d. Space Marine squada : ", i + 1);
		printf("\n 1. Assault Squad");
		printf("\n 2. Support Squad");
		printf("\n 3. Tactical Squad");

		scanf("%d", &(AddSquadArray + i)->squadType);
	}

	squadAmount++;

	sWrite(imeDatoteke, AddSquadArray, squadAmount);

	free(AddSquadArray);

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



/*void brisanjeSquada() {



}*/



SMSquad* sRead(char* imeDatoteke, int squadAmount) {

	FILE* input = fopen(imeDatoteke, "rb");
	if (input == NULL) {
		exit(EXIT_FAILURE);
	}
	

	squadAmount = fread(squadAmount, sizeof(int), 1, input);

	SMSquad* ReadSquadArray = (SMSquad*)malloc(squadAmount * sizeof(SMSquad));
	if (ReadSquadArray == NULL) {
		perror("SMSquad pointer ReadSquadArray je NULL, dinamicka alokacija se nije mogla izvrsiti kod sRead");
		exit(EXIT_FAILURE);
	}


	fread(ReadSquadArray, sizeof(SMSquad), squadAmount, input);

	return ReadSquadArray;

	free(ReadSquadArray);

	fclose(input);

}

/*Ova funkcija cita zapisane squadove (polje squadova) u datoteci. Namjenjena je spremati ono sto procita u privremeno polje squadova koje ce
vrlo vjerovatno predati funkciji sWrite na kraju programa kada se sve stvari obave na njoj, koja sve to zapisuje u datoteku preko postojecih informacija*/



void sWrite(char* imeDatoteke, SMSquad* outArray, int squadAmount) {

	FILE* output = fopen(imeDatoteke, "wb");
	if (output == NULL) {
		exit(EXIT_FAILURE);
	}

	fwrite(&squadAmount, sizeof(int), 1, output);
	fwrite(outArray, sizeof(SMSquad), squadAmount, output);
	fclose(output);
}



void sPrint(char* imeDatoteke) {

	SMSquad* PrintSquadArray = sRead(imeDatoteke, squadAmount);

	int i, j;

	system("cls");

	for (i = 0; i < squadAmount; i++) {

		printf("\n\n===%d. Squad===", i + 1);

		printf("\nSquad type : ");

		switch (PrintSquadArray[i].squadType) {

		case 1 :
			printf("Assault Squad");
			break;

		case 2:
			printf("Tactical Squad");
			break;

		case 3:
			printf("Support Squad");
			break;

		default:
			printf("Unknown");
				break;
		}

		for (j = 0; j < PrintSquadArray[i].marineCount; j++) {

			printf("\n\n\t===%d. Marine===", j + 1);

			printf("\n\tName : %s", PrintSquadArray[i].marinesArray[j].name);

			printf("\n\tRank : ");

			switch (PrintSquadArray[i].marinesArray[j].rank) {

			case 1:
				printf("Battle brother");
				break;

			case 2:
				printf("Sergeant");
				break;

			case 3:
				printf("Lieuetenant");
				break;

			case 4:
				printf("Captain");
				break;
			
			case 5:
				printf("Vanguard");
				break;

			default:
				printf("Unknown");
				break;

			}

			printf("\n\tAge %d", PrintSquadArray[i].marinesArray[j].age);

			printf("\n\tGodine u sluzbi : %d", PrintSquadArray[i].marinesArray[j].yearsOfService);

		}

	}

	free(PrintSquadArray);

}
 

void zatvaranje() {
	exit(EXIT_SUCCESS);
}
