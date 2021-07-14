#include "header.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int mainMenu(const char* const imeDatoteke) {

	int odabir1 = 1;

	while (odabir1 != 6) {

		system("cls");

		printf("\n==========Main Menu==========");			//realloc
		printf("\n\n 1. Add new Space Marine Squad");		//dinamicki alocirat temp polje koje ima velicinu kao polje u datoteci ali + 1 kada dodajemo novog
		printf("\n\n 2. Remove a Space Marine Squad");		//overwriteat novim poljem ono staro u datoteci
		printf("\n\n 3. Print the list");
		printf("\n\n 4. Sort the list");;
		printf("\n\n 5. Check number of squads in file and file name");
		printf("\n\n 6. Exit");
		printf("\n\n Odabir : ");


		scanf("%d", &odabir1);

		switch (odabir1) {

		case 1:
			dodavanjeSquada(imeDatoteke);
			break;

		case 2:
			break;

		case 3:
			sPrint(imeDatoteke, sRead(imeDatoteke));
			break;

		case 4:
			sortMenu();
			break;

		case 5:
			provjeraBrojaSquadova(imeDatoteke);
			printf("\nFile name : ");
			printf("%s", imeDatoteke);
			printf("\n\nPress any key to continue.");
			_getch();
			break;

		default:
			break;

		}

	}

	exit(EXIT_SUCCESS);

}
