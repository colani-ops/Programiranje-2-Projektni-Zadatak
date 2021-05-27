#define _CRT_SECURE_NO_WARNINGS

#ifndef header_h
#define header_h

typedef struct SpaceMarine {

	char name[64];
	char rank[32];
	char company[32];
	int age;
	int yearsOfService;
	char speciality[16];

}SpaceMarine;

typedef struct SpaceMarineSquad {

	int squadNumber;
	int marineCount;
	char squadType[16];

	struct SpaceMarine* marineArray;//ovdje dinamicki alocirati broj marinaca u squadu sa marine count prilikom dodavanja.
									//Mozda napraviti da se dodaje squad po squad a ne marine po marine.


}SMSquad;

typedef struct SpaceMarineUnit {

	int sAmount;

	struct SpaceMarineSquad* squads;

}SMunit;

int provjeraDatoteke(char* imeDatoteke);
SMSquad* dodavanjeSquada(SMunit* unit);
SMSquad* sRead(char* imeDatoteke);
void sWrite(char* imeDatoteke, SMSquad* outArray, int sizeOfOutArray);

#endif //header_h
