#include "PerformanceTest.h"

#include <vector>
#include <list>
#include <iterator>
#include <chrono>

using namespace std::chrono;

PerformanceTest::PerformanceTest(int numOfElements){
  //LinkedList linkedList_(numOfElements);
  PerformanceTest::createContainers(numOfElements);
}

///populate the container with n (size) elements
template<class OutIt>
void PerformanceTest::init(OutIt it, int size){
  for (int i = 0; i < size; ++i){
    *it = i;
  }
}

///create a std::vector and using std::chrono::high_resolution_clock to return 
void PerformanceTest::createContainers(int numOfElements_){

  high_resolution_clock::time_point start = high_resolution_clock::now();
  std::vector<int> ivec;
  init(std::back_inserter(ivec), numOfElements_);
  high_resolution_clock::time_point end = high_resolution_clock::now();
  
  long long duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << "Vector build time: " << duration << " milliseconds with " << ivec.size() << " elements \n";

  start = high_resolution_clock::now();
  std::list<int> ilist;
  init(std::back_inserter(ilist), numOfElements_);
  end = high_resolution_clock::now();

  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << "List build time: " << duration << " milliseconds with " << ivec.size() << " elements \n";
}

PerformanceTest::~PerformanceTest(){}
