/**
 * Author: Patirck Moore
 * Date: October 7, 2017
 * Description: count_letters function implementation.
 * */

#include "count.hpp"
#include "output.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

void count_letters(ifstream &file, int* letters)
{ 
  string paragraph; // Used to read in each paragraph of the file.
  string outFileName; // Used to store the name of each paragraphs output file.
  int pcount = 1; // keeps a paragraph count.

  // set letters array to all zeros.
  for (int i=0; i<26; i++)
  {
    letters[i] = 0;
  }

  while(file)
  {
    // make sure not to go past EOF.
    if (file.peek() > 0)
    {
      // get each paragraph one at a time.
      getline(file, paragraph);

      // loop through the letters of the paragraph 
      // and store to the corrrect locaton in the array.
      for (int i=0; i<paragraph.size(); i++)
      {
        if (tolower(paragraph[i]) >= 97)
        {
          letters[tolower(paragraph[i]) - 97] += 1;
        }
      }
      
      // prompt user for output file name.
      cout << "Enter file name for paragraph " << pcount << endl;
      cin >> outFileName;

      // create ofstream, open file. 
      // and pass to output_letters along with the letters array.
      ofstream outputFile;
      outputFile.open(outFileName);

      if (outputFile)
      {
        output_letters(outputFile, letters);
      }

      // close ofstream.
      outputFile.close();

      // increment paragraph count.
      pcount += 1;
    }
  }
}