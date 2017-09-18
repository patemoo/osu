/*******************************************
 * Author: Patrick Moore
 * Date: July 19, 2017
 * Description: Box interface declaration.
 * *****************************************/

#ifndef BOX_HPP
#define BOX_HPP

class Box 
{
  private:
    double height;
    double width;
    double length;
  public:
    Box();
    Box(double, double, double);
    bool setHeight(double);
    bool setWidth(double);
    bool setLength(double);
    double calcVolume();
    double calcSurfaceArea();
};

#endif
