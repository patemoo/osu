/**
 * Author: Patrick Moore
 * Date: 01-13-2019
 * Description: This program implements insertion sort.
 *              
 * 
 ***/

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
using std::rand;

#include <chrono> 
using namespace std::chrono; 

void insertsort(int[], int);

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
        insertsort(array, length);
        auto end = high_resolution_clock::now(); 

        auto duration = duration_cast<milliseconds>(end - start);

        cout << "array size: " << length << endl;
        cout << "time: " << duration.count() << endl; 
    
    }

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

