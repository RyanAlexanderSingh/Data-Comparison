#ifndef INCLUDED_PERFORMANCE_TEST_H_
#define INCLUDED_PERFORMANCE_TEST_H_

#include "LinkedList.h"

#include <stdio.h>
#include <iostream>

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

  template<class Container>
  void test(Container const & c);

  template<typename T>
  void timeIt(T t);

  void runTests(int numOfElements);

  void createContainers(int numOfElements);
};





#endif /* INCLUDED_PERFORMANCE_TEST_H_ */