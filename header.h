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
        int unitCount;
        char* squadType;

        struct SpaceMarine;

}SMSquad;

int provjeraDatoteke(char imeDatoteke);

#endif //header_h
