/**
 * Author: Patrick Moore
 * Date: 02-17-2019
 * Description: Takes a wrestlers list and rivalry list 
 * and splits wrestlers into a babyface group and heel group
 * 
 ***/

#include <iostream>
#include <fstream>
using namespace std;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>

struct rivalry {
    string w1;
    string w2;
};

void wrestler(vector<string>&, vector<rivalry>&, int);

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string fileName;

    // get file name
    cout << "enter file name:" << endl;
    cin >> fileName;

    // open file streams
    inputFile.open(fileName);

    if (!inputFile.is_open())
    {
        cout << "Could not open " << fileName << endl;
        return 0;
    }

    while (inputFile)
    {
        if (inputFile.peek() > 0)
        {
            
            int wLength;
            int rLength;

            // read the number of wrestlers 
            inputFile >> wLength;

            // create wrestler list
            vector<string> wrestlers;
            for (int i = 0; i < wLength; i++) {
                string name;
                inputFile >> name;
                wrestlers.push_back(name);
            }

            // read number of rivalries
            inputFile >> rLength;

            // create rival list
            vector<rivalry> rivals;
            for (int i = 0; i< rLength; i++) {
                string w1, w2;
                inputFile >> w1;
                inputFile >> w2;
                rivalry newRivals = {w1, w2};

                rivals.push_back(newRivals);
            }

            wrestler(wrestlers, rivals, rLength);

        }
    }

    // close streams.
    inputFile.close();

    return 0;
}

void wrestler(vector<string>& wrestlers, vector<rivalry>& rivals, int rLength) {
    
    bool possible = true;
    vector<string> babyfaces;
    vector<string> heels;
    int bcount = 1;
    int hcount = 0;

    babyfaces.push_back(wrestlers[0]);


    for (int i = 0; i < rLength; i++) {
 
        // if wrestler one is in babyfaces and wrestler two is not in heels, put wrestler two in heels.
        if (std::find(babyfaces.begin(), babyfaces.end(), rivals[i].w1) != babyfaces.end())
        {
            if (std::find(babyfaces.begin(), babyfaces.end(), rivals[i].w2) != babyfaces.end())
            {
                possible = false;
            }
            else if (std::find(heels.begin(), heels.end(), rivals[i].w2) != heels.end())
            {}
            else {
                heels.push_back(rivals[i].w2);
                hcount += 1;
            }
        }
        // if wrestler one is in heels and wrestler two is not in babyfaces, put wrestler two in babyfaces.
        else if (std::find(heels.begin(), heels.end(), rivals[i].w1) != heels.end())
        {
            if (std::find(heels.begin(), heels.end(), rivals[i].w2) != heels.end())
            {
                possible = false;
            }
            else if (std::find(babyfaces.begin(), babyfaces.end(), rivals[i].w2) != babyfaces.end())
            {}
            else {
                babyfaces.push_back(rivals[i].w2);
                bcount += 1;
            }
        }
        // if wrestler two is in babyfaces and wrestler one is not in heels, put wrestler one in heals
        else if (std::find(babyfaces.begin(), babyfaces.end(), rivals[i].w2) != babyfaces.end())
        {
            if (std::find(heels.begin(), heels.end(), rivals[i].w1) != heels.end())
            {}
            else {
                heels.push_back(rivals[i].w1);
                hcount += 1;
            }
        }
        // if wrestler two is in heels and wrestler one is not in babyfaces, put wrestler two in babyfaces
        else if (std::find(heels.begin(), heels.end(), rivals[i].w2) != heels.end())
        {
            if (std::find(babyfaces.begin(), babyfaces.end(), rivals[i].w1) != babyfaces.end())
            {}
            else {
                babyfaces.push_back(rivals[i].w1);
                bcount += 1;
            }
        }
        // if neither wrestler is already in a group, put wrestler one in babyfaces and wrestler two in heels
        else 
        {
            babyfaces.push_back(rivals[i].w1);
            heels.push_back(rivals[i].w2);
            bcount += 1;
            hcount += 1;
        }
    }
    
    // print results
    if (possible)
    {
        cout << "Yes" << endl;
        cout << "Babyfaces: ";
        for (int i = 0; i < bcount; i++) {
            cout << babyfaces[i] << ' ';
        }
        cout << endl;
        cout << "Heels: ";
        for (int i = 0; i < hcount; i++) {
            cout << heels[i] << ' ';
        }
        cout << endl;
    }
    else 
    {
        cout << "Not possible!" << endl;
    }
}