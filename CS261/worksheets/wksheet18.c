

struct link {
    TYPE value;
    struct link *next;
};

struct listQueue {
    struct link *fistLink;
    struct link *lastLink;
};

void listQueueInit(struct listQueue *q)
{
    struct link *lnk = (struct link *) malloc(sizeof(struct link));
    assert(lnk != 0);
    lnk->next = 0;
    q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack (struct listQueue *q, TYPE e)
{
    struct link *newLink = (struct link *) malloc(sizeof(struct link));
    assert(newLink != 0);

    newlink->value = e;
    newLink->next = 0;
    q->lasstlink->next = newLink;
    q->lastlink = newLink;
}

TYPE listQueueFront(struct listQueue *q)
{
    return q->firstLink->->value;
}

void listQueueRemoveFront(struct listQueue *q)
{
    assert(q != 0);
    if (q->firstLink != q->lastLink)
    {
        if (q->firstLink->next == q->lastLink)
        {
            free(q->firstLink->next);
            q->firstLink->next = 0;
            q->lastLink = q->fistLink;
        }
        else
        {
            struct link *temp = q->firstLink->next->next;
            free(q->firstLink->next);
            q->firstLink->next = temp;
        }
    }
}

int listQueueIsEmpty(struct listQueue *q)
{
    if (q->lastLink->value == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}