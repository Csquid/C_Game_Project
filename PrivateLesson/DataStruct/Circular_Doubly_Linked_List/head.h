#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* prev;
	struct _node* next;
} Node;

void Insert(Node** tail, int nData);
Node* Search(Node* tail, Node* cur, int nData);
void Delete(Node** tail, Node* removeNode);
void AllPrint(Node* tail, Node* cur);
void Free(Node** tail, Node* cur);