typedef struct przychodnia {
	char imie[50];
	char nazwisko[50];
	int idPacjenta;
}Entry;


typedef struct node
{
	Entry entry; //- typ danych do listy
	node* next;
}Node;  

typedef struct queue {
	Node* first;
	Node* last;
	int counter;
}Queue;


bool initialization(Queue* pqueue);
bool isEmpty(const Queue* pqueue);
bool isFull(const Queue* pqueue);
bool addNode(Entry entry, Queue* pqueue);
bool removeNode(Queue* pqueue);
int numberOfElements(const Queue* pqueue);
void displayData(const Queue* pqueue);
bool deleteQueue(Queue* pqueue);

