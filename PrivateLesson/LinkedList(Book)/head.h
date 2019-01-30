#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

void Menu();
void Init(Node** head, Node** tail, Node** cur, Node** searchNode);
void InsertNode(Node** head, Node** tail, int nData);
Node* Search(Node* head, Node* cur, int nData);
void PrintNode(Node* head, Node* cur);
void DeleteNode(Node** head, Node** tail, Node** RemoveNode, Node* cur);
void FreeNode(Node** head, Node** tail);
#endif