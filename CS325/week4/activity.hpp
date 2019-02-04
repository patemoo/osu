/**
 * Author: Patrick Moore
 * Date: 02/03/2019
 * Description: Activity class interface
 * */

#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

class Activity
{
  private:
    int number;
    int start;
    int finish;
  public:
    Activity(int = 0, int = -1, int = -1);
    int getNumber();
    int getStart();
    int getFinish();

    void setValues(int, int, int);
};

#endif