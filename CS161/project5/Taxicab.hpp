/*******************************************
 * Author: Patrick Moore
 * Date: July 19, 2017
 * Description: Taxicab interface declaration.
 * *****************************************/

 #ifndef TAXICAB_HPP
 #define TAXICAB_HPP

class Taxicab
{
  private:
    int x;
    int y;
    int odo;
  public:
   Taxicab();
   Taxicab(int, int);
   int getXCoord();
   int getYCoord();
   int getDistanceTraveled();
   void moveX(int);
   void moveY(int);
};

 #endif