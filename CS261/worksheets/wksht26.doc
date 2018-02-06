
            dynamicArrayBag   linkedListBag   orderedArrayBag
add             O(1)            O(1)            O(log n)
contains        O(n)            O(n)            O(log n)
remove          O(n)            O(n)            O(n)


1. O(log n)

2. O(log n)

3. O(1)+

4. O(log n)+

5. O(n)


/*Assume you have access to all existing dynArr functions */
/* _binarySearch is also included in dynArr.c now as an internal function! */
int _binarySearch(TYPE *data, int size, TYPE testValue);

/* These are the new functions to take advantage of the ordered dynamic array
and available to the end user , so they will be declared in the .h file */
int dyArrayBinarySearch (struct dyArray * da, TYPE testValue) 
{
    return _binarySearch (da->data, da->size, testValue); 
}

void orderedArrayAdd (struct dyArray *da, TYPE newElement) 
{
    int index = _binarySearch(da->data, da->size, newElement);
    dyArrayAddAt (da, index, newElement); /* takes care of resize if necessary*/
}


/* you must complete the following */
int orderedArrayContains (struct dyArray *da, TYPE testElement) 
{
    // Patrick
    assert(da != 0);
    int index = _binarySearch(da->data, da->size, testElement)
    if (da->data[index] == testElement)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void orderedArrayRemove (struct dyArray *da, TYPE testElement) 
{
    // Patrick
    assert(da != 0);
    removeDynArr(da, testElement);
}