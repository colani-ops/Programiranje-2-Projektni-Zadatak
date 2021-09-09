#include "Menus.h"
#include "IO.h"

int mainMenu(const char* fileName) {

	int input = 1;

	while (1) {

		system("cls");

		printf("\n==========Main Menu==========");			
		printf("\n\n 1. Add new Space Marine Squad");		
		printf("\n\n 2. Remove a Space Marine Squad");
		printf("\n\n 3. Print the list");
		printf("\n\n 4. Search the list");
		printf("\n\n 5. Exit");
		printf("\n\n Input : ");

		scanf("%d", &input);

		switch (input) {

		case 1:
			addSquad(fileName);
			break;

		case 2:
			removeSquad(fileName);
			break;

		case 3:
			printAvailableSquads(readSquadsFromFile(fileName), readSQAmount(fileName));
			break;

		case 4: {
			searchMenu(fileName);
			break;
		}
		case 5:
			exit(EXIT_SUCCESS);

		default:
			printf("\nPlease choose another option.");
			break;
		}

	}

	exit(EXIT_SUCCESS);

}
