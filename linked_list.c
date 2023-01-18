#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node;

typedef struct linked_list
{
	int size;
	node * head;
	node * end;
	int (*get_size) (struct linked_list *);
	void (*traverse) (struct linked_list *);
	void (*initialize) (struct linked_list *);
	void (*push_back) (struct linked_list *, int);
	void (*insert_at_head) (struct linked_list *,int);
	void (*destroy) (struct linked_list *);
	void (*print_reverse) (node *);
}linked_list;

void _print_reverse (struct node * ptr)
{
	if (!ptr)
		return;
	_print_reverse(ptr->next);
	printf ("%d ", ptr->data);
}
void _destroy (linked_list * ptr)
{
	node * temp = ptr->head;
	node * p = (node *)temp->next;
	while (temp != NULL )
	{
		p =  (node *)temp->next;
		free (temp);
		temp = p;
	}
	ptr->head = NULL;
	ptr->end = NULL;
	ptr->size = 0;
	free (ptr);
}
void _traverse (linked_list *ptr)
{
	node * temp = ptr->head;
	while (temp != NULL)
	{
		printf ("%d ", temp->data);
		temp = (node *)temp->next;
	}
	printf("\n");
}
void _push_back(linked_list * ptr, int value)
{
	node * tmp = (node *) malloc (sizeof *tmp);
	if (!tmp)
		return;
	tmp->data = value;
	tmp->next = NULL;
	if (!ptr->head)
	{
		ptr->head = tmp;
	}
	else
		ptr->end->next = (struct node *)tmp;
	ptr->end = tmp;
	ptr->size++;
}
int _get_size (linked_list * ptr)
{
	return ptr->size;
}
void _insert_at_head (linked_list * ptr, int value)
{
	node * tmp = (node *) malloc (sizeof (*tmp));
	if (tmp == NULL)
		return;
	tmp->data = value;
	tmp->next = (struct node *)ptr->head;
	ptr->head = tmp;
	ptr->size++;
	if (ptr->end == NULL)
		ptr->end = tmp;
}

void __initialize (linked_list * ptr)
{
	ptr->size = 0;
	ptr->head = NULL;
	ptr->end = NULL;
	ptr->get_size = _get_size;
	ptr->push_back = _push_back;
	ptr->insert_at_head = _insert_at_head;
	ptr->traverse = _traverse;
	ptr->destroy = _destroy;
	ptr->print_reverse = _print_reverse;
}
void _initialize (struct linked_list * ptr)
{
	linked_list *temp = (linked_list *) ptr;
	__initialize (temp);
}
linked_list * create_list ()
{
	linked_list * new_list =  malloc (sizeof *new_list);
	if (!new_list)
	{
		perror ("Memory allocation failed...\n");
		exit(EXIT_FAILURE);
	}
	new_list->initialize = _initialize;
	new_list->initialize(new_list);
	return new_list;
}

