#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {

        char imeDatoteke[20] = { '\0' };
        printf("\nUnesite ime datoteke u program : ");
        scanf("%s", imeDatoteke);

        int status = provjeraDatoteke(imeDatoteke);

        if (status == 1) {

                int odabir1;
                int odabir2;
                int odabir3;
                int back = 1;

                while (back == 1) {

                        system("cls");

                        printf("\n\n==========Main Menu==========");
                        printf("\n\n 1. Add new Space Marine");
                        printf("\n\n 2. Remove a Space Marine");
                        printf("\n\n 3. Print the list");
                        printf("\n\n 4. Sort the list");
                        printf("\n\n 5. Search the list");
                        printf("\n\n 6. Thought of the day");
                        printf("\n\n 7. Exit");
                        printf("\n\n 8.");
                        printf("\n\n 9.");

                        printf("\n\n Odabir : ");
                        scanf("%d", &odabir1);

                        while (odabir1 != 0) {

                                switch (odabir1) {

                                case 1:
                                        break;

                                case 2:
                                        break;

                                case 3:
                                        break;

                                case 4:

                                        system("cls");

                                        printf("=====Sort Menu=====");

                                        printf("\n\n\t1. By Squad Number");
                                        printf("\n\n\t2. By Unit Count");
                                        printf("\n\n\t3. By Squad Type");
                                        printf("\n\n\t4. Individual Space Marines");
                                        printf("\n\n\t5. Back");
                                        printf("\n\nOption : ");
                                        scanf("%d", &odabir2);

                                        while (odabir2 != 0) {

                                                switch (odabir2) {

                                                case 1:
                                                        break;

                                                case 2:
                                                        break;

                                                case 3:
                                                        break;

                                                case 4:
                                                        break;

                                                default:
                                                        back = 1;
                                                        break;
                                                }

                                                break;
                                        }

                                case 5:
                                        printf("=====Search Menu=====");

                                        printf("\n\n\t1. By Squad Number");
                                        printf("\n\n\t2. By Unit Count");
                                        printf("\n\n\t3. By Squad Type");
                                        printf("\n\n\t4. Individual Space Marines");
                                        printf("\n\n\t5. Back");
                                        printf("\n\nOption : ");
                                        scanf("%d", &odabir3);

                                        while (odabir3 != 0) {

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
                                                        back = 1;
                                                        break;
                                                }

                                        }

                                        break;

                                case 6:
                                        break;

                                case 7:
                                        exit(EXIT_SUCCESS);
                                        break;

                                default:
                                        printf("\nKrivo unesena vrijednost.");

                                }

                        }

                }

        }
}
