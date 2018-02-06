void dynArrayRemoveAt(struct dynArray * dy, int index);

struct dynArrayIterator {
    struct dynArray * da;
    int currentIndex;
};

void dynArrayIteratorInit(struct dynArray * da, struct dynArrayIterator * itr)
{
    itr->da = da;
    itr->currentIndex = 0;
}

int dynArrayIteratorHasNext(struct dynArrayIterator * itr)
{
    if (itr->da[itr->currentIndex + 1] != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

TYPE dynArrayIteratorNext (struct dynArrayItertor * itr)
{
    return itr->data[++itr->currentIndex];
}

void dynArrayIteratorRemove(struct dynArrayIterator *itr)
{
    dynArrayRemoveAt(itr->da, itr->currentIndex--);
}