#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;		//pointer right
	struct _node* prev;		//pointer left
} Node;

void Insert(Node** head, Node** tail, int nData);
Node* Search(Node* head, Node* cur, int nData);
void Delete(Node** head, Node** tail, Node* removeNode);
void AllPrint(Node* head, Node* cur);
void Free(Node** head, Node** tail, Node* cur);