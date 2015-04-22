#include "PerformanceTest.h"

  PerformanceTest::PerformanceTest(int numOfElements){
    LinkedList linkedList_(numOfElements);
    PerformanceTest::createStdVector(numOfElements);
    std::cin.get();
  }

  template<class OutIt>
  void PerformanceTest::init(OutIt it, int size){
    for (int i = 0; i < size; ++i){
      *it = i;
    }
  }

  void PerformanceTest::createStdVector(int numOfElements_){
    std::vector<int> ivec;
    init(std::back_inserter(ivec), numOfElements_);
    for (unsigned i = 0; i < ivec.size(); ++i){
      printf("ivec value: %f\n", ivec[i]);
    }
  }

  PerformanceTest::~PerformanceTest(){}
