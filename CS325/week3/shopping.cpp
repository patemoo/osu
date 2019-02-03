/**
 * Author: Patrick Moore
 * Date: 01-27-2019
 * Description: Shopping: takes in T test cases. a
 * For each case the program outputs the maximum 
 * total price of all goods that a family of F members 
 * can carry out during their shopping spree
 * 
 ***/

#include <iostream>
#include <fstream>
using namespace std;

int shopping(int [][2], int,  int);

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    int cases;

    // open file streams
    inputFile.open("shopping.txt");
    outputFile.open("results.txt");

    if (!inputFile.is_open())
    {
        cout << "Could not open shopping.txt" << endl;
        return 0;
    }

    while (inputFile)
    {
        if (inputFile.peek() > 0)
        {
            // read the number of cases
            inputFile >> cases;
            int caseNum = 0;

            // for each case: 
            for (int i=0; i< cases; i++)
            {
                caseNum += 1;
                // create items array
                int itemsLength;
                inputFile >> itemsLength;
                int items[itemsLength][2];
                for (int j=0; j < itemsLength; j++)
                {
                    inputFile >> items[j][0];
                    inputFile >> items[j][1];
                }

                // create family array
                int familyLength;
                inputFile >> familyLength;
                int family[familyLength];
                int grandTotal = 0;
            
                for (int j=1; j <= familyLength; j++)
                {
                    inputFile >> family[j];
                    grandTotal += shopping(items, itemsLength, family[j]);
                }

                // print results
                outputFile << "Test case: " << caseNum << endl;
                outputFile << "Total price: " << grandTotal << endl;
                outputFile << "Member items" << endl;

                for (int j=0; j<familyLength; j++)
                {
                    
                    outputFile << j+1 << ": ";

                    outputFile << endl;
                }
                outputFile << endl;
            }
        }
    }

    // close streams.
    inputFile.close();
    outputFile.close();

    return 0;
}

int shopping(int items[][2], int length, int weight) {
    int OP[length][weight];

    for (int w=0; w <= weight; w++)
    {
        OP[0][w] = 0;
    }

    for (int k=0; k < length; k++)
    {
        OP[k][0] = 0;

        for (int w=0; w < weight; w++)
        {
            if (k == 0 || w == 0) 
            {
                OP[k][w] = 0;
            } 
            else
            { 
            
                if (items[k-1][1] <= w)
                {
                    int leftover = w - items[k-1][1];
                    if (items[k-1][0] + OP[k-1][leftover] > OP[k-1][w])
                    {
                        OP[k][w] = items[k-1][0] + OP[k-1][leftover];
                        
                    }
                    else 
                    {
                        OP[k][w] = OP[k-1][w];
                    }
                }
                else
                {
                    OP[k][w] = OP[k-1][w];
                }
            }
        }
    }

    return OP[length-1][weight-1];
}