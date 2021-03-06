#include "PerformanceTest.h"

#include <vector>
#include <list>
#include <iterator>
#include <chrono>
#include <functional>
#include <algorithm>

using namespace std::chrono;

///make some default containers, we dont need to store them as we only want the execution time
template<typename Container>
void createContainers(Container c, int size){
  for (int i = 0; i < size; ++i){
    std::back_inserter(c) = i;
  }
}

///populate the container with n (size) elements, basic output iterator
//function template errors if its part of PerformanceTest class -> find out why later
template<typename OutIt>
void createContainersIterator(OutIt it, int size){
  for (int i = 0; i < size; ++i){
    *it = i;
  }
}

///using insert to add element at location (moves all subsequent elements up one place, only performing once so its much more efficient)
template<typename Container>
void insertVectorElement(Container c, int position, int value){
  c.insert(c.begin() + position, value);
}

///test function for the std::list(have to use iterator...)
template<typename Container>
void insertListElement(Container c, int position, int value){
  //we could deduce the type with auto but we'll be using ints for the time being
  std::list<int>::iterator it;
  it = std::next(c.begin(), position);
  c.insert(it, value);
}

///Removing an element from a std::vector
template<typename Container>
void removeVectorElement(Container c, int position){
  c.erase(c.begin() + position);
}

///Removing an element from a std::list (consider merging with std::vector removeVectorElement)
template<typename Container>
void removeListElement(Container c, int position){
  std::list<int>::iterator it;
  it = c.begin();
  std::advance(it, position);
  c.erase(it);
}

///Access element by position in a std::vector
template<typename Container>
void accessVectorElement(Container c, int element){
  std::vector<int>::iterator it = std::find(c.begin(), c.end(), element);
  int position = std::distance(c.begin(), it);
  if (position == c.size())
    std::cout << "Element could not be found" << std::endl;
}

///finding a specific element by returning its position
template<typename Container>
void accessListElement(Container c, int element){
  std::list<int>::iterator it = std::find(c.begin(), c.end(), element);
  int position = std::distance(c.begin(), it);
  if (position == c.size())
    std::cout << "Element could not be found" << std::endl;
}

/////times the execution time of a function multiple times and returns the average
template <typename Container>
double TimeFunction::timeIt(void(*function)(Container, int, int), Container c, int element_pos, int element_val){

  microseconds output_sum(0);
  int test_count = 1;
  Container temp_cont = c;
  for (int i = 0; i < test_count; ++i){
    auto start = high_resolution_clock::now();
    function(c, element_pos, element_val);
    auto end = high_resolution_clock::now();
    microseconds time_takenms = duration_cast<microseconds>(end - start);
    output_sum += time_takenms;
    c = temp_cont;
  }
  return duration_cast<microseconds> (output_sum / test_count).count();
}

///Function overloading -- This function will be used for creating containers/ remvoing elements (do not require a value to add)
template <typename Container>
double TimeFunction::timeIt(void(*function)(Container, int), Container c, int element_pos){

  microseconds output_sum(0);
  int test_count = 1;
  Container temp_cont = c;
  for (int i = 0; i < test_count; ++i){
    auto start = high_resolution_clock::now();
    function(c, element_pos);
    auto end = high_resolution_clock::now();
    microseconds time_takenms = duration_cast<microseconds>(end - start);
    output_sum += time_takenms;
    c = temp_cont;
  }
  return duration_cast<microseconds> (output_sum / test_count).count();
}

PerformanceTest::PerformanceTest(int numOfElements){
  PerformanceTest::runTests(numOfElements);
}

///create a std::vector and using std::chrono::high_resolution_clock to return 
void PerformanceTest::runTests(int numOfElements_){

  TimeFunction time;

  //create the containers and print the build time
  //std::vector
  std::vector<int> ivec;
  std::cout << "\nVector build time: "
    << time.timeIt(createContainers, ivec, numOfElements_)
    << " microseconds\n" << std::endl;

  //std::list
  std::list<int> ilist;
  std::cout << "List build time: "
    << time.timeIt(createContainers, ilist, numOfElements_)
    << " microseconds\n" << std::endl;

  //for debugging purposes
  createContainersIterator(&std::back_inserter(ivec), numOfElements_);
  createContainersIterator(&std::back_inserter(ilist), numOfElements_);

  //update (add/remove item)
  int element_pos = 0, element_value = 0;
  std::cout << "Enter element position to add a value to the containers: " << std::endl;
  std::cin >> element_pos;
  std::cout << "Now enter value to be added to that position: " << std::endl;
  std::cin >> element_value;

  //std::vector
  std::cout << "Time taken to insert value " << element_value << " at element " << element_pos << " in std::vector: "
    << time.timeIt(insertVectorElement, ivec, element_pos, element_value) << " microseconds\n" << std::endl;
  //std::list
  std::cout << "Time taken to insert value " << element_value << " at element " << element_pos << " in std::list: "
    << time.timeIt(insertListElement, ilist, element_pos, element_value) << " microseconds\n" << std::endl;

  //for debugging purposes  
  ivec.insert(ivec.begin() + element_pos, element_value);
  std::list<int>::iterator it;
  it = std::next(ilist.begin(), element_pos);
  ilist.insert(it, element_value);

  //remove an element
  std::cout << "Enter element position to remove a value to the containers: " << std::endl;
  std::cin >> element_pos;
  std::cout << "Time taken to remove element " << element_pos << " in std::vector: "
    << time.timeIt(removeVectorElement, ivec, element_pos) << " microseconds\n" << std::endl;
  std::cout << "Time taken to remove element " << element_pos << " in std::list: "
    << time.timeIt(removeListElement, ilist, element_pos) << " microseconds\n" << std::endl;

  //for debugging purposes
  ivec.erase(ivec.begin() + element_pos);
  it = ilist.begin();
  std::advance(it, element_pos);
  ilist.erase(it);

  //access time (time taken to find element by position)
  std::cout << "Enter element to be found by position" << std::endl;
  std::cin >> element_pos;
  std::cout << "Time taken to find element " << element_pos << " in std::vector "
    << time.timeIt(accessVectorElement, ivec, element_pos) << " microseconds\n" << std::endl;
  std::cout << "Time taken to find element " << element_pos << " in std::list: "
    << time.timeIt(accessListElement, ilist, element_pos) << " microseconds\n" << std::endl;

  //this is not ideal but it works for the time being (never use for real programs)
  system("pause");
}

PerformanceTest::~PerformanceTest(){}
