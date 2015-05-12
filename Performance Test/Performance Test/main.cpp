#include "PerformanceTest.h"

/**
  main.cpp
  Purpose: Comparing the performance of two different C++ data structures
  (std::list and std::vector)

  @author Ryan Singh
  */

int main(){
  //create both the linked list and the std::vector with n elements
  std::cout << "Enter desired container size for performance test..." << std::endl;
  int size;
  std::cin >> size;
  PerformanceTest test(size);
}