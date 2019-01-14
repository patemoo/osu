/**
 * Author: Patrick Moore
 * Date: 01-13-2019
 * Description:
 * 
 ***/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    int length,
        num;

    // open file streams
    inputFile.open("data.txt");
    outputFile.open("merge.txt");

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

            mergesort(array, 0, length - 1);

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