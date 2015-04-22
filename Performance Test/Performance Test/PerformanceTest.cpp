#include "PerformanceTest.h"

#include <vector>
#include <iterator>
#include <chrono>

using namespace std::chrono;

PerformanceTest::PerformanceTest(int numOfElements){
  //LinkedList linkedList_(numOfElements);
  PerformanceTest::createStdVector(numOfElements);
}

template<class Container>
void PerformanceTest::test(Container const &c){
  std::for_each
}

///populate the container with n (size) elements
template<class OutIt>
void PerformanceTest::init(OutIt it, int size){
  for (int i = 0; i < size; ++i){
    *it = i;
  }
}

///create a std::vector and using std::chrono::high_resolution_clock to return 
void PerformanceTest::createStdVector(int numOfElements_){

  high_resolution_clock::time_point start = high_resolution_clock::now();
  std::vector<int> ivec;
  init(std::back_inserter(ivec), numOfElements_);
  high_resolution_clock::time_point end = high_resolution_clock::now();
  
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

  std::cout << duration;
  system("pause");
}

PerformanceTest::~PerformanceTest(){}
