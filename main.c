#include "Menus.h"


int main() {

	char fileName[20] = { '\0' };
	
	printf("\nMake sure to add .bin at the end of the name.");
	printf("\nEnter the file name into the program : ");
	scanf("%19[^\n]", fileName);

	if (fileCheck(fileName)) {

		mainMenu(fileName);

	}
	else {
		perror("Something very bad happend with the files");
		exit(EXIT_FAILURE);
	}

	return 0;
}
