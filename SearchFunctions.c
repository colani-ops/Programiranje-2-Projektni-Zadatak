#include "Search.h"
#include "Marine.h"
#include "IO.h"
#include <string.h>

void findByName(const char* fileName, int validSquadID) {
	SMSquad* squads = readSquadsFromFile(fileName);
	
	char name[64];
	printf("Enter Marine Name: ");
	scanf("%64s", name);

	int flag = 0;
	for (int i = 0; i < squads[validSquadID].marineCount; i++) {
		if (strcmp(name, squads[validSquadID].marinesArray[i].name) == 0) {
			flag = 1;
			printf("%s is a marine under the index : %d, from a squad with the index : %d.\n", name, i, validSquadID);
			break;
		}
	}

	if (flag == 0)
		printf("%s is a marine which doesn't exist in the squad with the index : %d.\n", name, validSquadID);
	free(squads);
}

void sortByAge(const char* fileName) {
	SMSquad* squads = readSquadsFromFile(fileName);
	int squadAmount = readSQAmount(fileName);

	for (int i = 0; i < squadAmount; i++) {
		sortAge(&squads[i]);
		print(&squads[i]);
	}

	free(squads);
	system("pause");
}

void sortByRank(const char* fileName) {
	SMSquad* squads = readSquadsFromFile(fileName);
	int squadAmount = readSQAmount(fileName);

	for (int i = 0; i < squadAmount; i++) {
		sortRank(&squads[i]);
		print(&squads[i]);
	}

	free(squads);
	system("pause");
}

void sortByYOS(const char* fileName) {
	SMSquad* squads = readSquadsFromFile(fileName);
	int squadAmount = readSQAmount(fileName);

	for (int i = 0; i < squadAmount; i++) {
		sortYOS(&squads[i]);
		print(&squads[i]);
	}

	free(squads);
	system("pause");
}



void swap(SM* first, SM* second) {
	SM temp = *first;
	*first = *second;
	*second = temp;
}



void sortAge(SMSquad* squad) {
	for (int i = 0; i < squad->marineCount - 1; i++) {
		for (int j = 0; j < squad->marineCount - 1 - i; j++) {
			if (squad->marinesArray[j].age < squad->marinesArray[j + 1].age) {
				swap(&squad->marinesArray[j], &squad->marinesArray[j + 1]);
			}
		}
	}
}

void sortRank(SMSquad* squad) {
	for (int i = 0; i < squad->marineCount - 1; i++) {
		for (int j = 0; j < squad->marineCount - 1 - i; j++) {
			if (squad->marinesArray[j].rank < squad->marinesArray[j + 1].rank) {
				swap(&squad->marinesArray[j], &squad->marinesArray[j + 1]);
			}
		}
	}
}

void sortYOS(SMSquad* squad) {
	for (int i = 0; i < squad->marineCount - 1; i++) {
		for (int j = 0; j < squad->marineCount - 1 - i; j++) {
			if (squad->marinesArray[j].yearsOfService < squad->marinesArray[j + 1].yearsOfService) {
				swap(&squad->marinesArray[j], &squad->marinesArray[j + 1]);
			}
		}
	}
}