#ifndef INCLUDED_PERFORMANCE_TEST_H_
#define INCLUDED_PERFORMANCE_TEST_H_

#include "LinkedList.h"

#include <stdio.h>
#include <iostream>

class TimeFunction{
public:
  //constructors

  ///default
  TimeFunction();
  ///copy
  TimeFunction(const TimeFunction &pt);
  ///custom (n num of elements)
  TimeFunction(int numOfElements);

  //destructor
  ~TimeFunction();

  double clockDiffToSecs(long clockDiff);

  template<class Proc>
  void timeIt(Proc proc, int n);
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
  template<class OutIt>
  void init(OutIt it, int size);

  void createStdVector(int numOfElements);
};





#endif /* INCLUDED_PERFORMANCE_TEST_H_ */