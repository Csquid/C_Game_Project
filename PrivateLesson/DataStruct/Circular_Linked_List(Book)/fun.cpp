#include "head.h"

void Init(Node** tail, Node** cur, Node** Search)
{
	*tail = nullptr;
	*cur = nullptr;
	*Search = nullptr;
}

void Menu()
{
	printf("0. end \n");
	printf("1. insert \n");
	printf("2. search \n");
	printf("3. delete \n");
	printf("4. Print All \n");
}

void InsertFront(Node** tail, int nData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = nData;

	if (*tail == nullptr)
	{
		*tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = (*tail)->next;
		(*tail)->next = newNode;
		*tail = newNode;
	}
}

void InsertBack(Node** tail, int nData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = nData;
	if (*tail == nullptr)
	{
		*tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = (*tail)->next;
		(*tail)->next = newNode;
	}

}

Node* SearchNode(Node* tail, Node* cur, int nData)
{
	if (tail == nullptr)
	{
		return nullptr;
	}
	if (tail->data == nData)
	{
		return tail;
	}

	cur = tail->next;

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

void DeleteNode(Node** tail, Node* removeNode)
{
	if ((*tail)->next == removeNode)
	{
		printf("Free [%d] \n", removeNode->data);
		(*tail)->next = removeNode->next;
		free(removeNode);

		return;
	}

	Node* before = (*tail)->next;
	Node* delNode = before->next;
	
	while (delNode != (*tail))
	{
		if (delNode == removeNode)
		{
			printf("Free [%d] \n", delNode->data);
			before->next = delNode->next;
			free(delNode);
			return;
		}

		before = delNode;
		delNode = delNode->next;
	}

	if (delNode == (*tail))
	{
		(*tail) = before;
		(*tail)->next = delNode->next;

		printf("Free [%d] \n", delNode->data);
		free(delNode);
	}
}

void PrintAll(Node* tail, Node* cur)
{
	if (tail == nullptr)
	{
		printf("Tail is Empty \n");
		return;
	}
	cur = tail->next;

	printf("All Data [");
	while (cur != tail)
	{
		printf("%d, ", cur->data);
		cur = cur->next;
	}
	printf("%d] \n", cur->data);
}

void FreeNode(Node** tail, Node* cur)
{
	Node* delNode;

	printf("Free [");
	
	cur = (*tail)->next;
	while (cur != *tail)
	{
		delNode = cur;
		printf("%d, ", delNode->data);

		cur = cur->next;
		free(delNode);
	}
	
	delNode = cur;
	if (delNode == *tail)
	{
		printf("%d]", delNode->data);
		free(delNode);
		*tail = nullptr;
	}
}