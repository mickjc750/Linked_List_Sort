#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


static void sort(void);
static void push(int x);
static int pop(void);

struct node_struct 
{
	int value;
	struct node_struct* next_node;
};

struct node_struct* board_list = NULL;

int main(int argc, char *argv[])
{
	struct node_struct* ptr;

	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());
	push(rand());

	ptr = board_list;
	while(ptr)
	{
		printf("%i\n", ptr->value);
		ptr = ptr->next_node;
	};

	printf("-----\n");
	sort();

	ptr = board_list;
	while(ptr)
	{
		printf("%i\n", ptr->value);
		ptr = ptr->next_node;
	};

	while(board_list)
		pop();

	return 0;
}

static void push(int x)
{
	struct node_struct* new;
	new = malloc(sizeof(*new));
	new->value = x;
	new->next_node = board_list;
	board_list = new;
}

static int pop(void)
{
	int result = 0;
	struct node_struct* old;

	if(board_list)
	{
		result = board_list->value;
		old = board_list;
		board_list = board_list->next_node;
		free(old);
	};

	return result;
}

static void sort(void)
{
	bool done = false;
	struct node_struct** ptr = &board_list;
	struct node_struct* tmp;

	while(!done)
	{
		done = true;
		ptr = &board_list;
		while(*ptr && (*ptr)->next_node)
		{
			if((*ptr)->value > (*ptr)->next_node->value)
			{
				tmp = (*ptr)->next_node->next_node;
				(*ptr)->next_node->next_node = (*ptr);
				(*ptr) = (*ptr)->next_node;
				(*ptr)->next_node->next_node = tmp;
				done = false;
			};
			ptr = &((*ptr)->next_node);
		};
	};
}
