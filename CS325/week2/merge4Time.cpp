/**
 * Author: Patrick Moore
 * Date: 01-13-2019
 * Description: modified 4 way merge to collect runtime info
 * 
 ***/

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
using std::rand;

#include <chrono> 
using namespace std::chrono; 

void mergesort4(int[], int, int);
void merge(int[], int, int, int, int, int);
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

        mergesort4(array, 0, length - 1);
        auto end = high_resolution_clock::now(); 

        auto duration = duration_cast<milliseconds>(end - start);

        cout << "array size: " << length << endl;
        cout << "time: " << duration.count() << endl;

    }

    return 0;
}

void mergesort4(int array[], int p, int r)
{   
    if (p + 2 < r)
    {
        int l = (r - p + 1) / 4;
        int x = p + l - 1;
        int y = p + 2 * l - 1;
        int z = p + 3 * l - 1;

        mergesort4(array, p, x);
        mergesort4(array, x + 1, y);
        mergesort4(array, y + 1, z);
        mergesort4(array, z + 1, r);
        merge(array, p, x, y, z, r);
    }
    else if (p < r)
    {
        int q = (p + r) / 2;
        mergesort4(array, p, q);
        mergesort4(array, q + 1, r);
        merge(array, p, q, r);
    }
}

void merge(int array[], int p, int x, int y, int z, int r)
{
    int n1 = x - p + 1;
    int n2 = y - x;
    int n3 = z - y;
    int n4 = r - z;
    int one[n1 + 1];
    int two[n2 + 1];
    int three[n3 + 1];
    int four[n4 + 1];

    for (int g=1; g<=n1; g++)
    {
        one[g] = array[p + g - 1];
    }

    for (int h=1; h<=n2; h++)
    {
        two[h] = array[x + h];
    }

    for (int i=1; i<=n3; i++)
    {
        three[i] = array[y + i];
    }

    for (int j=1; j<=n4; j++)
    {
        four[j] = array[z + j];
    }

    one[n1 + 1] = 100001;
    two[n2 + 1] = 100001;
    three[n3 + 1] = 10001;
    four[n4 + 1] = 10001;

    int g = 1;
    int h = 1;
    int i = 1;
    int j = 1;

    int first = p;
    int last = r;

    for (int k=first; k<=last; k++)
    {
        if ((one[g] <= two[h] && one[g] <= three[i]) && one[g] <= four[j])
        {
            array[k] = one[g];
            g = g + 1;
        } else if ((two[h] <= one[g] && two[h] <= three[i]) && two[h] <= four[j])
        {
            array[k] = two[h];
            h = h + 1;
        } else if ((three[i] <= one[g] && three[i] <= two[h]) && three[i] <= four[j])
        {
            array[k] = three[i];
            i = i + 1;
        } else if ((four[j] <= one[g] && four[j] <= two[h]) && four[j] <= three[i]) 
        {
            array[k] = four[j];
            j = j + 1;
        }
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

   left[n1 + 1] = 10001;
   right[n2 + 1] = 10001;

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