#include "header.h"

void print_fun(pnode head)
{
	pnode nextnode = head;
	while (nextnode != NULL)
	{
		printf("%d ", nextnode->value);
		nextnode = nextnode->next;
	}
}

void reverse(pnode head, int n)
{
	pnode nextnode = head;
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			nextnode = nextnode->next;
		}
		printf("%d ", nextnode->value);
		nextnode = head;
	}
}

void center(pnode head, int n)
{
	pnode nextnode = head;
	if (n % 2)
	{
		for (int i = 0; i < (n - 1) / 2; i++)
			nextnode = nextnode->next;
		printf("%d\n", nextnode->value);
	}
	else
	{
		for (int i = 0; i < (n / 2) - 1; i++)
			nextnode = nextnode->next;
		printf("%d %d\n", nextnode->value, nextnode->next->value);
	}
}

pnode delete_odd(pnode head, int n)
{
	pnode nextnode = head;
	pnode newhead = nextnode->next;
	nextnode = nextnode->next;
	free(head);

	for (int i = 2; i <= n; i++)
	{
		if (i % 2)
		{
			pnode temp = nextnode->next;
			nextnode->next = temp->next;
			nextnode = nextnode->next;
			free(temp);
		}
	}

	return newhead;
}