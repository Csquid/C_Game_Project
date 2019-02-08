#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
	struct _node* prev;

} Node;

void Insert(_node** head, _node** tail, int nData);
void Delete(_node** head, _node** tail, _node* cur, int removeData);