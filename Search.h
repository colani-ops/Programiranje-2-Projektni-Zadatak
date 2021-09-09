#ifndef SEARCH_H
#define SEARCH_H

#include "Marine.h"

void findByName(const char* fileName, int validSquadID);

void sortByAge(const char* fileName);
void sortByRank(const char* fileName);
void sortByYOS(const char* fileName);

void sortAge(SMSquad* squad);
void sortRank(SMSquad* squad);
void sortYOS(SMSquad* squad);

#endif // !SEARCH_H
