#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
	int nData;
	linkedList* next;
} Link;

void init(Link* head, Link* tail)
{
	head->next = nullptr;
	head->nData = 0;

	tail->next = nullptr;
	tail->nData = 0;
}

void menu()
{
	printf("0. end \n");
	printf("1. add \n");
	printf("2. delete \n");
	printf("3. print \n");
}

void addNode(int iData, Link* head, Link* tail)
{
	Link* nNode = (Link*)malloc(sizeof(Link));
	nNode->nData = iData;
	nNode->next = nullptr;
	if (head->next == nullptr)
	{
		head->next = nNode;
	}
	else
	{
		tail->next->next = nNode;
	}

	tail->next = nNode;
}

void deleteNode(int dData, Link* head, Link* tail)
{
	//일단 삭제할려는 노드가 머리부분인가?
	if (head->next->nData == dData)
	{
		Link*pRemove = head->next;

		head->next   = pRemove->next;

		free(pRemove);
		pRemove = NULL;

	}
	else //노드가 일단 2개 이상이란 말.
	{

		Link* pRemoveNode = head->next; //삭제할노드
		Link* pPrevNode   = NULL;       //이전 노드

		//총 삽입된 노드를 돌면서 데이터값이 같은지 비교한다
		while (pRemoveNode)
		{
			//같다면? 삭제할 노드
			if (pRemoveNode->nData == dData)
			{

				//삭제할려면 전노드가 필요하다.
				
				pPrevNode->next = pRemoveNode->next;

				if (pRemoveNode == tail)
				{
					tail->next = pPrevNode->next;
				}


				free(pRemoveNode);
				pRemoveNode = NULL;
				break; //삭제했으니 반복문 탈출.
			}
			else
			{
				pPrevNode   = pRemoveNode;
				pRemoveNode = pRemoveNode->next;
			}
		}
	}

	//while (pLoopLink != nullptr)
	//{
	//	if (pLoopLink->nData == head->nData)
	//	{
	//		dLink = head;
	//		head = head->next;

	//		free(dLink);
	//	}
	//	else if (pLoopLink->nData == tail->nData)
	//	{
	//		dLink = tail;

	//	}
	//}
}
void printNode(Link* head)
{
	Link* pLoopLink = head->next;

	while (pLoopLink/*->next */!= nullptr)
	{
		printf("%d ", pLoopLink->nData);

		pLoopLink = pLoopLink->next;
	}
	printf("\n");
}