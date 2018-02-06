#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);

	list->sentinel = (struct Link *) malloc(sizeof(struct Link));
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
	list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link * lnk = (struct Link *) malloc(sizeof(struct Link));
	lnk->next = 0;
	lnk->prev = 0;
	lnk->value = value;

	return lnk;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(link != 0);

	struct Link *newLink = createLink(value);
	link->next->prev = newLink;
	newLink->next = link->next;
	newLink->prev = link;
	link->next = newLink;

	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(link != 0);

	link->next->prev = link->prev;
	link->prev->next = link->next;

	free(link);
	link = 0;

	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	for (int i = 0; i < list->size; i++)
	{
		removeLink(list, list->sentinel->next);
	}
	free(list->sentinel);
	free(list);
	list = 0;
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);

	addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);

	addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);

	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);

	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	if (list->sentinel->next == list->sentinel)
	{
		return 1;
	}
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	printf("\n");
	struct Link * print = list->sentinel;
	for (int i = 0; i < list->size; i++)
	{
		print = print->next;
		printf(" %g \n", print->value);
	}
	printf("\n");
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	struct Link * currentLink = list->sentinel;
	for (int i = 0; i <= list->size; i++)
	{
		struct Link * tempLink = currentLink->next;
		currentLink->next = currentLink->prev;
		currentLink->prev = tempLink;

		currentLink = tempLink;
	}
}
