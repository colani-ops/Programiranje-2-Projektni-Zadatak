#ifndef MARINE_H
#define MARINE_H
#include <stdlib.h>

typedef struct SpaceMarine {
	char name[64];
	int rank;
	int age;
	int yearsOfService;
}SM;

typedef struct SpaceMarineSquad {

	int squadNumber; //radi kao ID, prilikom pretrazivanja i brisanja.
	char squadName[128];
	int squadType;

	int marineCount;
	SM* marinesArray;

}SMSquad;

void addSquad(char* fileName);
SMSquad* appendToEnd(SMSquad* squads, SMSquad* newSquad, int squadAmount);
void removeSquad(const char* fileName);
void copySquad(SMSquad* destination, SMSquad* source);
void copyMarines(SM* destination, SM* source, int count);
int deleteSquad(SMSquad* squads, int squadAmount, int deleteID);

#endif //MARINE_H
