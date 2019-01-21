/**
 * Author: Patrick Moore
 * Date: 01-20-2019
 * Description: 4 way merge sort
 * 
 ***/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mergesort4(int[], int, int);
void merge(int[], int, int, int, int, int);
void merge(int[], int, int, int);

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    int length,
        num;

    // open file streams
    inputFile.open("data.txt");
    outputFile.open("merge4.txt");

    if (!inputFile.is_open())
    {
        cout << "Could not open data.txt" << endl;
        return 0;
    }

    while (inputFile)
    {
        if (inputFile.peek() > 0)
        {
            inputFile >> length;
            int array[length];

            for (int i=0; i<length; i++)
            {
                inputFile >> num;
                array[i] = num;
            }

            mergesort4(array, 0, length - 1);

            for (int i=0; i<length; i++)
            {
                outputFile << array[i] << ' ';
            }
            outputFile << endl;
        }
    }

    // close streams.
    inputFile.close();
    outputFile.close();

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

   one[n1 + 1] = 999;
   two[n2 + 1] = 999;
   three[n3 + 1] = 999;
   four[n4 + 1] = 999;

   int g = 1;
   int h = 1;
   int i = 1;
   int j = 1;

   for (int k=p; k<=r; k++)
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
