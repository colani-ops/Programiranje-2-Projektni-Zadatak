#define _CRT_SECURE_NO_WARNINGS

#ifndef header_h
#define header_h

static int squadAmount;

typedef struct SpaceMarine {

	char name[64];
	int rank;
	int age;
	int yearsOfService;

}SM;

typedef struct SpaceMarineSquad {

	int squadNumber; //radi kao ID, prilikom pretrazivanja i brisanja.
	int marineCount;
	int squadType;

	SM* marinesArray;	//Ovdje dinamicki alocirati broj marinaca u squadu sa marine count prilikom dodavanja.

}SMSquad;


int provjeraDatoteke(char* imeDatoteke);
void provjeraBrojaSquadova(char* imeDatoteke);
SMSquad* pocetnoDodavanjeSquada(char* imeDatoteke);

void dodavanjeSquada(char* imeDatoteke);

SMSquad* sRead(char* imeDatoteke);
void sWrite(char* imeDatoteke, SMSquad* outArray);
void sPrint(char* imeDatoteke);

#endif //header_h
