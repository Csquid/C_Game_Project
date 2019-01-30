#include "head.h"

void Insert(Node** head, Node** tail, int nData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = nData;
	newNode->next = nullptr;

	if (*head == nullptr)
	{
		*head = newNode;
		newNode->prev = nullptr;
	}
	else
	{
		(*tail)->next = newNode;
		newNode->prev = *tail;
	}

	*tail = newNode;
}

Node* Search(Node* head, Node* cur, int nData)
{
	if (head == nullptr)
	{
		printf("Empty Linked List \n");
	}
	if (head->data == nData)
	{
		return head;
	}

	cur = head;
	while (cur != nullptr)
	{
		if (cur->data == nData)
		{
			return cur;
		}
		cur = cur->next;
	}

	return nullptr;
}

void Delete(Node** head, Node** tail, Node* removeNode)
{
	Node* delNode = *head;

	if (*head == removeNode)
	{
		*head = (*head)->next;
		(*head)->prev = nullptr;
		free(delNode);
		return;
	}
	else if (*tail == removeNode)
	{
		delNode = *tail;
		*tail = (*tail)->prev;
		(*tail)->next = nullptr;
		free(delNode);
		return;
	}

	while (delNode != nullptr)
	{
		if (delNode == removeNode)
		{
			delNode->prev->next = delNode->next;
			delNode->next->prev = delNode->prev;
			free(delNode);
			return;
		}
		delNode = delNode->next;
	}
}

void AllPrint(Node* head, Node* cur)
{
	cur = head;

	printf("All Print [");
	while (cur != nullptr)
	{ 
		if (cur->next == nullptr)
			printf("%d]\n", cur->data);
		else
			printf("%d, ", cur->data);

		cur = cur->next;
	}

}

void Free(Node** head, Node** tail,  Node* cur)
{
	Node* delNode;

	cur = *head;

	while (cur != nullptr)
	{
		delNode = cur;
		cur = cur->next;

		printf("Free [%d] \n", delNode->data);
		free(delNode);
	}
	*head = nullptr;
	*tail = nullptr;
}