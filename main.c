#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "queue.h"

void clearInput() {
	while (getchar() != '\n');
}

int main()
{
	Queue* patients;
	patients = (struct queue*)malloc(sizeof(queue));
	bool init = initialization(patients);

	Entry inputData;

	if (isFull(patients)) {
		printf("Cos poszlo nie tak, kolejka jest pelna");
		exit(1);
	}

	int choice = 0;
	while (choice != 6) {
		printf("\nMenu\n");
		printf("1. Dodaj pacjentow do kolejki\n");
		printf("2. Pierwszy pacjent odbyl wizyte\n");
		printf("3. Wyswietl kolejke pacjentow\n");
		printf("4. Liczba pacjentow w kolejce\n");
		printf("5. Wyczysc calkowicie kolejke pacjentow\n");
		printf("6. Koniec programu\n");
		printf("Wybor: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
			case 1:
			{
				if (!isFull(patients)) {
					clearInput();
					printf("\nPodaj imie dla %d pacjenta w kolejce: ", patients->counter+1);
					while (gets_s(inputData.imie) != NULL && inputData.imie[0] != '\0') {
						printf("\nNazwisko pacjenta %s: ", inputData.imie);
						gets_s(inputData.nazwisko);
						printf("\nID pacjenta: ");
						scanf_s("%d", &inputData.idPacjenta);
						while (getchar() != '\n')
						{
							continue;
						}
						if (!addNode(inputData, patients))
						{
							printf("\nNie mozna dodac pacjenta\n");
							break;
						}
						printf("\nPodaj imie dla %d pacjenta w kolejce: ", patients->counter+1);
					}
				}
			}
			//displayData(patients);
			break;
			case 2:
			{
				removeNode(patients);
				displayData(patients);
			}
			break;
			case 3:
			{
				displayData(patients);
			}
			break;
			case 4:
			{
				printf("\nLiczba pacjentow w kolejce: %d\n",numberOfElements(patients));
			}
			break;
			case 5:
			{
				deleteQueue(patients);
			}
			break;
			default:
				break;
		}
	}

}



