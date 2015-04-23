#include "PerformanceTest.h"

#include <vector>
#include <list>
#include <iterator>
#include <chrono>
#include <functional>

using namespace std::chrono;

///populate the container with n (size) elements, basic output iterator
//function template errors if its part of PerformanceTest class -> find out why later
template<typename OutIt>
void createContainers(OutIt it, int size){
  for (int i = 0; i < size; ++i){
    *it = i;
  }
}

///using insert to add element at location (moves all subsequent elements up one place)
template<typename Container>
void insertElement(Container c, int position){
  int value = 391; //adding bogus value
  c->insert(c->begin() + position, value);

  //just for testing purposes
  /*for (int i = 0; i < c.size(); ++i){
    printf("Value:%i\n", c[i]);
  }*/

}

template <typename Container>
double TimeFunction::timeIt(void(*function)(Container, int), Container c, int data){

  auto start = high_resolution_clock::now();
  function(c, data);
  auto end = high_resolution_clock::now();

  return duration_cast<microseconds>(end - start).count();
}

PerformanceTest::PerformanceTest(int numOfElements){
  //LinkedList linkedList_(numOfElements);
  PerformanceTest::runTests(numOfElements);
}

///create a std::vector and using std::chrono::high_resolution_clock to return 
void PerformanceTest::runTests(int numOfElements_){

  TimeFunction time;

  //create the containers and print the build time
  //std::vector
  std::vector<int> ivec;
  std::cout << "\nVector build time: "
    << time.timeIt(createContainers, &std::back_inserter(ivec), numOfElements_)
    << " microseconds\n" << std::endl;

  //std::list
  std::list<int> ilist;
  std::cout << "List build time: "
    << time.timeIt(createContainers, &std::back_inserter(ilist), numOfElements_)
    << " microseconds\n" << std::endl;

  //update (add/remove item)
  //std::vector
  int elementPos;
  std::cin >> elementPos;

  std::cout << "Time taken to insert value at element " << elementPos << " in vector: "
    << time.timeIt(insertElement, &ivec, elementPos) << " microseconds\n" << std::endl;

  for (int i = 0; i < ivec.size(); ++i){
    printf("Value:%i\n", ivec[i]);
  }

    // add/remove an item at nth position
}

PerformanceTest::~PerformanceTest(){}
