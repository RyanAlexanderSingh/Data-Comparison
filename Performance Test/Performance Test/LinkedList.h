#ifndef INCLUDED_LINKED_LIST_H_
#define INCLUDED_LINKED_LIST_H_

class LinkedList{
public:
  //constructors

  ///default
  LinkedList();
  ///copy
  LinkedList(const LinkedList &l);
  ///custom (n num of elements)
  LinkedList(int numOfElements);

  //destructor
  ~LinkedList();

  void createLinkedList(int numOfElements);
};

#endif /* INCLUDED_LINKED_LIST_H_ */