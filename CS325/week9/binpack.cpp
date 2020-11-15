/**
 * Author: Patrick Moore
 * Date: 03-10-2019
 * Description: 
 * 
 ***/

#include <iostream>
#include <fstream>
using namespace std;

#include <vector>
using std::vector;

#include <algorithm>
using std::reverse;

#include <cstdlib>
using std::rand;

struct Bin {
    vector<int> items;
    int capacity;
    int currentWeight;
};

void firstFit(vector<int>&, int, int, vector<Bin>&);
void firstFitDecreasing(vector<int>&, int, int, vector<Bin>&);
void bestFit(vector<int>&, int, int, vector<Bin>&);

void mergesort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

int main()
{

    srand(time(0));

    ifstream inputFile;
    ofstream outputFile;

    int cases;

    // open file streams
    inputFile.open("bin.txt");

    if (!inputFile.is_open())
    {
        cout << "Could not open bin.txt" << endl;
        return 0;
    }

    inputFile >> cases;

    while (inputFile)
    {
        if (inputFile.peek() > 0)
        {

            for (int i=0; i<cases; i++)
            {
                int capacity;
                int itemQty;

                inputFile >> capacity;
                inputFile >> itemQty;

                vector<int> items;
                vector<int> items2;

                for (int j=0; j<itemQty; j++)
                {
                    int item;
                    inputFile >> item;
                    items.push_back(item);
                    items2.push_back(item);
                }

                vector<Bin> firstFitBins;
                firstFit(items, itemQty, capacity, firstFitBins);

                vector<Bin> firstFitDecreasingBins;
                firstFitDecreasing(items, itemQty, capacity, firstFitDecreasingBins);

                vector<Bin> bestFitBins;
                bestFit(items2, itemQty, capacity, bestFitBins);

                cout << "Test Case " << i + 1;
                cout << ", First Fit: " << firstFitBins.size();
                cout << ", First Fit Decreasing: " << firstFitDecreasingBins.size();
                cout << ", Best Fit: " << bestFitBins.size();
                cout << endl;
            }


            cout << endl;
            cout << "random results: " << endl;
            for (int r=0; r<20; r++)
            {
                int cap, itemCount;
                cap = rand() % 10 + 10;
                itemCount = rand() % 20 + 30;

                vector<int> randItems;
                for (int k=0; k<itemCount; k++)
                {
                    int item = rand() % (cap - 1) + 1;
                    randItems.push_back(item);
                }
        

                vector<Bin> firstFitBins;
                firstFit(randItems, itemCount, cap, firstFitBins);

                vector<Bin> bestFitBins;
                bestFit(randItems, itemCount, cap, bestFitBins);

                vector<Bin> firstFitDecreasingBins;
                firstFitDecreasing(randItems, itemCount, cap, firstFitDecreasingBins);                

                cout << "Test Case " << r + 1;
                cout << ", First Fit: " << firstFitBins.size();
                cout << ", First Fit Decreasing: " << firstFitDecreasingBins.size();
                cout << ", Best Fit: " << bestFitBins.size();
                cout << endl;
                
            }
        }
    }

    // close streams.
    inputFile.close();

    return 0;
}

void firstFit(vector<int>& items, int qty, int cap, vector<Bin>& bins) 
{
    vector<int> binItems = {};
    bins.push_back({binItems, cap, 0});

    for (int k=0; k<qty; k++) 
    {

        bool inBin = false;
        int index = 0;

        while (!inBin)
        {
            if (bins[index].currentWeight + items[k] <= cap)
            {
                bins[index].items.push_back(items[k]);
                bins[index].currentWeight += items[k];
                inBin = true;
            }
            else 
            {
                index += 1;
                if (bins.size() == index) {
                    vector<int> newBinItems;
                    bins.push_back({newBinItems, cap, 0});
                }
            }
        }
    }
}

void firstFitDecreasing(vector<int>& items, int qty, int cap, vector<Bin>& bins) {
    mergesort(items, 0, qty - 1);
    reverse(items.begin(),items.end());
    firstFit(items, qty, cap, bins);
}

void bestFit(vector<int>& items, int qty, int cap, vector<Bin>& bins) {
    vector<int> binItems = {};
    bins.push_back({binItems, cap, 0});

    for (int k=0; k<qty; k++) 
    {
        bool needNew = true;
        int leastSpace = cap;
        int leastBin;

        for (int b=0; b<bins.size(); b++) {
            if (bins[b].currentWeight + items[k] <= cap)
            {
                int space = cap - (bins[b].currentWeight + items[k]);
                if (space <= leastSpace)
                {
                    leastSpace = space;
                    leastBin = b;  
                }
                needNew = false;
            }
        }

        if (needNew)
        {
            vector<int> newBinItems;
            newBinItems.push_back(items[k]);
            bins.push_back({newBinItems, cap, items[k]});
        }
        else
        {
            bins[leastBin].items.push_back(items[k]);
            bins[leastBin].currentWeight += items[k];
        }
    }
}

void mergesort(vector<int>& array, int firstIndex, int lastIndex)
{
    if (firstIndex < lastIndex)
    {
        int middleIndex = (firstIndex + lastIndex) / 2;
        mergesort(array, firstIndex, middleIndex);
        mergesort(array, middleIndex + 1, lastIndex);
        merge(array, firstIndex, middleIndex, lastIndex);
    }
}

void merge(vector<int>& array, int first, int middle, int last)
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