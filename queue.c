#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX_SIZE 3

bool initialization(Queue* pqueue)
{
	//pqueue = (struct queue*)malloc(sizeof(queue));
	pqueue->first = NULL;
	pqueue->last = NULL;
	pqueue->counter = 0;
	return 1;
}

bool isEmpty(const Queue* pqueue)
{
	/*if (pqueue->counter == 0) {
		return 1;
	}*/
	if (pqueue->first == NULL) {
		return 1;
	}
	return 0;
}

bool isFull(const Queue* pqueue)
{
	if (pqueue->counter >= QUEUE_MAX_SIZE) {
		return 1;
	} 
	return 0;
}

bool addNode(Entry entry, Queue* pqueue)
{
	
	if (isFull(pqueue)) {
		printf("\nKolejka jest przepelniona!\n");
		return 0;
	}
	Node* temp;
	temp = (node*)malloc(sizeof(node));
	if (temp == NULL) {
		return 0;
	}
	temp->entry = entry;
	temp->next = NULL;
	if (isEmpty(pqueue)) {
		pqueue->first = temp;
		pqueue->last = temp;
	}
	else if (numberOfElements(pqueue) == 1) {
		pqueue->first->next = temp;
		pqueue->last = temp;
	}
	else {
		pqueue->last->next = temp;
		pqueue->last = temp;
	}
	pqueue->counter++;
	return 1;
}

bool removeNode(Queue* pqueue)
{
	if (pqueue->first == NULL) {
		return 0;
	}
	Node* temp;
	temp = pqueue->first->next;
	free(pqueue->first);
	pqueue->first = temp;
	pqueue->counter--;

	if (temp == NULL) {
		pqueue->first = NULL;
		pqueue->last = NULL;
	}
	return 1;
}

int numberOfElements(const Queue* pqueue)
{
	return pqueue->counter;
}

void displayData(const Queue* pqueue)
{
	if (!isEmpty(pqueue)) {
		printf("\nKolejka o aktualnym rozmiarze (%d):", numberOfElements(pqueue));
		Node* temp = pqueue->first;
		printf("\nImie | Nazwisko | ID");
		int i = 0;
		while (temp != NULL) {
			printf("\n%s | %s | %dzl", temp->entry.imie, temp->entry.nazwisko, temp->entry.idPacjenta);
			temp = temp->next;
			i++;
		}
		printf("\n\n");
	}
	else
	{
		printf("\nKolejka jest pusta\n");
	}
}

bool deleteQueue(Queue* pqueue)
{
	while (removeNode(pqueue));
	if (pqueue->first == NULL && pqueue->last == NULL) {
		printf("\nKolejka usunieta i pamiec zwolniona\n");
	}
	else {
		printf("Cos poszlo nie tak!!!");
		exit(1);
	}
	return 1;
}



