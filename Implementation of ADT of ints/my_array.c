#include <stdio.h>
#include <stdlib.h>

#include "my_array.h"



my_array* create_my_array(int length) {

//temp head node
node_t* temp = malloc(sizeof(my_array));

if(temp == NULL)
	return NULL;

temp->next = NULL;
node_t* curr = temp; //node that will iterate through array

my_array* new = malloc(sizeof(my_array)); //create a new list

/* Iterate through the length of the array creating new node for the entire length of array.
Each node will have a next and a previous element. */
for(int i = 0; i < length; i++)
{
	curr->next = malloc(sizeof(my_array));

	if(curr->next == NULL)
		return NULL;

	node_t* temp = curr;
	curr= curr->next;
	curr->next = NULL;
	curr->prev = temp;
}

//set head and tail
new->head = temp->next;
new->tail = curr;

return new;
}

int my_ar_get_length(const my_array* ar) {

int counter = 0;

node_t* n = ar->head; //node to iterate through  array

//while n is not null, iterate counter and n
while(n != NULL)
{	
	counter++;
	n = n->next;
}

return counter;
}


int my_ar_set_value(my_array* ar, int index, int item)  {


int i = 0; // counter

node_t* n = ar->head;

//iterate through array until i is equal to index to be set
while(i != index)
{
	i++;
	n = n->next;
}

n->val = item;

return item;
}



int my_ar_get_value(const my_array* ar, int index) {
int i = 0;

node_t* n= ar->head;

while(i != index)
{
	i++;
	n = n->next;
}
return n->val;
}


void my_ar_free(my_array* ar) {

node_t* n = ar->head;

//move through each node and free it
while(n)
{
	node_t *next = n->next;
	free(n);
	n = next;
}

free(ar);
}



/*** Part 2 [20 points] ***/

int my_ar_resize(my_array* ar, int new_size) {


int original_size = my_ar_get_length(ar);

//if the new size and original size are the same, do nothing and return the size
if(original_size == new_size)
	return original_size;


node_t* n; //node to iterate trough array


if(original_size < new_size)
{
	//calculate how many nodes to add
	int additional_nodes = new_size - original_size;

	//iterate starting from tail
	n = ar->tail;

	//add additional nodes
	for(int i = 0; i < additional_nodes; i++)
	{
		n->next = malloc(sizeof(my_array));

		if(n->next == NULL)
			return -1;

		node_t* temp = n;
		n = n->next;
		n->next = NULL;
		n->prev = temp;
	}

	ar->tail = n;
}


if(original_size > new_size)
{
	//if new size is 0, make array empty
	if(new_size == 0)
	{
		ar->head = NULL;
	}
	else
	{
		//iterate through array up until the new size length
		n = ar->head;
		for(int i = 1; i < new_size; i++)
		{
			n = n->next;
		}

		//set tail
		n->next = NULL;
		ar->tail = n;

	}
	
	
}
return new_size;

}

my_array* my_ar_copy(const my_array* src) {

	int n = my_ar_get_length(src);

	//create copy array with uninitialized values
	my_array* copy = create_my_array(n);

	//iterate through array setting copy values to src values
	node_t* original = src->head;
	node_t* copy_ptr = copy->head;

	for(int i = 0; i < n; i++)
	{
		copy_ptr->val = original->val;
		copy_ptr= copy_ptr->next;
		original = original->next;
	}

	return copy;
}

my_array* my_ar_append(my_array* dest, const my_array* src) {


	if(dest == NULL || src == NULL)
		return NULL;

	my_array* copy = my_ar_copy(src);

	//if dest array is empty
	if(dest->head == NULL)
		dest->head = copy->head;

	dest->tail->next = copy->head;

	if(dest->tail->next != copy->head)
	{
		return NULL;
	}

	return dest;
}

/*** Part 3 [30 points] ***/

int my_ar_find(const my_array* ar, int element) {

	int length = my_ar_get_length(ar);

	node_t* n = ar->head;

	for(int i = 0; i < length; i++)
	{
		if(n->val == element)
			return i;

		n = n->next;
	}

	return -1;
}

void my_ar_map(my_array* ar, int (*f)(int)) {

	int length = my_ar_get_length(ar);

	node_t* n = ar->head;

	for(int i = 0; i < length; i++)
	{
		n->val = f(n->val);
		n = n->next;
	}
}

int my_ar_reduce(const my_array* ar, int (*f)(int,int)) {

	my_array* copy = my_ar_copy(ar);

	int length = my_ar_get_length(copy);

	node_t* n = ar->head;

	int accumulator = n->val;

	//iterate through the length of the array accumulating each node value
	for(int i = 1; i < length; i++)
	{
		accumulator = f(accumulator, n->next->val);

		n = n->next;
	}

	my_ar_free(copy);

	return accumulator;
}

my_array* my_ar_filter(my_array* src, bool (*f)(int)) {



	my_array* copy = my_ar_copy(src);
	node_t * n = copy->head;


	//find the first value that is true
	//set that node equal to head
	while(f(n->val) == false)
	{
		node_t* temp = n;
		n = n->next;
		free(temp);//free false values

		if(n == NULL)
		{
			break;
		}
	}

	copy->head = n;



	//iterate through length of array, if the node is false, link the previuos node to the next node
	//and then free the false node.
	while(n != NULL)
	{
		//printf("hi\n");

		if(f(n->val) == false)
		{
			node_t* temp2 = n;
			n->prev->next = n->next;

			if(n->next){
				n->next->prev = n->prev;
			}

			n = n->next;
			free(temp2);
		}
		else
		{
			n = n->next;

		}
	}
	return copy;
}
