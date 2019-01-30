#include "head.h"

void Insert(Node** tail, int nData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = nData;

	if (*tail == nullptr)
	{
		*tail = newNode;
		newNode->next = newNode;
		newNode->prev = nullptr;
	}
	else
	{
		newNode->next = (*tail)->next;
		(*tail)->next = newNode;
		newNode->prev = *tail;

		*tail = newNode;
	}
}

Node* Search(Node* tail, Node* cur, int nData)
{
	cur = tail->next;

	if (cur->data == nData)
	{
		return cur;
	}

	if (tail->data == nData)
	{
		return tail;
	}

	while (cur != tail)
	{
		if (cur->data == nData)
		{
			return cur;
		}
		cur = cur->next;
	}
	
	return nullptr;
}

void Delete(Node** tail, Node* removeNode)
{
	Node* delNode = (*tail)->next;

	if ((*tail)->next == removeNode)
	{
		(*tail)->next = removeNode->next;
		removeNode->next->prev = nullptr;

		printf("Free [%d] \n", delNode->data);
		free(delNode);
		return;
	}
	
	if ((*tail) == removeNode)
	{
		delNode = (*tail);
		(*tail)->prev->next = (*tail)->next;
		(*tail) = (*tail)->prev;

		printf("Free [%d] \n", delNode->data);
		free(delNode);
		return;
	}

	while (delNode != *tail)
	{
		if (delNode == removeNode)
		{
			removeNode->prev->next = removeNode->next;
			removeNode->next->prev = removeNode->prev;

			printf("Free [%d] \n", delNode->data);
			free(delNode);
			return;
		}
		delNode = delNode->next;
	}
}

void AllPrint(Node* tail, Node* cur)
{
	cur = tail->next;
	
	printf("All Print [");
	while (cur != tail)
	{
		printf("%d, ", cur->data);
		cur = cur->next;
	}
	printf("%d] \n", cur->data);
}
void Free(Node** tail, Node* cur)
{
	Node* delNode = nullptr;

	cur = (*tail)->next;
	while (cur != *tail)
	{
		delNode = cur;
		printf("Free [%d] \n", delNode->data);

		cur = cur->next;

		free(delNode);
	}
	delNode = cur;
	printf("Free [%d] \n", delNode->data);
	free(delNode);
}