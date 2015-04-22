#include "PerformanceTest.h"

#include <vector>
#include <list>
#include <iterator>
#include <chrono>
#include <functional>

using namespace std::chrono;

class Target2
{
public:
  template <typename T>
  void Method(T a)
  {
    printf("test%i\n", a);
  }
};

PerformanceTest::PerformanceTest(int numOfElements){
  //LinkedList linkedList_(numOfElements);
  PerformanceTest::runTests(numOfElements);
}

///populate the container with n (size) elements, basic output iterator
template<class OutIt>
void PerformanceTest::init(OutIt it, int size){
  for (int i = 0; i < size; ++i){
    *it = i;
  }
}

template<typename T>
void PerformanceTest::timeIt(T t){

  high_resolution_clock::time_point start = high_resolution_clock::now();
  
  high_resolution_clock::time_point end = high_resolution_clock::now();

  //return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

///create a std::vector and using std::chrono::high_resolution_clock to return 
void PerformanceTest::runTests(int numOfElements_){

  //create the containers and print the build time
  std::vector<int> ivec;
  //init(std::back_inserter(ivec), numOfElements_);
  Target2 target;
  void (Target2::*shorterInt)(int) = &Target2::Method;
  (target.*shorterInt)(3);


  //std::cout << PerformanceTest::timeIt(PerformanceTest::init(std::back_inserter(ivec), numOfElements_)) << std::endl;

  //long long duration = PerformanceTest::timeIt(&PerformanceTest::test<std::vector<int>>, ivec);
  
//  long long duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  // add/remove an item at nth position
  int element;
  std::cin >> element;

}

PerformanceTest::~PerformanceTest(){}
