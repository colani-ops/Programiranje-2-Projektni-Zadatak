#include "header.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int searchMenu() {

	int odabir3 = 1;

	while (odabir3 != 5) {

		system("cls");

		printf("\n=====Search Menu=====");
		printf("\n\n1. By Squad Number");
		printf("\n\n2. By Unit Count");
		printf("\n\n3. By Squad Type");
		printf("\n\n4. Individual Space Marines");
		printf("\n\n5. Back");
		printf("\n\nOption : ");

		scanf("%d", &odabir3);

		switch (odabir3) {

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		default:
			break;

		}

	}
	return 0;
}
