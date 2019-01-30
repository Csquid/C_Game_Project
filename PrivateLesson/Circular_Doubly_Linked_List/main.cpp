#include "head.h"

int main()
{
	Node* scNode = nullptr;
	Node* tail = nullptr;
	Node* cur = nullptr;


	Insert(&tail, 1);
	Insert(&tail, 2);
	Insert(&tail, 3);

	scNode = Search(tail, cur, 3);

	if (scNode == NULL)
	{
		printf("Can't Found Node \n");
	}
	else
	{
		printf("Find! [ %d ] \n", scNode->data);
	}
	AllPrint(tail, cur);

	return 0;
}