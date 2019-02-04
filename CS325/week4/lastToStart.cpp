/**
 * Author: Patrick Moore
 * Date: 02-03-2019
 * Description: last to start algorithm. Reads input form act.txt
 *  sorts activites by latest start time (merege sort). then selects based on availability. 
 *  prints results to the console
 * 
 ***/

#include "activity.hpp"

#include <iostream>
#include <fstream>
using namespace std;

#include <vector>
using std::vector;

void lastToStart(vector<Activity>&, int);
void mergesort(vector<Activity>&, int, int);
void merge(vector<Activity>&, int, int, int);

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    int setLength;
    int setNum = 0;

    // open file streams
    inputFile.open("act.txt");

    if (!inputFile.is_open())
    {
        cout << "Could not open act.txt" << endl;
        return 0;
    }

    while (inputFile)
    {
        if (inputFile.peek() > 0)
        {
            // set number
            setNum += 1;
            cout << "Set " << setNum << endl;

            // read the number of activites 
            inputFile >> setLength;
            // create activies vector
            vector<Activity> activities{};

            // fill vector with activites/values
            for (int i = 0; i < setLength; i++) {
                int number, start, finish;
                inputFile >> number;
                inputFile >> start;
                inputFile >> finish;
                activities.push_back({number, start, finish});
            }

            mergesort(activities, 0, setLength - 1);

            lastToStart(activities, setLength);
        }
    }

    // close streams.
    inputFile.close();

    return 0;
}

void lastToStart(vector<Activity>& array, int length) {

    int selectedIndex = 0;
    // create container for selected activites
    vector<Activity> selected{};    

    // initially push the activity with the last start time to the vector
    selected.push_back(Activity(
        array[0].getNumber(),
        array[0].getStart(),
        array[0].getFinish()
    ));
    
    // loop over the rest of the activities
    for (int k=1; k < length; k++) {

        // push the the next available activity to the selected vector
        if (array[k].getFinish() <= selected[selectedIndex].getStart()) {

            selected.push_back(Activity(
                array[k].getNumber(),
                array[k].getStart(),
                array[k].getFinish()
            ));

            // update the selected index
            selectedIndex += 1;
        }
    }

    // print results
    cout << "Number of activities selected = " << selectedIndex + 1 << endl;

    cout << "Activities: ";
    for (int i = selectedIndex; i >= 0; i--) {
        cout << selected[i].getNumber() << ' ';
    }
    cout << endl;
    cout << endl;
}

void mergesort(vector<Activity>& array, int firstIndex, int lastIndex)
{
    if (firstIndex < lastIndex)
    {
        int middleIndex = (firstIndex + lastIndex) / 2;
        mergesort(array, firstIndex, middleIndex);
        mergesort(array, middleIndex + 1, lastIndex);
        merge(array, firstIndex, middleIndex, lastIndex);
    }
}

void merge(vector<Activity>& array, int first, int middle, int last)
{
    int n1 = middle - first + 1;
    int n2 = last - middle;
    vector<Activity> left{};
    vector<Activity> right{};

    for (int i=1; i<=n1; i++)
    {
        left.push_back(Activity(
            array[first + i - 1].getNumber(),
            array[first + i - 1].getStart(),
            array[first + i - 1].getFinish()
        ));
    }

    for (int j=1; j<=n2; j++)
    {
        right.push_back(Activity(
            array[middle + j].getNumber(),
            array[middle + j].getStart(),
            array[middle + j].getFinish()
        ));
    }

    left.push_back(Activity(0, -99, -99));
    right.push_back(Activity(0, -99, -99));

    int i = 0;
    int j = 0;

    for (int k=first; k<=last; k++)
    {
        if (left[i].getStart() >= right[j].getStart())
        {
            array[k].setValues(
                left[i].getNumber(),
                left[i].getStart(),
                left[i].getFinish()
            );

            i = i + 1;
        } else {
            array[k].setValues(
                right[j].getNumber(),
                right[j].getStart(),
                right[j].getFinish()
            );

            j = j + 1;
        }
    }
}