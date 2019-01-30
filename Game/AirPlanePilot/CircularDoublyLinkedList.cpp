#include "head.h"

void Linked_Insert(Node** tail, Pos planePos)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->bull.curPos.setPos(planePos.x, planePos.y - 1);

	if ((*tail) == nullptr)
	{
		(*tail) = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}

	//head
	newNode->next = (*tail)->next;
	(*tail)->next->prev = newNode;
	(*tail)->prev->next = newNode;
	(*tail)->next = newNode;
	//tail
	(*tail) = newNode;
}

void Linked_Search(Node* tail, Node* cur)
{

}

void Linked_Delete(Node** tail, Node* cur)
{

}

void Linked_PrintNode(Node* tail, Node* cur)
{

}

void Linked_Free(Node** tail, Node* cur)
{

}