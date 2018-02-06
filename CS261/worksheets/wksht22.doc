struct dLink {
    TYPE value;
    struct dLink * next;
    struct dLink * prev;
};

struct linkedList {
    struct dLink * frontSentinel;
    struct dLink * backSentinel;
    int size;
};

/* the following functions were written in earlier lessons */
void linkedlistInit (struct linkedList *lst);
void linkedListFree (struct linkedList *lst);
void _addLink (struct linkedList * lst, struct dLink * lnk, TYPE e);
void _removeLink (struct linkedList * lst, struct dLink * lnk);

void linkedListAdd (struct linkedList * lst, TYPE e)
{ 
    _addLink(lst, lst->frontSentinel->next, e); 
}

/* you must write the following */
int linkedListContains (struct linkedList *lst, TYPE e)
{
    assert(*lst != 0);
    assert(e != 0);
    struct dLink *link = lst->frontSentinel->next;

    for (int i = 0; i < lst->size; i++)
    {
        if (link->value == e)
        {
            return 1;
        }
        link = link->next;
    }

    return 0;
}

void linkedListRemove (struct linkedList *lst, TYPE e) 
{
    assert(*lst != 0);
    assert(e != 0);
    struct dLink *link = lst->frontSentinel->next;

    for (int i = 0; i < lst->size; i++)
    {
        if (link->value == e)
        {
            _removeLink(lst, link);
        }
    }
}

/* 
1. what were the algorithmic complexities of the
methods addLink and removeLink that you wrote back in link

addLink O(1)
removeLink O(n);

2. given your answer to the previous question, 
what are the algorithmic complexities of the three
principle Bag operations?

add O(1)
contains O(n)
remove() O(n-squared)

*/