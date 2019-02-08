#include "head.h"

void Insert(_node** head, _node** tail, int nData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = nData;

	if (*head == nullptr)
	{
		*head = newNode;
		newNode->prev = newNode;
		newNode->next = newNode;
	}
	else
	{
		(*tail)->next = newNode;
		newNode->prev = *tail;
	}

	*tail = newNode;
}
void Delete(_node** head, _node** tail, _node* cur, int removeData)
{
	Node* delNode;

	if ((*head)->data == removeData)
	{
		delNode = (*head);
		*head = (*head)->next;
		(*head)->prev = nullptr;
		
		printf("Delete [%d] \n", delNode->data);
		free(delNode);
		return;
	}
	else if ((*tail)->data == removeData)
	{
		delNode = (*tail);
		(*tail) = (*tail)->prev;
		(*tail)->next = nullptr;

		printf("Delete [%d] \n", delNode->data);
		free(delNode);
		return;
	}
	else
	{
		cur = *head;
		while (cur != nullptr)
		{
			if (cur->data == removeData)
			{
				delNode = cur;
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;

				printf("Delete [%d] \n", delNode->data);
				free(delNode);
				return;
			}
			cur = cur->next;
		}
	}
}