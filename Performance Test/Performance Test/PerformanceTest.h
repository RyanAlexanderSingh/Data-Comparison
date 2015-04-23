#ifndef INCLUDED_PERFORMANCE_TEST_H_
#define INCLUDED_PERFORMANCE_TEST_H_

#include "LinkedList.h"

#include <stdio.h>
#include <iostream>

class TimeFunction{
  public:
    template <typename P>
    double timeIt(void(*function)(P, int), P p, int data);
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
  
  void tester(int i);

  void runTests(int numOfElements);
  
};





#endif /* INCLUDED_PERFORMANCE_TEST_H_ */