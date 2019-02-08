#include "head.h"

int main()
{
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* cur = nullptr;
	for (int i = 0; i < 5; i++)
	{
		Insert(&head, &tail, i + 1);
	}
	Delete(&head, &tail, cur, 1);
	Delete(&head, &tail, cur, 3);
	Delete(&head, &tail, cur, 5);

	return 0;
}