/*
 * Name: Kevin Vo
 * ID: 006316930
 * Professor: Dr. Yan Zhang
 * Assignment: Assignment#3 - Problem 4
 * Purpose: This program will construct the given binary tree as it prints the
 *          binary tree in preorder, inorder, and level-order traversal 
 *          non-recursively with the use for stacks with pre- and in- while
 *          level-order uses a queue.
 * Date: 5/19/19
*/

// Queue.h
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <typename T>
class Queue 
{
public:
  // Constructor
  Queue()
  {
	  front = nullptr;
	  back = nullptr;
  }
  
  //Destructor
  ~Queue()
  {
	  make_empty();
  }  

  // Makes the queue to the empty state.  
  void make_empty()
  {
	  while (!empty())
	  {
		  dequeue();
	  }
  }
  
  // Checks if the queue is empty.  
  bool empty() const
  {
	  return (front == nullptr && back == nullptr);
  }
  
  // Inserts item at the end of the queue.
  void enqueue(const T& item)
  {
	  NodeType* new_node = new NodeType(item);
	  
	  if (empty())
	  {
	  	// add the first element 
	  	front = new_node;
	  	back = new_node;
	  }
	  else
	  {
	  	back->next = new_node;
	  	back = new_node;
	  }
  }

  // Removes the element at the start of the queue.
  void dequeue()
  {
	  if (!empty())
	  {
	  	NodeType* ptr = front;
	  	front = front->next;
	  	delete ptr;	
	  	// dequeue the last element
	  	if (front == nullptr)
	  		back = nullptr;
	  }
  }
	
	// returns the front element
  const T& front_element() const
  {
	  return front->data; 
  }
  
  // Prints the elements of the queue.
  void print() const
  {
	  NodeType* ptr = front;
	  while (ptr != nullptr)
	  {
		  cout << ptr->data << ", ";
		  ptr = ptr->next;
	  }
	  cout << endl;
  }  
  
private:
  struct NodeType
  {
        T data;
        NodeType* next;
	  
        NodeType(const T & d = T()): data(d)
        {
        	next = nullptr;
        }	  
  };
  
  NodeType* front;
  NodeType* back;
};

#endif