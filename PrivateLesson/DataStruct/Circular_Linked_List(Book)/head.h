#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

void Init(Node** tail, Node** cur, Node** Search);
void Menu();
void InsertFront(Node** tail, int nData);
void InsertBack(Node** tail, int nData);
Node* SearchNode(Node* tail, Node* cur, int nData);
void DeleteNode(Node** tail, Node* removeNode);
void PrintAll(Node* tail, Node* cur);
void FreeNode(Node** tail, Node* cur);