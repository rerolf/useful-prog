/*--------------USE--------------
#include <simpletimer.h>
in the beginnign of main() function, add a class object;
simpletimer name;
*/
#pragma once
#include <chrono>
#include <iostream>
#include <iomanip>
class simpletimer
{
public:
  simpletimer();
  ~simpletimer();
private:
  std::chrono::high_resolution_clock::time_point start, end;
  std::chrono::duration<float> duration;
};

simpletimer::simpletimer()
{
  start = std::chrono::high_resolution_clock::now();
}

simpletimer::~simpletimer()
{
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  float result = duration.count();
  std::cout << "\nDuration "<< result << " seconds\n";
}
