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
void insertVectorElement(Container c, int position){
  int value = 391; //adding bogus value
  c->insert(c->begin() + position, value);
}

///test function for the std::list(have to use iterator...)
template<typename Container>
void insertListElement(Container c, int position){
  int value = 391; //adding bogus value
  std::list<int>::iterator it;
  it = std::next(c->begin(), position);
  c->insert(it, value);
}

//times the execution time of a function multiple times and returns the average
template <typename Container>
double TimeFunction::timeIt(void(*function)(Container, int), Container c, int data){

  microseconds output_sum(0);
  int test_count = 5;
  for (int i = 0; i < test_count; ++i){
    auto start = high_resolution_clock::now();
    function(c, data);
    auto end = high_resolution_clock::now();
    microseconds time_takenms = duration_cast<microseconds>(end - start);
    output_sum += time_takenms;
  }
  return duration_cast<microseconds> (output_sum/test_count).count();
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
  int element_pos;
  std::cin >> element_pos;
  //std::vector
  std::cout << "Time taken to insert value 391 at element " << element_pos << " in std::vector: "
    << time.timeIt(insertVectorElement, &ivec, element_pos) << " microseconds\n" << std::endl;
  
  std::cout << "Time taken to insert value 391 at element " << element_pos << " in std::list: "
    << time.timeIt(insertListElement, &ilist, element_pos) << " microseconds\n" << std::endl;

  // add/remove an item at nth position
}

PerformanceTest::~PerformanceTest(){}
