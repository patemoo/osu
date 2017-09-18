/*******
 * Author: Patrick Moore
 * Date: July 23, 2017
 * Description: Quadratic interface decloration.
 *******************************/

#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

class Quadratic 
{
  private:
    double a;
    double b;
    double c;
  public:
    Quadratic();
    Quadratic(double, double, double);
    double getA();
    double getB();
    double getC();
    void setA(double);
    void setB(double);
    void setC(double);
    double valueFor(double);
    int numRealRoots();
};

#endif