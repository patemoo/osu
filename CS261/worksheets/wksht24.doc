struct linkedListIterator {
    struct linkedList * lst;
    struct dLink * currentLink;
}

void linkedListIteratorInit (struct linkedList *lst, struct linkedListIterator * itr) 
{
    // Patrick
    itr->lst = lst;
    itr->currentLink = lst->frontSentinel->next;
}

void _removeLink (struct linkedList *lst, struct dLink * lnk);


int linkedListIteratorHasNext (struct linkedListIterator *itr) 
{
    // Patrick
    if (itr->currentLink->next != 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

TYPE linkedListIteratorNext (struct linkedListIterator *itr) 
{
    // Patrick
    return itr->currentLink = itr->currentLink->next;
}

/* think about the next one carefully. Draw a picture. What should itr->currentLink be pointing to after the remove operation ? */
void linkedListIteratorRemove (struct linkedListIterator *itr) 
{
    // Patrick
    itr->currentLink = itr->currentLink->prev;
    _removeLink(itr->lst, itr->currentLink->next);
}