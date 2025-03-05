/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <iostream>

void sandbox()
{
  Vector<int> newVector;

  std::cout << "Vector size is: " << newVector.size() << std::endl;
  std::cout << "Is vector empty: " << newVector.empty() << std::endl;

  std::cout << "Writing 100 elements to vector." << std::endl;
  for (int i = 0; i < 100; ++i)
  {
    newVector.push_back(i);
  }
  std::cout << "Vector size is: " << newVector.size() << std::endl;
  std::cout << "Is vector empty: " << newVector.empty() << std::endl;

  std::cout << "Vector front: " << newVector.front() << std::endl;
  std::cout << "Vector back: " << newVector.back() << std::endl;

  std::cout << "Write to front and back." << std::endl;
  newVector.front() = 114514;
  newVector.back() = 1919810;
  std::cout << "Vector front: " << newVector.front() << std::endl;
  std::cout << "Vector back: " << newVector.back() << std::endl;

  std::cout << "Random read/write" << std::endl;
  for (int i = 0; i < 100; ++i)
  {
    std::cout << newVector.at(i) << ",";
    newVector.at(i) = 114514;
    std::cout << newVector.at(i) << ",";
  }
  std::cout << std::endl;

  std::cout << "Pop." << std::endl;
  for (int i = 0; i < 100; ++i)
  {
    newVector.pop_back();
  }
  std::cout << "Vector size is: " << newVector.size() << std::endl;
  std::cout << "Is vector empty: " << newVector.empty() << std::endl;
}