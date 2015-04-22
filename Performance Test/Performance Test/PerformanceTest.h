#ifndef INCLUDED_PERFORMANCE_TEST_H_
#define INCLUDED_PERFORMANCE_TEST_H_

#include "LinkedList.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>

class PerformanceTest{
public:
  //constructors

  ///default
  PerformanceTest();
  ///copy
  PerformanceTest(const PerformanceTest &pt);
  ///custom (n num of elements)
  PerformanceTest(int numOfElements);

  //destructor
  ~PerformanceTest();
private:
  template<class OutIt>
  void init(OutIt it, int size);

  void createStdVector(int numOfElements);
};



#endif /* INCLUDED_PERFORMANCE_TEST_H_ */