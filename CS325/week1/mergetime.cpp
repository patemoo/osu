/**
 * Author: Patrick Moore
 * Date: 01-13-2019
 * Description:
 * 
 ***/

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
using std::rand;

#include <chrono> 
using namespace std::chrono; 

void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main()
{

    srand(time(0));

    int nValue[8] = { 50000, 75000, 100000, 125000, 150000, 175000, 200000, 225000 };


    for (int j=0; j<8; j++)
    {
        int length = nValue[j];
        int array[length];

        for (int i=0; i<length; i++)
        {
            array[i] = rand() % 10000;
        }

        auto start = high_resolution_clock::now(); 

        mergesort(array, 0, length - 1);
        auto end = high_resolution_clock::now(); 

        auto duration = duration_cast<milliseconds>(end - start);

        cout << "array size: " << length << endl;
        cout << "time: " << duration.count() << endl;

    }

    return 0;
}

void mergesort(int array[], int firstIndex, int lastIndex)
{
    if (firstIndex < lastIndex)
    {
        int middleIndex = (firstIndex + lastIndex) / 2;
        mergesort(array, firstIndex, middleIndex);
        mergesort(array, middleIndex + 1, lastIndex);
        merge(array, firstIndex, middleIndex, lastIndex);

    }
}

void merge(int array[], int first, int middle, int last)
{
   int n1 = middle - first + 1;
   int n2 = last - middle;
   int left[n1 + 1];
   int right[n2 + 1];

   for (int i=1; i<=n1; i++)
   {
       left[i] = array[first + i - 1];
   }

   for (int j=1; j<=n2; j++)
   {
       right[j] = array[middle + j];
   }

   left[n1 + 1] = 999;
   right[n2 + 1] = 999;

   int i = 1;
   int j = 1;

   for (int k=first; k<=last; k++)
   {
       if (left[i] <= right[j])
       {
           array[k] = left[i];
           i = i + 1;
       } else {
           array[k] = right[j];
           j = j + 1;
       }
   }
}