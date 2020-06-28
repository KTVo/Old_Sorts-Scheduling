// CircularQueue.h
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <typename T>
class Queue 
{
public:
  // Constructor
  Queue(int capacity = 20)
  {
  	this->capacity = capacity;
  	theArray = new T[capacity];
  	front = 0;
  	back = 0;
  }
  
  //Desctructor
  ~Queue()
  {
  	delete [] theArray;
  }  

  // Makes the queue to the empty state.  
  void make_empty()
  {
  	front = 0;
  	back = 0;
  }
  
  // Checks if the queue is empty.  
  bool empty() const
  {
  	return (front == back);
  }

  // Checks if the queue is full.  
  bool full() const
  {
  	return (((back + 1) % capacity) == front);
  }
  
  // Inserts item at the end of the queue.
  void enqueue(const T& item)
  {
  	if(!full())
  	{
  	  	back = (back + 1) % capacity;
  	  	theArray[back] = item;	
  	}
  }

  // Removes the element at the start of the queue.
  void dequeue()
  {
  	if(!empty())
  	{
  	  	front = (front + 1) % capacity;
  	}
  }
	
	// returns the front element
  const T& front_element() const
  {
  	return theArray[(front + 1) % capacity];
  }
  
  // Prints the elements of the queue.
  void print() const
  {
  	int i = (front + 1) % capacity;
  	while (i <= back)
  	{
  	  	cout << theArray[i] << ",";
  	  	i = (i + 1) % capacity;
  	}
  	cout << endl;
  }  
  
  void myprint() const
  {
      cout<<endl<<endl<<"My Print: ";
      for(int i = 0; i < capacity; i++)
        cout<<theArray[i]<<"  ";
      cout<<endl<<endl;
  }
  
private:
 
  	T* theArray;
  	int capacity;
  	int front;
  	int back;
};

#endif