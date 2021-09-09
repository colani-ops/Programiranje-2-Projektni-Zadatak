#include "Marine.h"
#include "IO.h"

void addSquad(const char* fileName) {

	int squadAmount = readSQAmount(fileName);

	if (squadAmount == 0) {
		SMSquad* newSquad = userInputSquad(0);
		writeSquadsToFile(fileName, newSquad, squadAmount + 1);
	}
	else {
		SMSquad* squads = readSquadsFromFile(fileName);
		SMSquad* newSquad = userInputSquad(squadAmount);
		squads = appendToEnd(squads, newSquad, squadAmount + 1);
		writeSquadsToFile(fileName, squads, squadAmount + 1);
	}
	
}

SMSquad* appendToEnd(SMSquad* squads, SMSquad* appendSquad, int squadAmount) {
	
	SMSquad* newSquad = (SMSquad*)malloc(squadAmount * sizeof(SMSquad));
	if (newSquad == NULL) exit(EXIT_FAILURE);

	int i;
	for (i = 0; i < squadAmount - 1; i++) {
		newSquad[i].marinesArray = (SM*)malloc(squads[i].marineCount * sizeof(SM));
		if (newSquad[i].marinesArray == NULL) exit(EXIT_FAILURE);
		copySquad(&newSquad[i], &squads[i]);
		copyMarines(newSquad[i].marinesArray, squads[i].marinesArray, squads[i].marineCount);
	}

	copySquad(&newSquad[i], appendSquad);
	newSquad[i].marinesArray = (SM*)malloc(appendSquad->marineCount * sizeof(SM));
	if (newSquad[i].marinesArray == NULL) exit(EXIT_FAILURE);
	copyMarines(&newSquad[i].marinesArray, &appendSquad->marinesArray, appendSquad->marineCount);

	free(squads);
	return newSquad;
}

void removeSquad(const char* fileName) {

	int squadAmount = readSQAmount(fileName);

	if (squadAmount == 0) {
		printAvailableSquads(NULL, 0);
		return;
	}

	SMSquad* squads = readSquadsFromFile(fileName);
	printAvailableSquads(squads, squadAmount);

	int userInput = getValidSquadNumber(squadAmount);
	deleteSquad(squads, squadAmount, userInput);

	writeSquadsToFile(fileName, squads, squadAmount - 1);
}

void copySquad(SMSquad* destination, SMSquad* source) {
	destination->squadNumber = source->squadNumber;
	strcpy(destination->squadName, source->squadName);
	destination->squadType = source->squadType;
	destination->marineCount = source->marineCount;
}

void copyMarines(SM* destination, SM* source, int count) {
	for (int i = 0; i < count; i++) {
		strcpy(destination[i].name, source[i].name);
		destination[i].rank = source[i].rank;
		destination[i].age = source[i].age;
		destination[i].yearsOfService = source[i].yearsOfService;
	}
}

int deleteSquad(SMSquad* squads, int squadAmount, int deleteID) {

	SMSquad* alteredSquads = (SMSquad*)malloc((squadAmount - 1) * sizeof(SMSquad));
	if (alteredSquads == NULL) exit(EXIT_FAILURE);

	int j = 1;
	int flag = 0;

	for (int i = 0; i < squadAmount - 1; i++) {

		if (deleteID != i && flag == 0) {
			copySquad(alteredSquads + i, squads + i);

			alteredSquads[i].marinesArray = (SM*)malloc(alteredSquads[i].marineCount * sizeof(SM));
			if (alteredSquads[i].marinesArray == NULL) exit(EXIT_FAILURE);

			copyMarines(alteredSquads[i].marinesArray, squads[i].marinesArray, alteredSquads[i].marineCount);

		}
		else {
			flag = 1;

			copySquad(alteredSquads + i, squads + j);

			alteredSquads[i].marinesArray = (SM*)malloc(alteredSquads[i].marineCount * sizeof(SM));
			if (alteredSquads[i].marinesArray == NULL) exit(EXIT_FAILURE);

			copyMarines(alteredSquads[i].marinesArray, squads[i].marinesArray, alteredSquads[i].marineCount);
		}
		j++;
	}
}