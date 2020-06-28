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

// Stack.h
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <typename T>
class Stack 
{
public:
  // Constructor
  Stack()
  {
	topOfStack = nullptr;  
  }
  
  //Destructor
  ~Stack()
  {
	make_empty();
  }

  // Makes the stack to the empty state.  
  void make_empty()
  {
	  while (!empty())
	  {
		  pop();
	  }
  }
  
  // Checks if the stack is empty.  
  bool empty() const
  {
	  return (topOfStack == nullptr);
  }
  
  // Insert item in the stack.
  void push(const T& item)
  {
	  NodeType* newNode = new NodeType(item);
	  newNode->next = topOfStack;
	  topOfStack = newNode;
  }

  // Return the top element.
  const T& top() const
  {
	 return  topOfStack->data; 
  }
  
  // Removes the element front the front.
  void pop()
  {
	  if (!empty())
	  {
	  	NodeType* ptr = topOfStack;
	  	topOfStack = topOfStack->next;
	  	delete ptr;
	  }
  }

  void print() const
  {
	  NodeType* ptr = topOfStack;
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
  
  NodeType* topOfStack;
};

#endif