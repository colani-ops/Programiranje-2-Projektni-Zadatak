#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {

	char imeDatoteke[20] = { '\0' };
	printf("\nObavezno dodajte .bin na kraju imena datoteke.");
	printf("\nUnesite ime datoteke u program : ");
	scanf("%19[^\n]", imeDatoteke);
	//fgets(imeDatoteke,20,stdin)

	int status = provjeraDatoteke(imeDatoteke);

	if (status == 1) {

		mainMenu(imeDatoteke);

	}

}
