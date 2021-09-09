#include "IO.h"
#include "Marine.h"
#include <string.h>

int fileCheck(const char* fileName) {

	printf("Checking the filename...\n");

	FILE* file = fopen(fileName, "rb");

	if (file == NULL) {
		printf("\nThe file does not exist, creating the file...");

		file = fopen(fileName, "wb");
		if (file == NULL) {
			printf("\nError with creating the file");
			exit(EXIT_FAILURE);
		}

		int squadAmount = 0;
		fwrite(&squadAmount, sizeof(int), 1, file);

		fclose(file);

	}
	else {
		fclose(file);
	}

	return 1;

}

int readSQAmount(const char* fileName) {
	FILE* input = fopen(fileName, "rb");
	if (input == NULL) {
		perror("Error getting squad amount from file");
		exit(EXIT_FAILURE);
	}

	int sqaudAmount;
	fread(&sqaudAmount, sizeof(int), 1, input);

	fclose(input);

	return sqaudAmount;
}

SMSquad* userInputSquad(int squadNumber) {
	system("cls");


	SMSquad* newSquad = (SMSquad*)malloc(sizeof(SMSquad));
	if (newSquad == NULL) {
		perror("Error with creating a new squad");
		exit(EXIT_FAILURE);
	}

	newSquad->squadNumber = squadNumber;

	printf("\Enter the squad name (128 characters max) : ");
	scanf("%128s", newSquad->squadName);

	do {
		// Enter squad type
		printf("\n\nEnter the SQUAD TYPE : ");
		printf("\n 1. Assault Squad");
		printf("\n 2. Support Squad");
		printf("\n 3. Tactical Squad\n");
		scanf("%d", &newSquad->squadType);
	} while (newSquad->squadType < 1 || newSquad->squadType > 3);

	// Enter marine count in squad
	printf("\n\nEnter the MARINE COUNT of the squad : ");
	scanf("%d", &newSquad->marineCount);

	newSquad->marinesArray = (SM*)malloc(newSquad->marineCount * sizeof(SM));
	if (newSquad->marinesArray == NULL) {
		perror("Error creating marrines array.");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < newSquad->marineCount; i++) {
		printf("\nEnter the NAME of the %d. Space Marine (64 characters max) : ", i + 1);
		scanf("%64s", newSquad->marinesArray[i].name);

		do {
			printf("\nEnter the RANK of the %d. Space Marine : ", i + 1);
			printf("\n 1.Battle Brother");
			printf("\n 2.Sergeant");
			printf("\n 3.Lieuetenant");
			printf("\n 4.Captain");
			printf("\n 5.Vanguard\n");
			scanf("%d", &newSquad->marinesArray[i].rank);
		} while (newSquad->marinesArray[i].rank < 1 || newSquad->marinesArray[i].rank > 5);

		
		do {
			printf("\nEnter the AGE of the %d. Space Marine : ", i + 1);
			scanf("%d", &newSquad->marinesArray[i].age);
		} while (newSquad->marinesArray[i].age < 18 || newSquad->marinesArray[i].age > 80);

		do {
			printf("\nEnter the YEARS OF SERVICE of the %d. Space Marince : ", i + 1);
			scanf("%d", &newSquad->marinesArray[i].yearsOfService);
		} while (newSquad->marinesArray[i].yearsOfService > newSquad->marinesArray[i].age || newSquad->marinesArray[i].age < 0);
	}

	return newSquad;

}

