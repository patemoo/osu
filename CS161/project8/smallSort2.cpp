/**
 * Author: Patrick Moore
 * Date: August 1, 2017
 * Description: smallSort2 uses pointer parameters to take in each argument's
 *              memory addresses. Then using the indirection operator it referrences 
 *              each value and does the same sorting logic as the original smallSort
 *              function from project 4.
 **/

// I have chosen to place the astrisk on the type to distinguish better between
// the pointer parameter definition in the function header and the indirection operator
// being used through out the function's code block.
void smallSort2(int* aAddress, int* bAddress, int* cAddress)
{
  // keep looping until order is correct.
  while (!(*aAddress < *bAddress && *bAddress < *cAddress))
  {
    int temp;

    // compare and swap first two values if needed
    if (*aAddress > *bAddress)
    {
      temp = *aAddress;
      *aAddress = *bAddress;
      *bAddress = temp;
    }

    // compare and swap last two values if needed
    if (*bAddress > *cAddress)
    {
      temp = *bAddress;
      *bAddress = *cAddress;
      *cAddress = temp;
    }
  }
}