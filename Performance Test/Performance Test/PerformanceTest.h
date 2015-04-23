#ifndef INCLUDED_PERFORMANCE_TEST_H_
#define INCLUDED_PERFORMANCE_TEST_H_

#include "LinkedList.h"

#include <stdio.h>
#include <iostream>

class TimeFunction{
  public:
    template <typename P>
    double timeIt(void(*function)(P), P p);
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
  template<typename OutIt>
  void init(OutIt it);

  void tester(int i);

  void runTests(int numOfElements);

  void createContainers(int numOfElements);
};





#endif /* INCLUDED_PERFORMANCE_TEST_H_ */