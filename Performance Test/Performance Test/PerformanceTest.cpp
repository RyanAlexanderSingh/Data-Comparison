#include "LinkedList.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>

class PerformanceTest{
  PerformanceTest(int numOfElements){
    LinkedList linkedList_(numOfElements);
    PerformanceTest::createStdVector(numOfElements);
    std::cin.get();
  }

  template<class OutIt>
  void init(OutIt it, int size){
    for (int i = 0; i < size; ++i){
      *it = i;
    }
  }

  void PerformanceTest::createStdVector(int numOfElements_){
    std::vector<int> ivec;
    init(std::back_inserter(ivec), numOfElements_);

  }

  PerformanceTest::~PerformanceTest(){}
};