SMSquad* readSquadsFromFile(const char* fileName) {

	/*Ova funkcija cita zapisane squadove (polje squadova) u datoteci. Namjenjena je spremati ono sto procita u privremeno polje squadova.*/

	FILE* input = fopen(fileName, "rb");
	if (input == NULL) {
		exit(EXIT_FAILURE);
	}

	int squadAmount;
	fread(&squadAmount, sizeof(int), 1, input);

	if (squadAmount == 0) return NULL;

	SMSquad* ReadSquadArray = (SMSquad*)malloc(squadAmount * sizeof(SMSquad));
	if (ReadSquadArray == NULL) {
		perror("SMSquad pointer ReadSquadArray is NULL, dynamic memory allocation failed during reading.");
		exit(EXIT_FAILURE);
	}

	system("cls");

	for (int i = 0; i < squadAmount; i++) {

		fread(&ReadSquadArray[i], sizeof(SMSquad), 1, input);

		ReadSquadArray[i].marinesArray = (SM*)malloc(ReadSquadArray[i].marineCount * sizeof(SM));
		if (ReadSquadArray[i].marinesArray == NULL) {
			perror("Can not create marine array from sRead function.");
			exit(EXIT_FAILURE);
		}

		fread(ReadSquadArray[i].marinesArray, sizeof(SM), ReadSquadArray[i].marineCount, input);

	}

	fclose(input);

	return ReadSquadArray;

}

void writeSquadsToFile(const char* fileName, SMSquad* squads, int squadAmount) {

	FILE* output = fopen(fileName, "wb");
	if (output == NULL) {
		exit(EXIT_FAILURE);
	}

	fwrite(&squadAmount, sizeof(int), 1, output);

	int i;
	for (i = 0; i < squadAmount; i++) {
		fwrite(&squads[i], sizeof(SMSquad), 1, output);
		fwrite(squads[i].marinesArray, sizeof(SM), squads[i].marineCount, output);

	}

	fclose(output);
	
}

void printAvailableSquads(SMSquad* squads, int squadAmount) {
	system("cls");
	if (squadAmount == 0) {
		printf("No squads.\n");
		return;
	}

	int i, j;

	for (i = 0; i < squadAmount; i++) {
		//printf("Squad Name: %s. Squad id number %d.\n", squads[i].squadName, squads[i].squadNumber);
		printf("\n\n===%d. Squad===", i + 1);
		printf("\nSquad name : %s", squads[i].squadName);
		printf("\nSquad number : %d", squads[i].squadNumber);
		printf("\nSquad type : ");
		switch (squads[i].squadType) {
		case 1:
			printf("Assault Squad");
			break;
		case 2:
			printf("Support Squad");
			break;
		case 3:
			printf("Tactical Squad");
			break;
		default:
			printf("Unknown");
			break;
		}
		for (j = 0; j < squads[i].marineCount; j++) {
			printf("\n\n\t===%d. Marine===", j + 1);
			printf("\n\tName : %s", squads[i].marinesArray[j].name); //puca ovdje nakon sto se prog restartira
			printf("\n\tRank : ");
			switch (squads[i].marinesArray[j].rank) {
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
			printf("\n\tAge : %d", squads[i].marinesArray[j].age);
			printf("\n\tYears of service : %d", squads[i].marinesArray[j].yearsOfService);
		}
	}

	/*for (i = 0; i < squadAmount; i++) {
		
	}*/

	printf("\n\nPress any key to continue.");
	system("pause");
	getchar();
}

int getValidSquadNumber(int maxAmount) {
	int id;
	do {
		printf("Enter valid id: ");
		scanf("%d", &id);
	} while (id < 0 || id >= maxAmount);
	return id;
}

void print(SMSquad* squad) {

	printf("\n===============%d. SQUAD===============", squad->squadNumber);
	printf("\nSquad name: %s.", squad->squadName);
	printf("\nSquad type: %d.", squad->squadType);
	printf("\nMarine count: %d.", squad->marineCount);
	printf("\n=======Marines in the %d. squad=======\n", squad->squadNumber);
	for (int i = 0; i < squad->marineCount; i++) {
		
		printf("\nName: %s", squad->marinesArray[i].name);
		printf("\nRank: %d", squad->marinesArray[i].rank);
		printf("\nAge :%d", squad->marinesArray[i].age);
		printf("\nYears of Service : %d\n", squad->marinesArray[i].yearsOfService);
	}

	printf("====End of marines of the %d. squad====\n\n", squad->squadNumber);
}
