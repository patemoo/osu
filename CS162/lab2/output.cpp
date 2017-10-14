/**
 * Author: Patirck Moore
 * Date: October 7, 2017
 * Description: output_letters function implementation.
 * */

#include "output.hpp"

void output_letters(ofstream &file, int* letters)
{
  // loop through for each letter of the alphabet
  // and create the frequency output.
  for (int i=0; i<26; i++)
  {
    file << static_cast<char>(97+i) << ": " << letters[i] << "\n";
  }  
}