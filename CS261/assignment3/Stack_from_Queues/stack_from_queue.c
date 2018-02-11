

/*
 * This is the file in which you'll write the functions required to implement
 * a stack using two queues.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name: Patrick Moore
 * Email: moorepat@oregonstate.edu
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* All by yourself */ 

#ifndef TYPE
#define TYPE int
#endif

struct link {
   TYPE value;
   struct link * next;
};
 
struct listQueue {
   struct link *firstLink;
   struct link *lastLink;
};
 
void listQueueInit (struct listQueue *q) {
   struct link *lnk = (struct link *) malloc(sizeof(struct link));
   assert(lnk != 0);
   
   lnk->next = 0;
   q->firstLink = q->lastLink = lnk;
}
 
void listQueueAddBack (struct listQueue *q, TYPE e) {
    assert(q != 0);
	struct link *lnk = (struct link*) malloc(sizeof(struct link));
	assert(lnk !=0); 
	lnk->next = 0;
	lnk->value = e;
	q->firstLink->next = lnk;
	q->lastLink = lnk;
}
 
TYPE listQueueFront (struct listQueue *q) {
    assert(q != 0);
 	return q->firstLink->next->value;
}
 
void listQueueRemoveFront (struct listQueue *q) {

	assert(q != 0);
	if (q->firstLink != q->lastLink)
	{
    	if (q->firstLink->next == q->lastLink)
    	{
            free(q->firstLink->next);
        	q->firstLink->next = 0;
        	q->lastLink = q->firstLink;
    	}
    	else
    	{
        	struct link *temp = q->firstLink->next->next;
            free(q->firstLink->next);
        	q->firstLink->next = temp;
    	}
	}
}
 
int listQueueIsEmpty (struct listQueue *q) {

    assert(q != 0);
 	if(q->firstLink == q->lastLink) {
 		return 1;
	}
	return 0;
}


// listQueueInit
// listQueueAddBack
// listQueueFront
// listQueueRemoveFront
// listQueueIsEmpty



struct twoQueueStack {
   struct listQueue *one;
   struct listQueue *two;
}



void twoQueueStackInit (struct twoQueueStack * s) 
{ 
    struct listQueue * queueOne;
    listQueueInit(queueOne);
    struct listQueue * queueTwo;
    listQueueInit(queueTwo);

    s->one = queueOne;
    s->two = queueTwo;
}


void twoQueueStackFree (struct twoQueueStack *s)
	{ while (! twoQueueStackIsEmpty(s)) twoQueueStackPop(s); }


void twoQueueStackPush (struct twoQueueStack *s, TYPE d) {
   
   listQueueAddBack(s->one, d);
   if (listQueueIsEmpty(s->two))
   {
       listQueueAddBack(s->two, d);
   }
   else{
       listQueueRemoveFront(s->two);
       listQueueAddBack(s->two, d);
   }
}

TYPE twoQueueStackTop (struct twoQueueStack *s) 
{
	return s->two->firstLink->value;
}


void twoQueueStackPop (struct twoQueueStack *s) {

   	
}

int twoQueueStackIsEmpty (struct twoQueueStack *s) {

	listQueueIsEmpty(s->one);
}



int main()
{
    
    return 0;
}