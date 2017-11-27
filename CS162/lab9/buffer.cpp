/**
 * Author: Patrick Moore
 * Date: November 25, 2017
 * Description: Buffer function implementation
 * */

#include "buffer.hpp"

#include <queue>
using std::queue;

#include <iostream>
using std::cout;
using std::endl;

void printBuffer(queue<int>);

void bufferSimulation(int rounds, int endChance, int frontChance)
{
  queue<int> buffer;
  double averageLength = 0;

  for (int i=0; i<rounds; i++)
  {
    int N = rand() % 999 + 1;

    cout << "\n\nRound: " << i+1 << endl;
    int endRand = rand() % 99 + 1;
    if (endChance >= endRand)
    {
      buffer.push(N);
    }
    int frontRand = rand() % 99 + 1;
    if (frontChance >= frontRand && !buffer.empty())
    {
      buffer.pop();
    }

    printBuffer(buffer);

    if (i > 0)
    {
      averageLength = (averageLength * i + buffer.size()) / (i + 1);
    }

    cout << "\naverage length: " << averageLength << endl;
  }
}

/**
 * Description: Prints the values in the buffer as well as the buffer length
 * */
void printBuffer(queue<int> buffer)
{
  queue<int> temp = buffer;
  
  cout << "values: ";
  if (temp.size() > 0)
  {
    for (int i=0; i<buffer.size(); i++)
    {
      cout << temp.front() << " ";
      temp.pop();
    }
  }
  else
  {
    cout << "empty";
  }
  cout << "\nlength: " << buffer.size();
}