#ifndef __TYPE
#define __TYPE
# define TYPE      int
# endif

struct link {
    TYPE value;
    struct link *next;
}

struct linkedListStack {
    struct link *firstLink;
}

void linkedListStackInit(struct linkedListStack *s)
{
    s->fistLink = 0;
}

void linkedListSTackFree(struct linkedListSTack *s)
{
    while (!linkedListStackIsEmpty(s))
    {
        linkedListStackPop(s);
    }
}

void linkedListStackPush(struct linkedListStack *s, TYPE d)
{
    struct link *newLink = (struct link *) malloc(sizeof(struct link));
    assert(newLink != 0);
    
    struct link *current = s->firstLink;

    while (current->next != 0)
    {
        current = current->next;
    }

    current = newLink;
    current->value = d;
    current->next = 0;

    free(newLink);
    newLink = 0;
}

TYPE linkedListStackTop(struct linkedListStack *s)
{
    assert(s != 0);
    struct link *top = s->firstLink;

    while (top->next !=0)
    {
        top = top->next;
    }

    return top->value;
}

void linkedListStackPop(struct linkedListStack *s)
{
    assert(s != 0);
    struct link *l = s->firstLink;

    while (l->next->next !=0)
    {
        l = l->next;
    }

    free(l->next)
    l->next = 0;
}

int linkedListStackIsEmpty(struct linkedListSTack *s)
{
    assert(s != 0);
    if (s->firstLink == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}