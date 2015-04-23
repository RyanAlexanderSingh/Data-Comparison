#include "PerformanceTest.h"

#include <vector>
#include <list>
#include <iterator>
#include <chrono>
#include <functional>

using namespace std::chrono;

template <typename P>
double TimeFunction::timeIt(void(*function)(P), P p){

  high_resolution_clock::time_point start = high_resolution_clock::now();
  function(p);
  high_resolution_clock::time_point end = high_resolution_clock::now();

  return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}


PerformanceTest::PerformanceTest(int numOfElements){
  //LinkedList linkedList_(numOfElements);
  PerformanceTest::runTests(numOfElements);
}

template <typename P>
void print_test(P p){
  for (int i = 0; i < 1000; ++i){
    *p = i;
    printf("Wha...%i\n", p[i]);
  }
}

///populate the container with n (size) elements, basic output iterator
template<typename OutIt>
void PerformanceTest::init(OutIt it){

}

///create a std::vector and using std::chrono::high_resolution_clock to return 
void PerformanceTest::runTests(int numOfElements_){

  //create the containers and print the build time
  std::vector<int> ivec;

  int size = numOfElements_;
  //init(std::back_inserter(ivec), numOfElements_);
  TimeFunction time;
  std::cout << time.timeIt(print_test, &std::back_inserter(ivec)) << std::endl;

  // add/remove an item at nth position

}

PerformanceTest::~PerformanceTest(){}
