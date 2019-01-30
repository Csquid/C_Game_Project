#include "head.h"

void Init(Node** head, Node** tail, Node** cur, Node** searchNode)
{
	*searchNode = nullptr;
	*head = nullptr;
	*tail = nullptr;
	*cur = nullptr;
}

void Menu()
{
	printf("0. end \n");
	printf("1. insert \n");
	printf("2. search \n");
	printf("3. delete \n");
	printf("4. Print All \n");
}

void InsertNode(Node** head, Node** tail, int nData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = nData;
	newNode->next = nullptr;

	if (*head == nullptr)
		*head = newNode;
	else
		(*tail)->next = newNode;

	*tail = newNode;
}

Node* Search(Node* head, Node* cur, int nData)
{
	if (head == nullptr)
	{
		printf("EMPTY LinkList \n");
		exit(1);
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
	return NULL;
}

void PrintNode(Node* head, Node* cur)
{
	if (head == nullptr)
	{
		printf("EMPTY LinkedList \n");
		exit(1);
	}

	cur = head;

	printf("All Print Linked List Data's [");

	while (cur != nullptr)
	{
		if (cur->next == nullptr)
			printf("%d", cur->data);
		else
			printf("%d, ", cur->data);

		cur = cur->next;
	}
	printf("] \n");
}

void DeleteNode(Node** head, Node** tail, Node** RemoveNode, Node* cur)
{
	if (*head == *RemoveNode)
	{
		*head = (*RemoveNode)->next;
		free(*RemoveNode);

		*RemoveNode = nullptr;
		return;
	}

	Node* Before = *head;
	Node* DelNode = (*head)->next;

	while (DelNode != nullptr)
	{
		if (*RemoveNode == DelNode)
		{
			if (*tail == *RemoveNode)
			{
				*tail = Before;
				Before->next = nullptr;
				free(DelNode);
				return;
			}

			Before->next = DelNode->next;
			free(DelNode);
			return;
		}
		Before = DelNode;
		DelNode = DelNode->next;
	}
}

void FreeNode(Node** head, Node** tail)
{
	Node* DelNode;

	printf("Free [");
	while (*head != nullptr)
	{
		DelNode = *head;
		
		if (*head == *tail)
		{
			printf("%d]", DelNode->data);
			*head = nullptr;
			*tail = nullptr;
		}
		else
		{
			*head = (*head)->next;

			printf("%d, ", DelNode->data);
		}
		free(DelNode);
	}
}