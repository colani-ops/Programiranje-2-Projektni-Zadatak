#define _CRT_SECURE_NO_WARNINGS

#ifndef header_h
#define header_h

typedef struct SpaceMarine {

	char name[64];
	char rank[32];
	int age;
	int yearsOfService;

}SpaceMarine;

typedef struct SpaceMarineSquad {

	int squadNumber; //radi kao ID, prilikom pretrazivanja i brisanja.
	int marineCount;
	char squadType[16];

	struct SpaceMarine* marinesArray;	//Ovdje dinamicki alocirati broj marinaca u squadu sa marine count prilikom dodavanja.

}SMSquad;


int provjeraDatoteke(char* imeDatoteke);
void dodavanjeSquada(char* imeDatoteke);
SMSquad* sRead(char* imeDatoteke);
void sWrite(char* imeDatoteke, SMSquad* outArray, int sizeOfOutArray);

#endif //header_h
