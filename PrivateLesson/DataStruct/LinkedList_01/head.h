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
	//�ϴ� �����ҷ��� ��尡 �Ӹ��κ��ΰ�?
	if (head->next->nData == dData)
	{
		Link*pRemove = head->next;

		head->next   = pRemove->next;

		free(pRemove);
		pRemove = NULL;

	}
	else //��尡 �ϴ� 2�� �̻��̶� ��.
	{

		Link* pRemoveNode = head->next; //�����ҳ��
		Link* pPrevNode   = NULL;       //���� ���

		//�� ���Ե� ��带 ���鼭 �����Ͱ��� ������ ���Ѵ�
		while (pRemoveNode)
		{
			//���ٸ�? ������ ���
			if (pRemoveNode->nData == dData)
			{

				//�����ҷ��� ����尡 �ʿ��ϴ�.
				
				pPrevNode->next = pRemoveNode->next;

				if (pRemoveNode == tail)
				{
					tail->next = pPrevNode->next;
				}


				free(pRemoveNode);
				pRemoveNode = NULL;
				break; //���������� �ݺ��� Ż��.
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