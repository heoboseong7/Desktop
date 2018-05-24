#include "header.h"

pnode create(int n)
{
	pnode cur;
	cur = (pnode)malloc(sizeof(struct node));

	cur->value = n;
	cur->next = NULL;

	return cur;
}

pnode append(pnode head, pnode cur)
{
	pnode nextnode = head;

	if (head == NULL)
	{
		head = cur;
		return head;
	}

	while (nextnode->next != NULL)
		nextnode = nextnode->next;

	nextnode->next = cur;
	return head;
}