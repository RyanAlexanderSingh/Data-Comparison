#include "PerformanceTest.h"

#include <vector>
#include <iterator>
#include <ctime>

///returns the time in microseconds
double TimeFunction::clockDiffToSecs(long clockDiff){
  return double(clockDiff) / CLOCKS_PER_SEC; //1000 clocks per sec 
}

///measures execution time of small code snippets and derived from the Python function "timeit"
template<class Proc>
void TimeFunction::timeIt(Proc proc, int repeats = 1){
  std::clock_t const start = std::clock(); //grab the current time
  for (int i = 0; i < repeats; ++i) proc();
  std::clock_t const end = std::clock //when loop ends
    if (TimeFunction::clockDiffToSecs(end - start) < .2)
      return timeIt(proc, repeats * 5);
  return TimeFunction::clockDiffToSecs(end - start) * (1e6 / repeats);
}

PerformanceTest::PerformanceTest(int numOfElements){
  LinkedList linkedList_(numOfElements);
  PerformanceTest::createStdVector(numOfElements);
}

///populate the container with n (size) elements
template<class OutIt>
void PerformanceTest::init(OutIt it, int size){
  for (int i = 0; i < size; ++i){
    *it = i;
  }
}

void PerformanceTest::createStdVector(int numOfElements_){
  std::vector<int> ivec;
  init(std::back_inserter(ivec), numOfElements_);
  //just for testing purposes (remove later)
  /*for (unsigned i = 0; i < ivec.size(); ++i){
    printf("ivec value: %i\n", ivec[i]);
    }*/
}

PerformanceTest::~PerformanceTest(){}
