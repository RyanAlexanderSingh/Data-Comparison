#ifndef INCLUDED_PERFORMANCE_TEST_H_
#define INCLUDED_PERFORMANCE_TEST_H_

#include "LinkedList.h"

#include <stdio.h>
#include <iostream>

class TimeFunction{
  public:
    template <typename Container>
    double timeIt(void(*function)(Container, int, int), Container c, int element_pos, int element_val = 0);

    template <typename Container>
    double timeIt(void(*function)(Container, int), Container c, int element_pos);
};

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
  
  void runTests(int numOfElements);
};





#endif /* INCLUDED_PERFORMANCE_TEST_H_ */