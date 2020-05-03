/*--------------ИСПОЛЬЗОВАНИЕ--------------
#include <simpletimer.h>
в начале функции main создать объект класса:
simpletimer имя;
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
  std::cout << "\nПрошло времени "<< result << " секунд\n";
}
