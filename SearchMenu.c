#include "Search.h"

int searchMenu(const char* fileName) {

	int input = 1;

	while (1) {

		system("cls");

		printf("\n=====Search Menu=====");
		printf("\n\n 1. Find Marine by NAME.");
		printf("\n\n 2. Sort All Marines by RANK.");
		printf("\n\n 3. Sort All Marines by AGE.");
		printf("\n\n 4. Sort All Marines by YEARS OF SERVICE.");
		printf("\n\n 5. Back");
		printf("\n\n Input : ");

		scanf("%d", &input);

		switch (input) {

		case 1:
			findByName(fileName, getValidSquadNumber(readSQAmount(fileName)));
			break;

		case 2:
			sortByRank(fileName);
			break;

		case 3:
			sortByAge(fileName);
			break;

		case 4:
			sortByYOS(fileName);
			break;

		case 5:
			return 0;

		default:
			printf("\nPlease choose another option.");
			break;
		}

	}
	return 0;
}
