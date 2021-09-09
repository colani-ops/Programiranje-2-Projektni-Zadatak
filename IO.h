#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <stdlib.h>

#include "Marine.h"

int fileCheck(const char* fileName);
int readSQAmount(const char* fileName);
SMSquad* userInputSquad(int squadNumber);
SMSquad* readSquadsFromFile(char* fileName);
void writeSquadsToFile(const char* fileName, SMSquad* squads, int squadAmount);
void printAvailableSquads(SMSquad* squads, int squadAmount);
int getValidSquadNumber(int maxAmount);
void print(SMSquad* squad);

#endif // !IO_H


