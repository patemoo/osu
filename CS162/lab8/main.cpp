/**
 * Author: Patrick Moore
 * Date: November 15, 2017
 * Description: This program opens a set of files, does a search for a target,
 *              sorts the values from the files, and then does a binary search.
 * */

#include "search.hpp"
#include "bubblesort.hpp"
#include "binarysearch.hpp"
#include "validate.hpp"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;

void readFile(vector<int> &, string);
void printSearchResult(int);
void outputResult(vector<int> &);

int main()
{
  int target;
  vector<int> numTxt;
  vector<int> earlyTxt;
  vector<int> middleTxt;
  vector<int> endTxt;

  // simple search:
  cout << "Please enter a target value." << endl;
  cinValidInt(target);

  cout << "\nnum.txt: ";
  readFile(numTxt, "num.txt");
  printSearchResult(search(numTxt, target));

  cout << "\nearly.txt: ";
  readFile(earlyTxt, "early.txt");
  printSearchResult(search(earlyTxt, target));

  cout << "\nmiddle.txt: ";
  readFile(middleTxt, "middle.txt");
  printSearchResult(search(middleTxt, target));

  cout << "\nend.txt: ";
  readFile(endTxt, "end.txt");
  printSearchResult(search(endTxt, target));

  // sort and output to file:
  outputResult(numTxt);
  outputResult(earlyTxt);
  outputResult(middleTxt);
  outputResult(endTxt);

  // binary search:
  cout << "\nPlease enter a target value for a binary search." << endl;
  cinValidInt(target);

  cout << "\nnum.txt: ";
  printSearchResult(binarySearch(numTxt, target));

  cout << "\nearly.txt: ";
  printSearchResult(binarySearch(earlyTxt, target));

  cout << "\nmiddle.txt: ";
  printSearchResult(binarySearch(middleTxt, target));

  cout << "\nend.txt: ";
  printSearchResult(binarySearch(endTxt, target));


  return 0;
}


/**
 * Description: takes a vector by reference adds a set of values from a file.
 * */
void readFile(vector<int> &nums, string filename)
{
  ifstream inputFile;
  int num;

  inputFile.open(filename);
  
  while (inputFile.peek() > 0)
  {
    inputFile >> num;
    nums.push_back(num);
  }

  inputFile.close();
}


/**
 * Description: takes in the result of a search function and prints the correct string.
 * */
void printSearchResult(int result)
{
  if (result >= 0)
  {
    cout << "target value found." << endl;
  }
  else
  {
    cout << "target value not found." << endl;
  }
}


/**
 * Description: outputs a sortered list to a file.
 * */
void outputResult(vector<int> &nums)
{
  string filename;
  cout << "\nPlease select a file name: ";
  cin >> filename;

  ofstream outputFile;
  outputFile.open(filename);

  if (outputFile)
  {
    bubbleSort(nums);

    cout << endl;
    for (int i=0; i<nums.size(); i++)
    {
      outputFile << nums[i] << " ";
      cout << nums[i] << " ";
    }

    cout << endl;
  }

  outputFile.close();
}