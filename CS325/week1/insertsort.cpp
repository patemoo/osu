/**
 * Author: Patrick Moore
 * Date: 01-13-2019
 * Description: This program implements insertion sort.
 *              Imports data.txt, outputs sorted data to merge.txt
 * 
 ***/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void insertsort(int[], int);

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    int length,
        num;

    // open file streams
    inputFile.open("data.txt");
    outputFile.open("merge.txt");

    // handle error with import
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

            insertsort(array, length);

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

void insertsort(int array[], int size)
{
    for (int j=1; j<size; j++)
    {
        int key = array[j];
        int i = j - 1;

        while ( i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            array[i] = key;
            i--;
        }
    }
}